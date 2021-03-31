/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:44:51 by honlee            #+#    #+#             */
/*   Updated: 2021/03/31 17:33:18 by junhypar         ###   ########.fr       */
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

int		ft_puterror_return(char *p_name, char *str)
{
	write(2, p_name, ft_strlen(p_name));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (1);
}
