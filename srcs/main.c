/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:27:53 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 17:51:44 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_info	info;
	char	*line;
	int		ret;

	ac = 0;
	av = 0;
	init_info(&info, env);
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret == -1)
			return (exit_with_strerror(line));
		
		free(line);
		line = 0;
	}
	printf("%s", line);
	free(line);
	line = 0;
	return (0);
}
