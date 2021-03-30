/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:37:03 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/30 16:47:14 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void write_export(t_info *info, int fd[2])
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
			write(info->fd_stdout, "declare -x ", 11);
			write(info->fd_stdout, info->env[i], len);
			write(info->fd_stdout, "\n", 1);
		}
		else
		{
			write(1, "declare -x ", 11);
			write(1, info->env[i], len);
			write(1, "\n", 1);
		}
		i++;
	}
	write(fd[1], "0\n", 2);
	exit(0);
}

void		ft_export(t_info *info, int fd[2])
{
	if (info->opt[1] == 0)
		write_export(info, fd);
}
