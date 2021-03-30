/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:55:40 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/30 23:36:10 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static void	rebase_input(t_info *info, int i)
{
	char	*temp;

	temp = info->opt[i];
	info->opt[i] = change_input_to_env(info, temp);
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
	if (info->opt[i][0] >= '0' && info->opt[i][0] <= '9')
		return (1);
	j = 0;
	while(info->opt[i][j])
	{
		if (info->opt[i][j] == '\'' || info->opt[i][j] == '\"' ||
				info->opt[i][j] == '=')
			return (1);
		j++;
	}
	return (0);
}

static void	unset_error(char *str, int *tag)
{
	*tag = 1;
	write(2, "bash: unset: \'", 14);
	write(2, str, ft_strlen(str));
	write(2, "\': not a valid identifier\n", 26);
}

void		ft_unset(t_info *info, int fd[2])
{
	int		i;
	int		flag;
	int		tag;

	tag = 0;
	if (info->opt[1] == 0)
	{
		write(fd[1], "0\n", 2);
		exit(0);
	}
	i = 0;
	while (info->opt[++i])
	{
		flag = is_available(info, i);
		if (flag)
			unset_error(info->opt[i], &tag);
		else
		{
			write(fd[1], info->opt[i], ft_strlen(info->opt[i]));
			write(fd[1], "\n", 1);
		}
	}
	write(fd[1], "unset_end\n", 10);
	if (tag)
		write(fd[1], "1\n", 2);
	else
		write(fd[1], "0\n", 2);
	exit(40);
}
