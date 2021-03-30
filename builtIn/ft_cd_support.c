/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:17:48 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/30 15:20:28 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

void		do_cd(t_info *info, char *old, char *pwd, int fd[2])
{
	char	*temp;

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
