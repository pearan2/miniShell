/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:39:16 by honlee            #+#    #+#             */
/*   Updated: 2021/03/30 13:17:08 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void static	init_int(int *s_flag, int *d_flag, int *idx)
{
	*s_flag = 0;
	*d_flag = 0;
	*idx = -1;
}

int	check_quotes(char *line)
{
	int	s_flag;
	int	d_flag;
	int	idx;

	init_int(&s_flag, &d_flag, &idx);
	while (line[++idx] != 0)
	{
		if (line[idx] == '\'' && d_flag == 0)
		{
			if (s_flag == 0)
				s_flag = 1;
			else
				s_flag = 0;
		}
		else if (line[idx] == '\"' && s_flag == 0)
		{
			if (d_flag == 0)
				d_flag = 1;
			else
				d_flag = 0;
		}
	}
	if (d_flag == 1 || s_flag == 1)
		return (1);
	return (0);
}
