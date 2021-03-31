/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:13:03 by honlee            #+#    #+#             */
/*   Updated: 2021/03/31 02:40:24 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		waitpid(pid, &status, 0);
		info->built_result_num = 0;
		if (status != 0 && status != 2)
		{
			ft_puterror(path, status / 255);
			info->built_result_num = status / 255;
		}
		free(path);
		return (status);
	}
}
