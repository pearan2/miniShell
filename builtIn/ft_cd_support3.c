/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_support3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:04:40 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 16:18:55 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_old_dir_flag(char *str)
{
	if (str != NULL)
	{
		if (str[0] == '-')
		{
			if (str[1] == '\0')
			{
				return (1);
			}
		}
	}
	return (0);
}

int			is_home_dir(char *str, int *i)
{
	if (str != NULL)
	{
		if (str[0] == '~')
		{
			if (str[1] == '\0')
			{
				*i = 1;
				return (1);
			}
		}
	}
	*i = 0;
	return (0);
}

char		*result_of_combine(char **p_str, char *out, char *temp,
		int flag)
{
	char	*del;
	char	*out2;

	out2 = ft_strdup(out);
	if (flag > 0)
	{
		del = out2;
		out2 = combine_str_support(out2, temp);
		free(del);
	}
	else
	{
		del = out2;
		out2 = combine_str2(p_str);
		free(del);
	}
	return (out2);
}
