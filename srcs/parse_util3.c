/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:45:40 by honlee            #+#    #+#             */
/*   Updated: 2021/03/31 20:51:27 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_trim_dup(char *line)
{
	char	*temp;

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

int	ft_get_info_opt_len(t_info *info)
{
	int		idx;

	idx = 0;
	while (info->opt[idx] != NULL)
		idx++;
	return (idx);
}

void	ft_info_trim(t_info *info)
{
	int		idx;

	idx = 0;
	if (ft_get_info_opt_len(info) == 0)
		return ;
	info->opt[0] = str_trim_free(&(info->opt[0]));
	if (ft_strcmp(info->opt[0], "echo") == 0)
		return ;
	else
		while (info->opt[++idx] != NULL)
			info->opt[idx] = str_trim_free(&(info->opt[idx]));
	return ;
}
