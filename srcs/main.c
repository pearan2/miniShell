/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:27:53 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 17:20:38 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_info info;
	info->env = env;
	ret = environ;
	while (ret[idx] != 0)
	{
		printf("%s\n", ret[idx]);
		idx++;
	}
	return (0);
}
