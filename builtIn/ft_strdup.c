/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:51:06 by junhypar          #+#    #+#             */
/*   Updated: 2020/07/01 10:35:43 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(char *src)
{
	char	*a;
	int		b;

	b = 0;
	while (src[b])
		b++;
	a = (char *)malloc(sizeof(char) * (b + 1));
	if (!a)
		return (NULL);
	b = 0;
	while (src[b])
	{
		a[b] = src[b];
		b++;
	}
	a[b] = 0;
	return (a);
}
