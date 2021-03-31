/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:43:48 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 23:24:01 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_available(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_env(t_info *info, int fd[2])
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (info->env[i])
	{
		if (is_available(info->env[i]))
		{
			len = ft_strlen(info->env[i]);
			if (info->is_print == 0)
			{
				write(info->fd_stdout, info->env[i], len);
				write(info->fd_stdout, "\n", 1);
			}
			else
			{
				write(1, info->env[i], len);
				write(1, "\n", 1);
			}
		}
		i++;
	}
	write(fd[1], "0\n", 2);
	exit(0);
}
