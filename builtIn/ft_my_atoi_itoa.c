/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_atoi_itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:11:30 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 23:27:38 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long	my_atoi(char *str)
{
	int		i;
	long	out;
	int		mine;

	out = 0;
	i = 0;
	if (str[i] == '-')
	{
		i = 1;
		mine = 1;
	}
	while (str[i])
	{
		out *= 10;
		out += (str[i] - '0');
		i++;
	}
	if (mine == 1)
		out *= -1;
	return (out);
}

static void	support_itoa(long *num, int *mine, int *len)
{
	int		num2;

	num2 = *num;
	if (*num < 0)
	{
		(*num) *= -1;
		*mine = 1;
		*len += 1;
	}
	while (num2)
	{
		*len += 1;
		num2 /= 10;
	}
}

char	*my_itoa(long num)
{
	int		len;
	int		mine;
	char	*out;
	int		i;

	if (num == 0)
		return (ft_strdup("0"));
	len = 0;
	mine = 0;
	support_itoa(&num, &mine, &len);
	ft_salloc((void *)&out, sizeof(char), len + 1);
	i = len;
	out[i] = '\0';
	while (i--)
	{
		if (mine == 1 && i == 0)
			out[i] = '-';
		else
			out[i] = num % 10 + '0';
		num /= 10;
	}
	return (out);
}
