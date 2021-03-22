/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:04:56 by honlee            #+#    #+#             */
/*   Updated: 2021/01/06 23:01:28 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

char			**ft_split_free(char **target, unsigned int idx)
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
