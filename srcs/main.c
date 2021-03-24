/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:27:53 by honlee            #+#    #+#             */
/*   Updated: 2021/03/24 17:46:34 by honlee           ###   ########.fr       */
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
		path = ft_strdup(info->opt[0]);
	proc_inner(info, path);
	return (0);
}

void	do_loop(char *line, t_info *info)
{
	char	*s;
	char	*e;

	if (*line == 0)
		return ;
	s = line;
	while (1)
	{
		e = ft_find_pc(s);
		init_info(info, e);
		if (e != 0)
			*e = 0;
		if (make_info(info, ft_split_input(s)) != 0 || do_proc(info) != 0)
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
		while (*s == ' ')
			s++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_info	info;
	char	*line;
	int		ret;

	ac = 0;
	av = 0;
	write(1, "minishell > ", 12);
	info.env = ft_copy_string_arr(env);
	info.fd_stdin = -2;
	line = ft_strdup("");
	while (1)
	{
		//ret = get_char(&line);
		ret = get_next_line(0, &line);
		if (ret == -1)
			return (exit_with_strerror(line));
		ft_string_trim_free(&line);
		if (check_quotes(line) != 0)
			write(2, "quotes error\n", ft_strlen("quotes error\n"));
		else
			do_loop(line, &info);
		free(line);
		write(1, "minishell > ", 12);
	}
	return (0);
}
