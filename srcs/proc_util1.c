/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:13:03 by honlee            #+#    #+#             */
/*   Updated: 2021/03/30 10:09:04 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	proc_print(t_info *info)
{
	char buff;

	while (read(info->fd_stdout_r, &buff, 1) > 0)
		write(1, &buff, 1);
	close(info->fd_stdout_r);
}

int	proc_inner(t_info *info, char *path)
{
	int pid;
	int status;

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
		if (status != 0 && status != 2)
			ft_puterror(path, status / 255);
		close(info->fd_stdout);
		close(info->fd_stdin);
		if (info->is_print == 1)
			close(info->fd_stdout_r);
		free(path);
		return (status);
	}
}