/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:21:50 by junhypar          #+#    #+#             */
/*   Updated: 2021/04/01 10:01:24 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exit_support(t_info *info, int cnt)
{
	int			i;

	i = 0;
	while (info->opt[1][i])
	{
		if (info->opt[1][i] < '0' || info->opt[1][i] > '9')
			return (2);
		i++;
	}
	if (cnt > 2)
		return (3);
	return (1);
}

static void	exit_result_support(t_info *info, int flag)
{
	if (info->is_print == 1)
	{
		if (flag == 0)
			write(1, "exit\n", 5);
		else if (flag == 2)
		{
			write(1, "exit\n", 5);
			write(2, "minishell: exit: ", 12);
			write(2, info->opt[1], ft_strlen(info->opt[1]));
			write(2, ": numeric argument required\n", 28);
		}
		else if (flag == 3)
		{
			write(1, "exit\n", 5);
			write(2, "minishell: exit: too many arguments\n", 31);
		}
		else
			write(1, "exit\n", 5);
	}
}

static void	exit_result(t_info *info, int flag, int fd[2])
{
	if (flag == 0)
	{
		exit_result_support(info, flag);
		write(fd[1], "0\n", 2);
		exit(20);
	}
	else if (flag == 2)
	{
		exit_result_support(info, flag);
		write(fd[1], "255\n", 4);
		exit(20);
	}
	else if (flag == 3)
	{
		exit_result_support(info, flag);
		write(fd[1], "1\n", 2);
		exit(1);
	}
	else
	{
		exit_result_support(info, flag);
		write(fd[1], info->opt[1], ft_strlen(info->opt[1]));
		write(fd[1], "\n", 1);
		exit(20);
	}
}

void	ft_exit(t_info *info, int fd[2])
{
	int			i;
	int			flag;

	i = 0;
	flag = 0;
	while (info->opt[i])
		i++;
	if (i == 1)
		exit_result(info, flag, fd);
	else
		flag = exit_support(info, i);
	exit_result(info, flag, fd);
}
