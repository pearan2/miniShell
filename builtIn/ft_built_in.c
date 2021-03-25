/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:33:21 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/25 15:30:05 by junhypar         ###   ########.fr       */
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

static void	do_child(t_info *info, int order, int fd[2])
{
	if (order == 3)
		ft_pwd(info, fd);
	else if (order == 6)
		ft_env(info, fd);
	else if (order == 7)
		ft_exit(info, fd);
}

static void	do_parent(t_info *info, int status, int fd[2])
{
	char	*result;
	long	stat;
	int		gnl;

	char	buf[10];
	int len;

	if (status == 20)
	{
		gnl = get_next_line(fd[0], &result);
		stat = my_atoi(result);
		stat = stat % 256;
		free(result);
		exit((int)stat);
	}
	else
	{
		gnl = get_next_line(fd[0], &result);
		info->built_result_num = my_atoi(result) % 256;
		free(result);
	}
}

int			*ft_built_in(t_info *info)
{
	int		order;
	pid_t	pid;
	pid_t	pwait;
	int		fd[2]; //0은 무조건 읽기전용 1은 무조건 쓰기전용
	int		status;

	order = check_order(info->opt[0]);
	if (pipe(fd) == -1)
	{
		write(2, "pipe error\n", 11);
		exit(1);
	}
	pid = fork();
	if (pid > 0)
	{
		pwait = wait(&status);
		do_parent(info, status / 256, fd);
	}
	else if (pid == 0)
		do_child(info, order, fd);
	else
	{
		write(2, "fork error\n", 11);
		exit(1);
	}
	return(0);
}
