/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:27:53 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 15:44:40 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env);
{
	t_info info;
	info->env = env;
	//ret = ft_split("this is for test!","ih");
	ret = environ;
	while (ret[idx] != 0)
	{
		printf("%s\n", ret[idx]);
		idx++;
	}
	return (0);
}
