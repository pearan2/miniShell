/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:02:19 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/30 13:33:34 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_env_full(t_info *info, char *str)
{
	char	*out;
	char	*temp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	temp = my_strjoin(str, "=");
	out = 0;
	while(info->env[i])
	{
		if (ft_strcmp(info->env[i], temp) == 0)
		{
			len = ft_strlen(info->env[i]);
			ft_salloc((void*)&out, sizeof(char *), len + 1);
			out = ft_strdup(info->env[i]);
			break;
		}
		i++;
	}
	return (out);
}

int			get_env_num(t_info *info, char *str)
{
	char	*temp;
	int		i;
	int		out;

	i = 0;
	temp = my_strjoin(str, "=");
	out = -1;
	while(info->env[i] != NULL)
	{
		if (ft_strncmp(info->env[i], temp, ft_strlen(temp)) == 0)
		{
			out = i;
			break;
		}
		i++;
	}
	free(temp);
	return (out);
}

char		*get_env(t_info *info, char *str)
{
	char	*out;
	char	*temp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	temp = my_strjoin(str, "=");
	out = 0;
	while(info->env[i] != NULL)
	{
		if (ft_strncmp(info->env[i], temp, ft_strlen(temp)) == 0)
		{
			len = ft_strlen(info->env[i]);
			ft_salloc((void*)&out, sizeof(char *), len - 3);
			out = ft_strdup(info->env[i] + 4);
			break;
		}
		i++;
	}
	free(temp);
	return (out);
}
