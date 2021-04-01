/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:46:07 by honlee            #+#    #+#             */
/*   Updated: 2021/04/01 10:44:43 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_info(t_info *info, char *od)
{
	int	fd[2];

	pipe(fd);
	ft_salloc((void **)&info->opt, sizeof(char *), 1);
	(info->opt)[0] = NULL;
	if (info->fd_stdin < 2 || info->built_result_num != 0)
		info->fd_stdin = -2;
	info->fd_stdout = fd[1];
	info->fd_stdout_r = fd[0];
	info->is_print = 0;
	if (od == NULL || (od != NULL && *od == ';'))
		info->is_print = 1;
	return (1);
}

void	free_info(t_info *info)
{
	int	idx;

	info->is_print = 0;
	if (info->fd_stdin > 2)
		close(info->fd_stdin);
	if (info->fd_stdout > 2)
		close(info->fd_stdout);
	if (info->fd_stdout_r > 2 && info->is_print == 0)
		info->fd_stdin = dup(info->fd_stdout_r);
	else
		close(info->fd_stdout_r);
	idx = 0;
	if (info->opt != NULL)
	{
		while ((info->opt)[idx] != 0)
			free((info->opt)[idx++]);
		free(info->opt);
	}
}

void	set_stdout_info(t_info *info, char *path, int is_append)
{
	if (info->fd_stdout > 2)
		close(info->fd_stdout);
	if (info->fd_stdout_r != -2)
	{
		close(info->fd_stdout_r);
		info->fd_stdout_r = -2;
	}
	if (is_append == 0)
		info->fd_stdout = open(path, O_WRONLY | O_CREAT, 0644);
	else
		info->fd_stdout = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	info->is_print = 0;
}

void	set_stdin_info(t_info *info, char *path)
{
	if (info->fd_stdin > 2)
		close(info->fd_stdin);
	info->fd_stdin = open(path, O_RDONLY);
}

int	make_info(t_info *info, char **ret)
{
	int		idx;
	int		result;

	idx = -1;
	result = 0;
	if (ret == 0)
		return (ft_puterror_return("minishell", "parser error"));
	while (ret[++idx] != 0)
	{
		if (ft_strcmp(ret[idx], ">") == 0)
			set_stdout_info(info, str_trim_free(&ret[++idx]), 0);
		else if (ft_strcmp(ret[idx], "<") == 0)
			set_stdin_info(info, str_trim_free(&ret[++idx]));
		else if (ft_strcmp(ret[idx], ">>") == 0)
			set_stdout_info(info, str_trim_free(&ret[++idx]), 1);
		else
			result = ft_string_append(&(info->opt), ret[idx]);
		if (info->fd_stdout == -1 || info->fd_stdin == -1 || result == 1)
			return (ft_split_free2(ret));
	}
	ft_info_trim(info);
	ft_split_free2(ret);
	return (0);
}
