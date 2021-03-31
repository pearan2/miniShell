/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_util4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:30:05 by honlee            #+#    #+#             */
/*   Updated: 2021/03/31 20:53:11 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_split_input2_proc_quotes(char *line, char **temp, int idx,
										char *f_va)
{
	ft_charappend2(temp, line[idx]);
	if (line[idx] == '\'' || line[idx] == '\"')
	{
		if (*f_va == 0)
			*f_va = line[idx];
		else
		{
			if (*f_va == line[idx])
				*f_va = 0;
		}
	}
}

void	ft_split_input2_init_all(char **temp, int *idx,
								char *f_va, char ***ret)
{
	*temp = ft_strdup("");
	*idx = -1;
	*f_va = 0;
	ft_salloc((void **)ret, sizeof(char *), 1);
	(*ret)[0] = NULL;
}

void	ft_split_input2_charappend(char ***ret, char **temp)
{
	ft_string_append(ret, *temp);
	free(*temp);
	*temp = ft_strdup("");
}

char	**ft_split_input2_free_all(char *line, char *temp, char **ret)
{
	free(line);
	free(temp);
	ft_split_free2(ret);
	return (NULL);
}

int	ft_split_input2_f_va_zero(char ***ret, char **temp, int *idx,
								char *line)
{
	char	sep;

	sep = line[*idx];
	if (ft_strlen(*temp) > 0)
		ft_split_input2_charappend(ret, temp);
	if (sep == ' ')
		while (line[*idx + 1] == ' ')
			(*idx)++;
	else
	{
		while (line[*idx] == sep)
			ft_charappend2(temp, line[(*idx)++]);
		(*idx)--;
		if (ft_strlen(*temp) > 2 || (ft_strlen(*temp) == 2
				&& (*temp)[0] == '<'))
		{
			ft_split_input2_free_all(line, *temp, *ret);
			return (1);
		}
		ft_split_input2_charappend(ret, temp);
	}
	return (0);
}
