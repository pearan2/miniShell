/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:04:56 by honlee            #+#    #+#             */
/*   Updated: 2021/04/01 11:05:12 by honlee           ###   ########.fr       */
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
		ft_salloc((void **)&ret, 1, e - s + 2);
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
	ft_salloc((void **)&temp, 1, e - s + 2);
	while (s + ++idx <= e)
		temp[idx] = line[s + idx];
	temp[idx] = 0;
	ft_string_append(tg, temp);
	free(temp);
}

char	**ft_split_input2(char *line)
{
	char	*temp;
	int		idx;
	char	f_va;
	char	**ret;

	ft_split_input2_init_all(&temp, &idx, &f_va, &ret);
	while (line[++idx] != 0)
	{
		if (line[idx] == ' ' || line[idx] == '>' || line[idx] == '<')
		{
			if (f_va == 0)
			{
				if (ft_split_input2_f_va_zero(&ret, &temp, &idx, line) != 0)
					return (NULL);
			}
			else
				ft_charappend2(&temp, line[idx]);
		}
		else
			ft_split_input2_proc_quotes(line, &temp, idx, &f_va);
	}
	if (ft_strlen(temp) > 0)
		ft_string_append(&ret, temp);
	ft_free2(line, temp);
	return (ret);
}
