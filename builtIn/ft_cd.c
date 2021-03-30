/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 07:48:57 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/30 15:22:34 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	scan_command(char *str)
{
	if (str[0] == '.')
	{
		if (str[1] == '\0')
			return (0);
		else if (str[1] == '.' && str[2] == '\0')
			return (-1);
	}
	return (1);
}

static char *combine_str2(char **pwd)
{
	int		i;
	int		len;
	char	*del;
	char	*out;

	len = 0;
	while(pwd[len])
		len++;
	out = ft_strdup("");
	i = 0;
	while(i < len - 1)
	{
		del = out;
		out = my_strjoin(out, "/");
		free(del);
		del = out;
		out = my_strjoin(out, pwd[i]);
		free(del);
		i++;
	}
	return (out);
}

static char *combine_str(char *pwd, char *temp, int flag)
{
	char	*out;
	char	**p_str;
	char	*del;

	out = ft_strdup(pwd);
	p_str = ft_split(out, "/");
	if (flag > 0)
	{
		del = out;
		out = my_strjoin(out, "/");
		free(del);
		del = out;
		out = my_strjoin(out, temp);
		free(del);
	}
	else
	{
		del = out;
		out = combine_str2(p_str);
		free(del);
	}
	ft_split_free2(p_str);
	return (out);
}

static char	*pasing_dir(char *pwd, char *temp)
{
	char	**t_str;
	char	*del;
	char	*out;
	int		i;
	int		flag;

	i = 0;
	t_str = ft_split(temp, "/");
	out = ft_strdup(pwd);
	while(t_str[i])
	{
		flag = scan_command(t_str[i]);
		if (flag)
		{
			del = out;
			out = combine_str(out, t_str[i], flag);
			free(del);
		}
		i++;
	}
	return (out);
}

void		ft_cd(t_info *info, int fd[2])
{
	char	*old;
	char	*pwd;
	char	*n_pwd;
	char	*temp;
	int		len;
	int		flag;

	pwd = get_env(info, "PWD");
	old = my_strjoin("OLDPWD=", pwd);
	if (info->opt[1] != 0)
	{
		temp = ft_strdup(info->opt[1]);
		n_pwd = pasing_dir(pwd, temp);
		free(pwd);
		free(temp);
		do_cd(info, old, n_pwd, fd);
	}
	else
	{
		free(pwd);
		go_home(info, old, fd);
	}
}
