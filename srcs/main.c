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

int	main(int ac, char **av, char **env)
{
	t_info	info;
	char	*line;
	int		ret;
	char	**splited;

	av = 0;
	init_info(&info, env);
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret == -1)
			return (exit_with_strerror(line));
		splited = ft_split(line, "|;"); // 0처리 해줘야함 나중에.
		ac = -1;
		while(splited[++ac] != 0)
		{
			make_info(&info, ft_split(splited, " "));
			proc_order(&info);
		}
		ft_split_free2(splited);		
		free(line);
		line = 0;
	}
	free(line);
	line = 0;
	return (0);
}
