/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:12:00 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 11:42:43 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	rebase_input(t_info *info, int i)
{
	char	*temp;

	temp = info->opt[i];
	info->opt[i] = change_input_to_env(info, temp);
	free(temp);
}

static void	check_env(t_info *info, int i)
{
	int		j;

	j = 0;
	while(info->opt[i][j])
	{
		if (info->opt[i][j] == '$')
		{
			rebase_input(info, i);
			break;
		}
		j++;
	}
}

static void	check_flag(t_info *info, int fd[2], int *i, int *out)
{
	int		j;

	while (info->opt[*i])
	{
		if (info->opt[*i][0] == '-')
		{
			j = 0;
			while (info->opt[*i][++j])
			{
				if (info->opt[*i][j] != 'n')
					break;
			}
			if (info->opt[*i][j] != 0)
				break;
			*out = 1;
		}
		else
			break;
		*i += 1;
	}
}

static void ft_print_echo(t_info *info, int i, int fd[2], int flag)
{
	while (info->opt[i])
	{
		if (info->is_print == 0)
			write(info->fd_stdout, info->opt[i], ft_strlen(info->opt[i]));
		else
			write(1, info->opt[i], ft_strlen(info->opt[i]));
		i++;
		if (info->opt[i])
		{
			if (info->is_print == 0)
				write(info->fd_stdout, " ", 1);
			else
				write(1, " ", 1);
		}
	}
	if (!flag)
	{
		if (info->is_print == 0)
			write(info->fd_stdout, "\n", 1);
		else
			write(1, "\n", 1);
	}
}


void		ft_echo(t_info *info, int fd[2])
{
	int		i;
	int		j;
	int		flag;
	int		tag;

	tag = 0;
	if (info->opt[1] == 0)
	{
		write(1, "\n", 1);
		write(fd[1], "0\n", 2);
		exit(0);
	}
	i = 1;
	flag = 0;
	check_flag(info, fd, &i, &flag);
	j = i - 1;
	while (info->opt[++j])
		check_env(info, j);
	ft_print_echo(info, i, fd, flag);
	write(fd[1], "0\n", 2);
	exit(0);
}
