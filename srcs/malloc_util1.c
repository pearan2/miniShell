/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 03:13:25 by honlee            #+#    #+#             */
/*   Updated: 2021/03/31 17:33:09 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_salloc(void **target, int type_size, int alloc_size)
{
	if (type_size < 0 || alloc_size < 0)
		return (1);
	(*target) = malloc(type_size * alloc_size);
	if ((*target) == 0)
	{
		ft_puterror("miniShell", errno);
		exit(1);
	}
	return (0);
}
