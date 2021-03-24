/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:04:56 by honlee            #+#    #+#             */
/*   Updated: 2021/03/24 13:27:52 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_string_append_se(char ***tg, char *line, int s, int e)
{
	char	*temp;
	int		idx;

	temp = NULL;
	idx = -1;
	if (line[e] == ' ' || line[e] == 0)
		e--;
	ft_salloc((void**)&temp, 1, e - s + 2);
	while (s + ++idx <= e)
		temp[idx] = line[s + idx];
	temp[idx] = 0;
	ft_string_append(tg, temp);
	free(temp);
}

char	**ft_split_input(char *line)
{
	char	**ret;
	int		s;
	int		e;
	char	f_value;
	int		is_first;

	ret = NULL;
	ft_salloc((void**)&ret, sizeof(char *), 1);
	ret[0] = NULL;
	s = 0;
	e = 0;
	f_value = ' ';
	is_first = 0;
	while (line[++e] != 0)
	{
		if (line[e] == f_value)
		{
			ft_string_append_se(&ret, line, s, e);
			is_first = 1;
			s = e + 1;
			if (line[s] == 0)
				break ;
			while (line[s] == ' ')
				s++;
			f_value = line[s];
			if (!(f_value == '\'' || f_value == '\"'))
				f_value = ' ';
			e = s + 1;
		}
	}
	if (is_first == 0)
		ft_string_append_se(&ret, line, s, e);
	return (ret);
}