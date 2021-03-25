/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:21:50 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/25 11:48:25 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minihell.h"

static int		ft_atoi(char *a)
{
}

static int		exit_support(t_info *info, int cnt)
{
	int			i;

	i = 0;
	while (info->[1][i])
	{
		if (info->[1][i] < '0' && info->[1][i] > '9')
			return (2) //exit 뒤에는 숫자요소 1개만 와야되는데 문자요소가옴
		i++;
	}
}

static void		exit_result(t_info *info, int flag)
{
	if (flag == 0)
	{
		write(1, "exit\n", 5);
		exit(0);
	}
	else if (flag == 2)
	{

	}
}

void			ft_exit(t_info *info)
{
	int			i;
	int			flag;

	i = 0;
	while (info->opt[i])
		i++;
	if (i == 1)
		exit_result(info, 0);
	else
		flag = exit_support(info, i);
}
