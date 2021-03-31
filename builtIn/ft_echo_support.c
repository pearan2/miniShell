/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_support.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:32:00 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 15:43:41 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		no_component_echo(int fd[2])
{
	write(1, "\n", 1);
	write(fd[1], "0\n", 2);
	exit(0);
}

int			check_single_quote(t_info *info, int i)
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
