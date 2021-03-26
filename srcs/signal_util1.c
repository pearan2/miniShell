/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:54:49 by honlee            #+#    #+#             */
/*   Updated: 2021/03/26 16:07:25 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signo)
{
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
	exit(0);
}