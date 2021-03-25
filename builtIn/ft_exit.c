/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:21:50 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/25 15:28:44 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		exit_support(t_info *info, int cnt)
{
	int			i;

	i = 0;
	while (info->opt[1][i])
	{
		if (info->opt[1][i] < '0' && info->opt[1][i] > '9')
			return (2); //exit 뒤에는 숫자요소 1개만 와야되는데 문자요소가옴
		i++;
	}
	if (i > 2)
		return (3); //요소가 많다
	return (1); //정상
}

static void		exit_result(t_info *info, int flag, int fd[2])
{
	if (flag == 0)
	{
		write(1, "exit\n", 5);
		write(fd[1], "0\n", 2);
		exit(20);
	}
	else if (flag == 2)
	{
		write(1, "bash: exit: aa: numeric argument required\n", 42);
		write(fd[1], "255\n", 4);
		exit(20);
	}
	else if (flag == 3)
	{
		write(1, "bash: exit: too many arguments\n", 31);
		write(fd[1], "1\n", 2);
		exit(1);
	}
	else
	{
		write(1, "exit\n", 5);
		write(fd[1], info->opt[1], ft_strlen(info->opt[1]));
		write(fd[1], "\n", 1);
		exit(20);
	}
}

void			ft_exit(t_info *info, int fd[2])
{
	int			i;
	int			flag;

	i = 0;
	while (info->opt[i])
		i++;
	if (i == 1)
		exit_result(info, 0, fd);
	else
		flag = exit_support(info, i);
	exit_result(info, flag, fd);
}
