/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:17:48 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/30 15:49:27 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

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
		write(1, "cd: no such file or directory: ", 31);
		write(1, info->opt[1], ft_strlen(info->opt[1]));
		write(1, "\n", 1);
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
	pwd = my_strjoin("PWD", home);
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
