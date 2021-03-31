/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 07:48:57 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 23:22:12 by junhypar         ###   ########.fr       */
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
	return (99);
}

char	*combine_str2(char **pwd)
{
	int		i;
	int		len;
	char	*del;
	char	*out;

	len = 0;
	while (pwd[len])
		len++;
	i = 0;
	if ((len - 1) <= 0)
		out = ft_strdup("/");
	else
		out = ft_strdup("");
	while (i < len - 1)
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

static char	*combine_str(char *pwd, char *temp, int flag)
{
	char	*out;
	char	**p_str;
	char	*del;

	out = ft_strdup(pwd);
	p_str = ft_split(out, "/");
	del = out;
	out = result_of_combine(p_str, out, temp, flag);
	free(del);
	ft_split_free2(p_str);
	return (out);
}

static char	*pasing_dir(t_info *info, char *pwd, char *temp)
{
	char	**t_str;
	char	*del;
	char	*out;
	int		i;
	int		flag;

	i = 0;
	t_str = ft_split(temp, "/");
	if (is_home_dir(t_str[0], &i))
		out = get_env(info, "HOME");
	else
		out = ft_pasing_dir_support(pwd, temp);
	while (t_str[i])
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
	ft_split_free2(t_str);
	return (out);
}

void	ft_cd(t_info *info, int fd[2])
{
	char	*old;
	char	*pwd;
	char	*n_pwd;

	pwd = get_env(info, "PWD");
	old = my_strjoin("OLDPWD=", pwd);
	if (info->opt[1] != 0)
	{
		rebase_input_cd(info, 1, fd, old);
		if (is_old_dir_flag(info->opt[1]))
		{
			free(pwd);
			go_old(info, old, fd);
		}
		n_pwd = pasing_dir(info, pwd, info->opt[1]);
		if (n_pwd[0] == '\0')
		{
			free(n_pwd);
			n_pwd = ft_strdup("/");
		}
		free(pwd);
		do_cd(info, old, n_pwd, fd);
	}
	else
		ft_exit_cd_support3(info, old, fd, pwd);
}
