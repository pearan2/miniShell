/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_no_comp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:57:50 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 23:25:02 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_export(t_info *info, char **str, int fd[2])
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[i])
	{
		len = ft_strlen(str[i]);
		if (info->is_print == 0)
		{
			write(info->fd_stdout, "declare -x ", 11);
			write(info->fd_stdout, str[i], len);
			write(info->fd_stdout, "\n", 1);
		}
		else
		{
			write(1, "declare -x ", 11);
			write(1, str[i], len);
			write(1, "\n", 1);
		}
		i++;
	}
	write(fd[1], "0\n", 2);
	exit(0);
}

static char	**sort_env(t_info *info, int len)
{
	char	**out;
	char	*temp;
	int		i;
	int		j;

	ft_salloc((void **)&out, sizeof(char *), len);
	i = -1;
	while (++i < len)
		out[i] = ft_strdup(info->env[i]);
	out[len] = NULL;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len - 1)
		{
			if (ft_strcmp(out[j], out[j + 1]) > 0)
			{
				temp = out[j];
				out[j] = out[j + 1];
				out[j + 1] = temp;
			}
		}
	}
	return (out);
}

void	no_comp_export(t_info *info, int fd[2])
{
	int		env_len;
	char	**sort;

	env_len = 0;
	while (info->env[env_len])
		env_len++;
	sort = sort_env(info, env_len);
	write_export(info, sort, fd);
}
