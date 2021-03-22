/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:43:00 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 18:21:47 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniShell.h"

int	exit_with_strerror(void*free_target)
{
	strerror(errno);
	/* free something */
	free(free_target);
	return (1);
}

int return_with_free(t_info *info, int en, char **splited)
{
	int		idx;

	idx = 0;
	if (splited != NULL)
	{
		while (splited[idx] != 0)
			free(splited[idx++]);
		free(splited);
	}
	idx = 0;
	if (info->env != NULL)
		while (info->env[idx] != 0)
			free(info->env[idx++]);
	if (info->order != NULL)
		free(info->order);
	idx = 0;
	if (info->opt != NULL)
		while (info->opt[idx] != 0)
			free(info->opt[idx++]);
	strerror(en);
	return (1);
}