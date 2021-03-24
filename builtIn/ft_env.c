/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:43:48 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/24 16:54:49 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_env(t_info *info)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while(info->env[i])
	{
		len = ft_strlen(info->env[i]);
		write(info->fd_stdout, info->env[i], len);
		write(info->fd_stdout, "\n", 1);	
		i++;
	}
}
