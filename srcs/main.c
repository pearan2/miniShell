/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:27:53 by honlee            #+#    #+#             */
/*   Updated: 2021/03/26 16:24:52 by honlee           ###   ########.fr       */
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
		if (make_info(info, ft_split_input2(str_trim_dup(s))) != 0 || do_proc(info) != 0)
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
	t_info			info;
	t_list_info		list_info;
	struct termios	save;
	struct termios	setting;

	ac = 0;
	av = 0;
	ft_salloc((void**)&(list_info.head), sizeof(t_list *), 1);
	*(list_info.head) = 0;
	list_info.pos = -1;
	list_info.size = 0;
	write(1, "minishell > ", 12);
	info.env = ft_copy_string_arr(env);
	info.fd_stdin = -2;
	init_term(&save, &setting);
	signal(SIGQUIT, sigquit_handler);
	signal(SIGINT, sigint_handler);
	while (1)
	{
		g_line = ft_strdup("");
		tcsetattr(0,TCSANOW, &setting);
		do_term_loop(&g_line, &list_info);
		tcsetattr(0,TCSANOW, &save);
		ft_string_trim_free(&g_line);
		if (check_quotes(g_line) != 0)
			write(2, "quotes error\n", ft_strlen("quotes error\n"));
		else
			do_loop(g_line, &info);
		free(g_line);
		write(1, "minishell > ", 12);
	}
	return (0);
}
