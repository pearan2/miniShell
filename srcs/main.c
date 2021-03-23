/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:27:53 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 21:57:24 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_loop(char *line, t_info *info)
{
	char	*s;
	char	*e;

	s = line;
	
	while (1)
	{
		e = ft_find_pc(s);
		init_info(info, e);
		*e = 0;
		make_info(info, ft_split(s, " "));
		if (e == NULL)
			break;
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
	info.env = env;
	info.is_print = 0;
	info.is_redirct = 0;
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
