/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:12:00 by junhypar          #+#    #+#             */
/*   Updated: 2021/04/01 10:24:42 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	rebase_input_echo(t_info *info, int i)
{
	char	*temp;
	int		j;
	int		flag;

	flag = 0;
	j = 0;
	while (info->opt[i][j])
	{
		if (info->opt[i][j] == '=')
		{
			flag = 1;
			break ;
		}
		j++;
	}
	if (flag)
		rebase_input(info, i);
	else
	{
		temp = info->opt[i];
		info->opt[i] = change_input_to_env(info, temp);
		free(temp);
	}
}

static void	check_env(t_info *info, int i)
{
	int		j;

	j = 0;
	while (info->opt[i][j])
	{
		if (info->opt[i][j] == '$')
		{
			rebase_input_echo(info, i);
			break ;
		}
		j++;
	}
}

static int	check_flag(t_info *info, int i, int *out)
{
	int		j;

	if (info->opt[i][0] == '-')
	{
		j = 0;
		while (info->opt[i][++j])
		{
			if (info->opt[i][j] != 'n')
			{
				return (0);
				break ;
			}
		}
		if (info->opt[i][j] == 0)
			*out = 1;
	}
	else
		return (0);
	return (1);
}

static void	ft_print_echo(t_info *info, int i)
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

void	ft_echo(t_info *info, int fd[2])
{
	int		i;
	int		flag;
	int		flag2;
	int		tag;

	tag = 0;
	if (info->opt[1] == 0)
		no_component_echo(fd);
	i = 0;
	while (info->opt[++i])
	{
		flag = check_single_quote(info, i);
		flag2 = check_flag(info, i, &tag);
		if (scan_single_doller(info, i))
			print_single_doller(info, i);
		else
		{
			if (!flag)
				check_env(info, i);
			if (!flag2)
				ft_print_echo(info, i);
		}
	}
	ft_echo_finish(info, fd, tag);
}
