/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:02:19 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/30 23:39:05 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			get_env_num(t_info *info, char *str)
{
	char	*temp;
	int		i;
	int		out;

	i = 0;
	temp = ft_strdup(str);
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
	out = ft_strdup("");
	while(info->env[i] != NULL)
	{
		if (ft_strncmp(info->env[i], temp, ft_strlen(temp)) == 0)
		{
			len = ft_strlen(info->env[i]);
			ft_salloc((void*)&out, sizeof(char *), len - ft_strlen(temp) - 1);
			out = ft_strdup(info->env[i] + ft_strlen(temp));
			break;
		}
		i++;
	}
	free(temp);
	return (out);
}

static char	*support_change_input_to_env(t_info *info, char *str)
{
	char	**split;
	char	*temp;
	char	*out;
	int		len;

	len = 0;
	out = ft_strdup("");
	split = ft_split(str, "$");
	while (split[len])
	{
		temp = split[len];
		split[len] = get_env(info, temp);
		free(temp);
		len++;	
	}
	len = 0;
	while (split[len])
	{
		temp = out;
		out = my_strjoin(out, split[len]);
		free(temp);
		len++;
	}
	ft_split_free2(split);
	return (out);
}

char		*change_input_to_env(t_info *info, char *str)
{
	char	*out;
	int		i;
	char	*temp;
	char	*temp2;
	char	*temp3;

	i = -1;
	out = ft_strdup(str);
	while (str[++i])
	{
		if (str[i] == '$')
		{
			temp2 = support_change_input_to_env(info, str + i);
			str[i] = '\0';
			temp = ft_strdup(str);
			temp3 = out;
			out = my_strjoin(temp, temp2);
			free(temp3);
			free(temp);
			free(temp2);
			break;
		}
	}
	return (out);
}
