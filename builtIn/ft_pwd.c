/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:34:36 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 23:28:05 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_pwd(char *str)
{
	if (str[0] == 'P' && str[1] == 'W' && str[2] == 'D' && str[3] == '=')
		return (1);
	return (-1);
}

static void	ft_pwd_support(t_info *info, char *env, int len, int flag)
{
	if (flag == 1)
	{
		write(info->fd_stdout, env + 4, len - 4);
		write(info->fd_stdout, "\n", 1);
	}
	else
	{
		write(1, env + 4, len - 4);
		write(1, "\n", 1);
	}
}

void	ft_pwd(t_info *info, int fd[2])
{
	int		i;
	int		flag;
	int		len;

	i = 0;
	while (info->env[i])
	{
		flag = find_pwd(info->env[i]);
		if (flag == 1)
		{
			len = ft_strlen(info->env[i]);
			if (info->is_print == 0)
				ft_pwd_support(info, info->env[i], len, 1);
			else
				ft_pwd_support(info, info->env[i], len, 2);
			break ;
		}
		i++;
	}
	write(fd[1], "0\n", 2);
	exit(0);
}
