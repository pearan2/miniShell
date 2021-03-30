/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:54:49 by honlee            #+#    #+#             */
/*   Updated: 2021/03/30 10:46:15 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signo)
{
	write(0, "\n", 1);
	free(g_line);
	g_line = ft_strdup("");
	return ;
}

void	sigquit_handler(int signo)
{
	return ;
}

void	sigcd_handler(int inputlen)
{
	if (inputlen > 0)
		return ;
	write(2, "exit\n", 5);
	//free and reset;	
	exit(0);
	return ;
}