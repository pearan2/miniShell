/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_support1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:35:53 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 23:20:05 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parent_exit(t_info *info, int fd[2])
{
	long	stat;
	int		sstat;
	char	*result;

	get_next_line(fd[0], &result);
	stat = my_atoi(result);
	sstat = stat % 256;
	if (sstat < 0)
		sstat *= -1;
	free(result);
	if (info->is_print == 1)
		exit(sstat);
}

static void	support_p_cd(t_info *info, int env_num)
{
	chdir(info->env[env_num] + 4);
}

void	ft_parent_cd(t_info *info, int fd[2])
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
	support_p_cd(info, num_env);
	get_next_line(fd[0], &result);
	info->built_result_num = my_atoi(result) % 256;
	free(result);
}
