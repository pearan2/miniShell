/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:45:40 by honlee            #+#    #+#             */
/*   Updated: 2021/03/25 14:34:46 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_trim_dup(char *line)
{
	char *temp;

	temp = ft_strdup(line);
	return (ft_string_trim_free(&temp));
}

char	*str_trim_free(char **tg)
{
	char	*ret;
	int		idx;
	char	f_val;

	ret = ft_strdup("");
	idx = -1;
	f_val = 0;
	while ((*tg)[++idx] != 0)
	{
		if ((*tg)[idx] == '\'' || (*tg)[idx] == '\"')
		{
			if (f_val == 0)
				f_val = (*tg)[idx];
			else if (f_val == (*tg)[idx])
				f_val = 0;
			else
				ft_charappend2(&ret, (*tg)[idx]);
		}
		else
			ft_charappend2(&ret, (*tg)[idx]);
	}
	free(*tg);
	*tg = ret;
	return (ret);
}