/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:46:07 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 21:43:10 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_info(t_info *info, char *od)
{
	int fd[2];

	pipe(fd);
	info->order = NULL;
	ft_salloc((void **)&info->opt, sizeof(char *), 1);
	(info->opt)[0] = NULL;
	info->fd_stdin = -2;
	if (info->is_redirect == 1)
		info->fd_stdin = dup(info->fd_stdout_r);
	info->fd_stdout = fd[1];
	info->fd_stdout_r = fd[0];
	info->is_append = 0;
	info->is_redirect = 0;
	info->is_print = 0;
	if (od == NULL || (od != NULL && *od == ';'))
		info->is_print = 1;
	if (od != NULL && *od == '|')
		info->is_redirect = 1;
	return (1);
}

void	free_info(t_info *info)
{
	int	idx;

	if (info->fd_stdin > 2)
		close(info->fd_stdin);
	if (info->fd_stdout > 2)
		close(info->fd_stdout);
	if (info->fd_stdout_r > 2)
		close(info->fd_stdout_r);
	if (info->order != NULL)
		free(info->order);
	idx = 0;
	if (info->opt != NULL)
	{
		while ((info->opt)[idx] != 0)
			free((info->opt)[idx++]);
		free(info->opt);
	}
}

void	set_stdout_info(t_info *info, char *path)
{
	if (info->fd_stdout > 2)
		close(info->fd_stdout);
	if (info->fd_stdout_r != -2)
	{
		close(info->fd_stdout_r);
		info->fd_stdout_r = -2;
	}
	info->fd_stdout = open(path, O_WRONLY | O_CREAT, 0644);
	info->is_print = 0;
	info->is_redirect = 1;
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
	int		is_order;

	idx = -1;
	is_order = 0;
	while (ret[++idx] != 0)
	{
		if (ft_strcmp(ret[idx], ">") == 0)
			set_stdout_info(info, ret[++idx]);
		else if (ft_strcmp(ret[idx], "<") == 0)
			set_stdin_info(info, ret[++idx]);
		else if (ft_strcmp(ret[idx], ">>") == 0)
		{
			set_stdout_info(info, ret[++idx]);
			info->is_append = 1;
		}
		else
		{
			if (is_order == 0)
			{
				is_order = 1;
				info->order = ft_strdup(ret[idx]);
			}
			else
				result = ft_string_append(&(info->opt), ret[idx]);
		}
		if (info->fd_stdout == -1 || info->fd_stdin == -1 || result == 1)
			return (ft_split_free2(ret));
	}
	ft_split_free2(ret);
	return (0);
}
