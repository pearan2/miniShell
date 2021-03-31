/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:17:48 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 23:22:41 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

static char	*rebase_cd_join(char **split)
{
	char	*out;
	char	*temp;
	int		j;

	j = -1;
	out = ft_strdup("");
	while (split[++j])
	{
		temp = out;
		out = my_strjoin(temp, "/");
		free(temp);
		temp = out;
		out = my_strjoin(temp, split[j]);
		free(temp);
	}
	return (out);
}

static void	rebase_cd(t_info *info, int i, int fd[2], char *old)
{
	char	**split;
	char	*temp;
	char	*temp2;
	int		j;

	j = -1;
	split = ft_split(info->opt[i], "/");
	while (split[++j])
	{
		temp = split[j];
		split[j] = change_input_to_env(info, split[j]);
		free(temp);
		if (split[0][0] == '\0')
			go_home(info, old, fd);
	}
	temp = rebase_cd_join(split);
	temp2 = info->opt[i];
	info->opt[i] = temp;
	free(temp2);
}

void	rebase_input_cd(t_info *info, int i, int fd[2], char *old)
{
	int		j;

	j = 0;
	while (info->opt[i][j])
	{
		if (info->opt[i][j] == '$')
		{
			rebase_cd(info, i, fd, old);
			break ;
		}
		j++;
	}
}

int	is_can_open(char *pwd)
{
	DIR		*dir;
	int		flag;

	flag = 0;
	dir = opendir(pwd);
	if (dir == NULL)
		flag = 1;
	else
		closedir(dir);
	if (flag == 1)
		return (1);
	return (0);
}
