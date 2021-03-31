/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:03:51 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 23:27:57 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*my_strjoin(char *s1, char *s2)
{
	char	*out;
	int		len1;
	int		len2;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ft_salloc((void *)&out, sizeof(char), len1 + len2 + 1);
	while (i < len1 + len2)
	{
		if (i < len1)
			out[i] = s1[i];
		else
			out[i] = s2[i - len1];
		i++;
	}
	out[i] = 0;
	return (out);
}
