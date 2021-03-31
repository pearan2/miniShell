/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:55:54 by honlee            #+#    #+#             */
/*   Updated: 2021/03/31 17:51:14 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_copy_string_arr(char **target)
{
	int		idx;
	char	**ret;

	idx = 0;
	while (target[idx] != 0)
		idx++;
	ft_salloc((void **)&ret, sizeof(char *), idx + 1);
	idx = -1;
	while (target[++idx] != 0)
		ret[idx] = ft_strdup(target[idx]);
	ret[idx] = NULL;
	return (ret);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (1)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0')
			break ;
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_find_pc(char *target)
{
	int		idx;

	idx = 0;
	while (target[idx] != 0)
	{
		if (target[idx] == '|' || target[idx] == ';')
			return (&target[idx]);
		idx++;
	}
	return (NULL);
}

int		ft_string_append(char ***target, char *value)
{
	char	**temp;
	int		idx;
	int		iter;

	temp = NULL;
	idx = 0;
	iter = -1;
	while ((*target)[idx] != 0)
		idx++;
	ft_salloc((void **)&temp, sizeof(char *), idx + 2);
	while (++iter < idx)
		temp[iter] = (*target)[iter];
	temp[iter++] = ft_strdup(value);
	temp[iter] = 0;
	free(*target);
	*target = temp;
	return (0);
}

char	*ft_strdup(const char *src)
{
	size_t		src_size;
	char		*ret;
	size_t		idx;

	idx = 0;
	ret = NULL;
	src_size = (size_t)ft_strlen(src);
	ft_salloc((void **)&ret, 1, src_size + 1);
	while (idx < src_size)
	{
		ret[idx] = src[idx];
		idx++;
	}
	ret[idx] = 0;
	return (ret);
}
