/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:34:36 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/25 10:43:47 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static int	find_pwd(char *str)
{
	if (str[0] == 'P' && str[1] == 'W' && str[2] == 'D' && str[3] == '=')
		return (1);
	return (-1);
}

void		ft_pwd(t_info *info)
{
	int		i;
	int		flag;
	int		len;
	
	i = 0;
	len = 0;
	flag = -1;
	while(info->env[i])
	{
		flag = find_pwd(info->env[i]);
		if (flag == 1)
		{
			write(1, "\nget in\n", 8);
			len = ft_strlen(info->env[i]);
			write(info->fd_stdout, info->env[i] + 4, len - 4);
			write(info->fd_stdout, "\n", 1);
			break;
		}
		i++;
	}
}
