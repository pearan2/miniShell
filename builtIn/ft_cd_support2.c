/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_support2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:04:40 by junhypar          #+#    #+#             */
/*   Updated: 2021/04/01 10:01:36 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*combine_str_support(char *out, char *temp)
{
	char	*del;
	char	*out2;

	out2 = ft_strdup(out);
	del = out2;
	out2 = my_strjoin(out2, "/");
	free(del);
	del = out2;
	out2 = my_strjoin(out2, temp);
	free(del);
	return (out2);
}

void	do_cd(t_info *info, char *old, char *pwd, int fd[2])
{
	char	*temp;

	if (is_can_open(pwd))
	{
		free(pwd);
		free(old);
		write(1, "minishell: cd: ", 10);
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

void	go_old(t_info *info, char *old, int fd[2])
{
	char	*pwd;
	char	*home;

	home = get_env(info, "OLDPWD");
	pwd = my_strjoin("PWD=", home);
	write(1, home, ft_strlen(home));
	write(1, "\n", 1);
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

void	go_home(t_info *info, char *old, int fd[2])
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
