/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:27:53 by honlee            #+#    #+#             */
/*   Updated: 2021/03/23 17:40:50 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(t_info *info)
{
	char		**splited_path;
	struct stat	sb;
	int			idx;
	char		*ret;

	idx = 0;
	splited_path = find_path(info);
	if (splited_path == NULL)
		return (NULL);
	while (splited_path[idx] != 0)
	{
		ret = str_append(splited_path[idx], info->opt[0]);
		if (stat(ret, &sb) != -1)
		{
			ft_split_free2(splited_path);
			return (ret);
		}
		free(ret);
		idx++;
	}
	ft_split_free2(splited_path);
	return (NULL);
}

int		do_proc(t_info *info)
{
	char	*path;

	if (info->opt[0] == 0)
		return (1);
	if (ft_strcmp(info->opt[0], "echo") == 0
			|| ft_strcmp(info->opt[0], "cd") == 0
			|| ft_strcmp(info->opt[0], "pwd") == 0
			|| ft_strcmp(info->opt[0], "export") == 0
			|| ft_strcmp(info->opt[0], "unset") == 0
			|| ft_strcmp(info->opt[0], "env") == 0
			|| ft_strcmp(info->opt[0], "exit") == 0)
		return (0);
	path = get_path(info);
	if (path == NULL)
		return (1);
	else
	{
		proc_inner(info, path);
		return (0);
	}
	return (0);
}

void	do_loop(char *line, t_info *info)
{
	char	*s;
	char	*e;
	
	s = line;
	while (1)
	{
		e = ft_find_pc(s);
		init_info(info, e);
		if (e != 0)
			*e = 0;
		if (make_info(info, ft_split(s, " ")) != 0 || do_proc(info) != 0)
		{
			ft_puterror("miniShell", errno);
			free_info(info);
			break ;
		}
		if (e == NULL)
		{
			free_info(info);
			break ;
		}
		free_info(info);
		s = e + 1;
	}
}

int	main(int ac, char **av, char **env)
{
	t_info	info;
	char	*line;
	int		ret;

	ac = 0;
	av = 0;
	info.env = ft_copy_string_arr(env);
	info.is_print = 0;
	info.is_redirect = 0;
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret == -1)
			return (exit_with_strerror(line));
		do_loop(line, &info);
		free(line);
	}
	return (0);
}
