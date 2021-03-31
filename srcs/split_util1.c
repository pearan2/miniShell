/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 03:13:25 by honlee            #+#    #+#             */
/*   Updated: 2021/03/31 20:52:02 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	ft_get_cnt(char *str, char *charset)
{
	unsigned int	idx;
	unsigned int	ret;

	idx = 0;
	ret = 0;
	while (1)
	{
		idx = ft_next(str, charset, idx, 0);
		if (str[idx] != '\0')
			ret++;
		else
			return (ret);
		idx = ft_next(str, charset, idx, 1);
		if (str[idx] == '\0')
			return (ret);
	}
}

int	ft_is_sep(char c, char *charset)
{
	int				idx;

	idx = 0;
	if (c == '\0')
		return (-1);
	while (charset[idx] != '\0')
	{
		if (c == charset[idx])
			return (1);
		idx++;
	}
	return (0);
}

void	ft_sc(char *dest, char *src, unsigned int s, unsigned int e)
{
	unsigned int	idx;

	idx = 0;
	while (s + idx < e)
	{
		dest[idx] = src[s + idx];
		idx++;
	}
	dest[idx] = '\0';
}

unsigned int	ft_next(char *str, char *charset, unsigned int s, int is_sep)
{
	if (is_sep == 1)
	{
		while (ft_is_sep(str[s], charset) == 0)
			s++;
		return (s);
	}
	else
	{
		while (ft_is_sep(str[s], charset) == 1)
			s++;
		return (s);
	}
}

char	**ft_split(char *str, char *charset)
{
	char			**ret;
	unsigned int	cnt;
	unsigned int	idx;
	unsigned int	s;
	unsigned int	e;

	ret = NULL;
	cnt = ft_get_cnt(str, charset);
	ft_salloc((void **)&ret, sizeof(char *), cnt + 1);
	ret[cnt] = 0;
	idx = 0;
	s = ft_next(str, charset, 0, 0);
	while (idx < cnt)
	{
		e = ft_next(str, charset, s, 1);
		ft_salloc((void **)&(ret[idx]), 1, e - s + 1);
		ft_sc(ret[idx], str, s, e);
		idx++;
		s = ft_next(str, charset, e, 0);
		if (str[s] == '\0')
			break ;
	}
	return (ret);
}
