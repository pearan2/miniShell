/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_support.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:32:00 by junhypar          #+#    #+#             */
/*   Updated: 2021/04/01 11:06:42 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_single_doller(t_info *info, int i)
{
	if (info->is_print == 0)
		write(info->fd_stdout, "$", 1);
	else
		write(1, "$", 1);
	i++;
	if (info->opt[i])
	{
		if (info->is_print == 0)
			write(info->fd_stdout, " ", 1);
		else
			write(1, " ", 1);
	}	
}

int	scan_single_doller(t_info *info, int i)
{
	if (info->opt[i][0] == '$')
	{
		if (info->opt[i][1] == '\0')
			return (1);
	}
	return (0);
}

void	ft_echo_finish(t_info *info, int fd[2], int tag)
{
	if (!tag)
	{
		if (info->is_print == 0)
			write(info->fd_stdout, "\n", 1);
		else
			write(1, "\n", 1);
	}
	write(fd[1], "0\n", 2);
	exit(0);
}

void	no_component_echo(int fd[2])
{
	write(1, "\n", 1);
	write(fd[1], "0\n", 2);
	exit(0);
}

int	check_single_quote(t_info *info, int i)
{
	int		j;

	j = 0;
	while (info->opt[i][j])
	{
		if (info->opt[i][j] == '\'')
		{
			info->opt[i] = str_trim_free(&(info->opt[i]));
			return (1);
		}
		else if (info->opt[i][j] == '\"')
		{
			info->opt[i] = str_trim_free(&(info->opt[i]));
			return (0);
		}
		j++;
	}
	return (0);
}
