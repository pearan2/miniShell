/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:04:56 by honlee            #+#    #+#             */
/*   Updated: 2021/03/31 20:52:59 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_free(char **target, unsigned int idx)
{
	unsigned int		iter;

	iter = 0;
	while (iter < idx)
	{
		free(target[iter]);
		iter++;
	}
	free(target);
	return (0);
}

int	ft_split_free2(char **target)
{
	int			idx;

	idx = 0;
	if (target != NULL)
	{
		while (target[idx] != 0)
			free(target[idx++]);
		free(target);
	}
	return (1);
}
