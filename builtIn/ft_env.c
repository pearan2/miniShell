/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:43:48 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/30 16:33:46 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_env(t_info *info, int fd[2])
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while(info->env[i])
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
		i++;
	}
	write(fd[1], "0\n", 2);
	exit(0);
}
