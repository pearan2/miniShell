/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 03:13:25 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 14:06:13 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_salloc(void**target, int type_size, int alloc_size)
{
	if (type_size < 0 || alloc_size < 0)
		return (0);
	(*target) = malloc(type_size * alloc_size);
	if ((*target) == 0)
		return (0);
	return (1);
}