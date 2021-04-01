/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:13:03 by honlee            #+#    #+#             */
/*   Updated: 2021/04/01 10:35:56 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	proc_handle_error(t_info *info, char *path, int en)
{
	ft_puterror(path, en);
	info->built_result_num = en;
	return (0);
}

int	proc_inner(t_info *info, char *path)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		if (info->is_print == 0)
			dup2(info->fd_stdout, 1);
		dup2(info->fd_stdin, 0);
		if (execve(path, info->opt, info->env) == -1)
			exit(errno);
		return (0);
	}
	else
	{
		g_data.is_fork = 1;
		waitpid(pid, &status, 0);
		g_data.is_fork = 0;
		info->built_result_num = 0;
		if (status / 256 != 0)
			proc_handle_error(info, path, status / 256);
		free(path);
		return (status);
	}
}
