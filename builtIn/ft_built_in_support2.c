/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_support2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:35:53 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 23:20:47 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**add_env(t_info *info, char *env, int len)
{
	char	**data;
	int		i;

	i = -1;
	ft_salloc((void **)&data, sizeof(char *), len + 2);
	while (++i < len)
		data[i] = ft_strdup(info->env[i]);
	data[i] = ft_strdup(env);
	data[i + 1] = NULL;
	return (data);
}

static int	len_of_env(t_info *info)
{
	int		out;

	out = 0;
	while (info->env[out])
		out++;
	return (out);
}

static void	put_env(t_info *info, char *result)
{
	int		env_num;
	int		len;
	char	**sp_result;
	char	**temp;
	char	*temp2;

	sp_result = ft_split(result, "=");
	env_num = get_env_num(info, sp_result[0]);
	ft_split_free2(sp_result);
	if (env_num == -1)
	{
		len = len_of_env(info);
		temp = info->env;
		info->env = add_env(info, result, len);
		ft_split_free2(temp);
	}
	else
	{
		temp2 = info->env[env_num];
		info->env[env_num] = ft_strdup(result);
		free(temp2);
	}
}

void	ft_parent_export(t_info *info, int fd[2])
{
	int		i;
	char	*result;

	i = 0;
	while (1)
	{
		get_next_line(fd[0], &result);
		if (ft_strcmp(result, "export_end") == 0)
		{
			free(result);
			break ;
		}
		else
		{
			put_env(info, result);
			free(result);
		}
	}
	get_next_line(fd[0], &result);
	info->built_result_num = my_atoi(result) % 256;
	free(result);
}
