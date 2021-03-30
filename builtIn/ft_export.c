/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:37:03 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/31 00:10:23 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	rebase_input(t_info *info, int i)
{
	char	**split;
	char	*temp;
	char	*temp2;
	int		j;

	j = -1;
	split = ft_split(info->opt[i], "=");
	while (split[++j])
	{
		temp = split[j];
		split[j] = change_input_to_env(info, split[j]);
		free(temp);
	}
	temp = my_strjoin(split[0], "=");
	temp2 = info->opt[i];
	info->opt[i] = my_strjoin(temp, split[1]);
	ft_split_free2(split);
	free(temp2);
	free(temp);
}

static int	is_available(t_info *info, int i)
{
	int		j;

	j = 0;
	while(info->opt[i][j])
	{
		if (info->opt[i][j] == '$')
		{
			rebase_input(info, i);
			break;
		}
		j++;
	}
	if (info->opt[i][0] == '=')
		return (1);
	if (info->opt[i][0] >= '0' && info->opt[i][0] <= '9')
		return (1);
	j = 0;
	while(info->opt[i][j])
	{
		if (info->opt[i][j] == '\'' || info->opt[i][j] == '\"')
			return (1);
		j++;
	}
	return (0);
}

static void	export_error(char *str, int *tag)
{
	*tag = 1;
	write(2, "bash: export: \'", 15);
	write(2, str, ft_strlen(str));
	write(2, "\': not a valid identifier\n", 26);
}

void		ft_export(t_info *info, int fd[2])
{
	int		i;
	int		flag;
	int		tag;

	tag = 0;
	if (info->opt[1] == 0)
		no_comp_export(info, fd);
	i = 0;
	while (info->opt[++i])
	{
		flag = is_available(info, i);
		if (flag)
			export_error(info->opt[i], &tag);
		else if (info->is_print == 1)
		{
			write(fd[1], info->opt[i], ft_strlen(info->opt[i]));
			write(fd[1], "\n", 1);
		}
	}
	write(fd[1], "export_end\n", 11);
	if (tag && info->is_print == 1)
		write(fd[1], "1\n", 2);
	else
		write(fd[1], "0\n", 2);
	exit(30);
}
