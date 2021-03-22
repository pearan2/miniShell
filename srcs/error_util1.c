/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:44:51 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 21:58:23 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_puterror(char *p_name, int en)
{
	write(2, p_name, ft_strlen(p_name));
	write(2, ": ", 2);
	write(2, strerror(en), ft_strlen(strerror(en)));
	write(2, "\n", 1);
}