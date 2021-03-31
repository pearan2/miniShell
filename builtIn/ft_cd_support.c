/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:17:48 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 13:47:09 by junhypar         ###   ########.fr       */
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

static void	rebase_cd(t_info *info, int i)
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
	}
	temp = rebase_cd_join(split);
	temp2 = info->opt[i];
	info->opt[i] = temp;
	free(temp2);
}	

void		rebase_input_cd(t_info *info, int i)
{
	int		j;

	j = 0;
	while(info->opt[i][j])
	{
		if (info->opt[i][j] == '$')
		{
			rebase_cd(info, i);
			break;
		}
		j++;
	}
}

static int	is_can_open(char *pwd)
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

void		do_cd(t_info *info, char *old, char *pwd, int fd[2])
{
	char	*temp;
	int		hi;

	if (is_can_open(pwd))
	{
		free(pwd);
		free(old);
		write(1, "bash: cd: ", 10);
		write(1, info->opt[1], ft_strlen(info->opt[1]));
		write(1, ": No such file or directory\n", 28);
		write(fd[1], "1\n", 2);
		exit(1);
	}
	temp = pwd;
	pwd = my_strjoin("PWD=", pwd);
	free(temp);
	write(fd[1], old, ft_strlen(old));
	write(fd[1], "\n", 1);
	write(fd[1], pwd, ft_strlen(pwd));
	write(fd[1], "\n", 1);
	write(fd[1], "0\n", 2);
	free(pwd);
	free(old);
	exit(10);
}

void		go_home(t_info *info, char *old, int fd[2])
{
	char	*pwd;
	char	*home;

	home = get_env(info, "HOME");
	pwd = my_strjoin("PWD=", home);
	free(home);
	write(fd[1], old, ft_strlen(old));
	write(fd[1], "\n", 1);
	write(fd[1], pwd, ft_strlen(pwd));
	write(fd[1], "\n", 1);
	write(fd[1], "0\n", 2);
	free(pwd);
	free(old);
	exit(10);
}
