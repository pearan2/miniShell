/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 07:48:57 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/29 08:18:28 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_pwd(char *str)
{
	if (str[0] == 'P' && str[1] == 'W' && str[2] == 'D' && str[3] == '=')
		return (1);
	return (-1);
}

char		*get_pwd(t_info *info)
{
	int		i;
	int		flag;
	int		len;
	char	*out;

	i = 0;
	len = 0;
	flag = -1;
	while(info->env[i])
	{
		flag = find_pwd(info->env[i]);
		if (flag == 1)
		{
			len = ft_strlen(info->env[i]);
			ft_salloc((void*)&out, sizeof(char *), len - 3);
			out = ft_strdup(info->env[i] + 4);
			break;
		}
		i++;
	}
	return (out);
}

int			ft_cd(t_info *info, int fd)
{
	char	*old;
	char	*temp;
	int		len;

	temp = get_pwd(info);
	old = my_strjoin("OLDPWD=", temp);
	
	len = ft_strlen(old)
	write(info->fd_stdout, old, len);
	write(info->fd_stdout, "\n", 1);
	write(fd[1], "0\n", 2);
	exit(0);
}
