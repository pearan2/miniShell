/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:33:21 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/25 13:53:24 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_order(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (1);
	else if (ft_strcmp(str, "cd") == 0)
		return (2);
	else if (ft_strcmp(str, "pwd") == 0)
		return (3);
	else if (ft_strcmp(str, "export") == 0)
		return (4);
	else if (ft_strcmp(str, "unset") == 0)
		return (5);
	else if (ft_strcmp(str, "env") == 0)
		return (6);
	else if (ft_strcmp(str, "exit") == 0)
		return (7);
	else
		return (-1);
}

static void	do_child(t_info *info, int order)
{
	if (order == 3)
		ft_pwd(info);
	else if (order == 6)
		ft_env(info);
	else if (order == 8)
		ft_exit(info);
}

int			*ft_built_in(t_info *info)
{
	int		order;
	pid_t	pid;
	pid_t	pwait;
	int		fd[2];
	int		status;

	order = check_order(info->opt[0]);
	pid = fork();
	if (pid > 0)
	{
		pwait = wait(&status);

	}
	else if (pid == 0)
		do_child;
	else
		return (1);
	return(0);
}
