/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:37:50 by honlee            #+#    #+#             */
/*   Updated: 2021/03/25 13:53:53 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_printable(char c)
{
	if (c >= 32 && c <= 127)
		return (1);
	return (0);
}

char	*str_append(char *target, char *value)
{
	char	*ret;
	int		idx;
	int		idx2;

	idx = 0;
	idx2 = 0;
	ft_salloc((void**)&ret, 1, ft_strlen(target) + ft_strlen(value) + 2);
	while (target[idx] != 0)
	{
		ret[idx2] = target[idx];
		idx2++;
		idx++;
	}
	ret[idx2++] = '/';
	idx = 0;
	while (value[idx] != 0)
	{
		ret[idx2] = value[idx];
		idx2++;
		idx++;
	}
	ret[idx2] = 0;
	return (ret);
}

char	**find_path(t_info *info)
{
	char	**ret;
	int		idx;
	char	**result;

	idx = 0;
	while ((info->env)[idx] != 0)
	{
		ret = ft_split((info->env)[idx], "=");
		if (ft_strcmp(ret[0], "PATH") == 0)
		{
			result = ft_split(ret[1], ":");
			ft_split_free2(ret);
			return (result);
		}
		ft_split_free2(ret);
		idx++;
	}
	return (NULL);
}
