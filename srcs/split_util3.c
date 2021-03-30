/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:04:56 by honlee            #+#    #+#             */
/*   Updated: 2021/03/30 10:37:49 by honlee           ###   ########seoul.kr  */
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

char	**ft_split_input2(char *line)
{
	char	*temp;
	int		idx;
	int		flag;
	char	f_va;
	char	**ret;
	char	*save;
	char	sep;

	save = line;
	temp = ft_strdup("");
	idx = -1;
	flag = 0;
	f_va = 0;
	ret = NULL;
	ft_salloc((void**)&ret, sizeof(char *), 1);
	ret[0] = NULL;
	while (line[++idx] != 0)
	{
		if (line[idx] == ' ' || line[idx] == '>' || line[idx] == '<') // 분리해야하는가?
		{
			sep = line[idx];
			if (flag == 0) // 따옴표가 세팅되어 있지 않다.
			{
				if (ft_strlen(temp) > 0)
				{
					ft_string_append(&ret, temp); // 리턴에 넣어줌.
					free(temp);
					temp = ft_strdup("");
				}
				line += idx; // line[idx] 가 가르키던 방향
				if (sep == ' ')
				{
					while (*line == ' ') // 공백이 아닌게 올때까지 밀어준다.
						line++;
				}
				else
				{
					while (*line == sep) // > 면 > 가 나오는동안, <면 <가나오는동안
					{
						ft_charappend2(&temp, *line); // 계속어펜드
						line++;
					}
					if (ft_strlen(temp) > 2 || (ft_strlen(temp) == 2 && temp[0] == '<'))
					{
						free(temp);
						free(save);
						ft_split_free2(ret);
						return (NULL);						
					}
					// 다른게 나왔다면 끊어준다.
					ft_string_append(&ret, temp);
					free(temp);
					temp = ft_strdup("");
				}
				idx = -1; // 인덱스 초기화
			}
			else // 따옴표를 찾는중이다.
				ft_charappend2(&temp, line[idx]);// 집어넣는다.
		}
		else
		{
			ft_charappend2(&temp, line[idx]); // 일단 집어넣는다.
			if (line[idx] == '\'' || line[idx] == '\"')
			{
				if (flag == 0)
				{
					flag = 1;
					f_va = line[idx];
				}
				else // flag == 1
				{
					if (f_va == line[idx])
					{
						flag = 0;
						f_va = 0;
					}
				}
			}
		}
	}
	if (ft_strlen(temp) > 0)
		ft_string_append(&ret, temp);
	free(temp);
	free(save);
	return (ret);
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
