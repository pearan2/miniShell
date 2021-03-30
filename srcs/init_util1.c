/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:59:53 by honlee            #+#    #+#             */
/*   Updated: 2021/03/30 13:11:50 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_all(t_list_info *list_info, t_info *info,
				struct termios *save, struct termios *setting)
{
	ft_salloc((void **)&(list_info->head), sizeof(t_list *), 1);
	*(list_info->head) = 0;
	list_info->pos = -1;
	list_info->size = 0;
	put_welcome_msg();
	put_prompt();
	info->fd_stdin = -2;
	init_term(save, setting);
	signal(SIGQUIT, sigquit_handler);
	signal(SIGINT, sigint_handler);
	return ;
}
