/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:54:49 by honlee            #+#    #+#             */
/*   Updated: 2021/03/31 20:52:49 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signo)
{
	g_data.signo = signo;
	write(0, "\n", 1);
	free(g_data.line);
	g_data.line = ft_strdup("");
	if (g_data.is_fork == 0)
		put_prompt();
	g_data.signo = 0;
	return ;
}

void	sigquit_handler(int signo)
{
	g_data.signo = signo;
	if (g_data.is_fork == 1)
		write(2, QUIT, ft_strlen(QUIT));
	g_data.signo = 0;
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
