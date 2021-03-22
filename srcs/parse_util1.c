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

int	init_info(t_info *info, char **env)
{
	if (env != NULL)
		info->env = env;
	info->order = NULL;
	if (ft_salloc((void **)&info->opt, sizeof(char *), 1))
		return (0);
	(info->opt)[0] = 0;
	info->fd_stdin = -2;
	info->fd_stdout = -2;
	info->is_append = -2;
	return (1);
}

int	make_info(t_info *info, char **ret)
{
	int		idx;
	int		result;

	idx = -1;
	while (ret[++idx] != 0)
	{
		if (ft_strcmp(ret[idx], ">") == 0)
			info->fd_stdout = open(ret[++idx], O_WRONLY | O_CREAT, 0644);
		else if (ft_strcmp(ret[idx], "<") == 0)
			info->fd_stdin = open(ret[++idx], O_RDONLY);
		else if (ft_strcmp(ret[idx], ">>") == 0)
		{
			info->fd_stdout = open(ret[++idx], O_WRONLY);
			info->is_append = 1;
		}
		else
			result = ft_string_append(&(info->opt), ret[idx]);
		if (info->fd_stdout == -1 || info->fd_stdin == -1 || result == 0)
			return (return_with_free(info, errno, ret));
	}
	info->order = info->opt[0];
	(info->opt)++;
	ft_split_free2(ret);
	return (0);
}
