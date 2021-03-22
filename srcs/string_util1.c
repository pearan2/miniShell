/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:55:54 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 18:39:31 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniShell.h"

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
	
}