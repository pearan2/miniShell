/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:02:19 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/30 19:15:32 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			temp = ft_strdup(str + i + 1);
			temp2 = get_env(info, temp);
			free(temp);
			str[i] = '\0';
			temp = ft_strdup(str);
			temp3 = out;
			out = my_strjoin(temp, temp2);
			free(temp3);
			free(temp);
			free(temp2);
		}
	}
	return (out);
}
