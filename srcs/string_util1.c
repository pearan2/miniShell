/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:55:54 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 21:42:50 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
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

int	ft_string_append(char ***target, char *value)
{
	char **temp;
	int	idx;
	int iter;

	temp = NULL;
	idx = 0;
	iter = -1;
	while ((*target)[idx] != 0)
		idx++;
	if (ft_salloc((void**)&temp, sizeof(char *), idx + 2) == 0)
	{
		free(value);
		ft_split_free2(*target);
		return (0);
	}
	while (++iter < idx)
		temp[iter] = (*target)[iter];
	temp[iter++] = ft_strdup(value);
	temp[iter] = 0;
	free(*target);
	*target = temp;
	return (1);
}

char	*ft_strdup(const char *src)
{
	size_t		src_size;
	char		*ret;
	size_t		idx;

	idx = 0;
	src_size = (size_t)ft_strlen(src);
	if (!(ret = (char *)malloc(src_size + 1)))
		return (NULL);
	while (idx < src_size)
	{
		ret[idx] = src[idx];
		idx++;
	}
	ret[idx] = 0;
	return (ret);
}
