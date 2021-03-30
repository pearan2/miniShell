/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:54:49 by honlee            #+#    #+#             */
/*   Updated: 2021/03/30 13:19:55 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signo)
{
	signo = 0;
	write(0, "\n", 1);
	free(g_line);
	g_line = ft_strdup("");
	put_prompt();
	return ;
}

void	sigquit_handler(int signo)
{
	signo = 0;
	return ;
}

void	sigcd_handler(int inputlen)
{
	if (inputlen > 0)
		return ;
	write(2, "exit\n", 5);
	exit(0);
	return ;
}
