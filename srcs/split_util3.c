/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:04:56 by honlee            #+#    #+#             */
/*   Updated: 2021/03/24 17:50:19 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_string_trim_free(char **line)
{
	int		s;
	int		e;
	char	*ret;
	int		idx;

	e = ft_strlen(*line) - 1;
	s = 0;
	while ((*line)[s] == ' ')
		s++;
	while ((*line)[e] == ' ' && e >= 0)
		e--;
	if (e < 0)
		ret = ft_strdup("");
	else
	{
		ft_salloc((void**)&ret, 1, e - s + 2);
		idx = -1;
		while (s + ++idx <= e)
			ret[idx] = (*line)[s + idx];
		ret[idx] = 0;
	}
	free(*line);
	*line = ret;
	return (ret);
}

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

	ret = NULL;
	ft_salloc((void**)&ret, sizeof(char *), 1);
	ret[0] = NULL;
	s = 0;
	e = 0;
	f_value = ' ';
	while (1)
	{
		if (line[e] == f_value || line[e] == 0)
		{
			ft_string_append_se(&ret, line, s, e);
			if (line[e] == 0)
				break ;
			s = e + 1;
			if (line[s] == 0)
				break ;
			while (line[s] == ' ')
				s++;
			f_value = line[s];
			if (!(f_value == '\'' || f_value == '\"'))
				f_value = ' ';
			e = s;
		}
		e++;
	}
	return (ret);
}
