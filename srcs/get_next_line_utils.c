/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 10:03:33 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 17:14:14 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniShell.h"

int					ft_len(char *str)
{
	int				ret;

	ret = 0;
	while (str[ret] != 0)
		ret++;
	return (ret);
}

int					is_newline(char *str)
{
	int				idx;

	idx = 0;
	while (str[idx] != 0)
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

char				*ft_strdup(char *input)
{
	char			*ret;
	int				len;
	int				idx;

	len = ft_len(input);
	if (!(ret = malloc(len + 1)))
		return (NULL);
	idx = -1;
	while (input[++idx] != 0)
		ret[idx] = input[idx];
	ret[idx] = 0;
	return (ret);
}
