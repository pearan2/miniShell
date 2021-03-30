/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_support1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:35:53 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/30 22:45:27 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_parent_exit(int fd[2])
{
	long	stat;
	char	*result;

	get_next_line(fd[0], &result);
	stat = my_atoi(result);
	stat = stat % 256;
	free(result);
	exit((int)stat);
}

static void	support_p_cd(t_info *info)
{
	char	*pwd;

	pwd = get_env(info, "PWD");
	chdir(pwd);
	free(pwd);
}

void		ft_parent_cd(t_info *info, int fd[2])
{
	int		i;
	int		num_env;
	char	*result;

	i = 0;
	get_next_line(fd[0], &result);
	num_env = get_env_num(info, "OLDPWD");
	if (num_env >= 0)
	{
		free(info->env[num_env]);
		info->env[num_env] = ft_strdup(result);
	}
	free(result);
	get_next_line(fd[0], &result);
	num_env = get_env_num(info, "PWD");
	if (num_env >= 0)
	{
		free(info->env[num_env]);
		info->env[num_env] = ft_strdup(result);
	}
	free(result);
	support_p_cd(info);
	get_next_line(fd[0], &result);
	info->built_result_num = my_atoi(result) % 256;
	free(result);
}
