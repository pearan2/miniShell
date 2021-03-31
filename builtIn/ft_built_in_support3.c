/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_support3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:35:53 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 23:21:25 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**del_env2(t_info *info, int len, int env_num)
{
	char	**data;
	int		i;
	int		j;

	i = -1;
	j = 0;
	ft_salloc((void **)&data, sizeof(char *), len);
	while (++i < len)
	{
		if (i != env_num)
		{
			data[j] = ft_strdup(info->env[i]);
			j++;
		}
	}
	data[j] = NULL;
	return (data);
}

static void	del_env(t_info *info, char *result)
{
	int		env_num;
	int		len;
	char	**temp;

	env_num = get_env_num(info, result);
	if (env_num != -1)
	{
		len = 0;
		while (info->env[len])
			len++;
		temp = info->env;
		info->env = del_env2(info, len, env_num);
		ft_split_free2(temp);
	}
}

void	ft_parent_unset(t_info *info, int fd[2])
{
	int		i;
	char	*result;

	i = 0;
	while (1)
	{
		get_next_line(fd[0], &result);
		if (ft_strcmp(result, "unset_end") == 0)
		{
			free(result);
			break ;
		}
		else
		{
			del_env(info, result);
			free(result);
		}
	}
	get_next_line(fd[0], &result);
	info->built_result_num = my_atoi(result) % 256;
	free(result);
}
