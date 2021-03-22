/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:39:34 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 17:26:58 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int static	ft_strlen(const char *str)
{
	int		ret;

	ret = 0;
	while (str[ret] != 0)
		ret++;
	return (ret);
}

char static	*ft_charappend(char *target, char value)
{
	int		idx;
	char	*ret;

	idx = 0;
	ret = NULL;
	if (ft_salloc(&ret, 1, ft_strlen(target) + 2) == 0)
		return (0);
	while (target[idx] != 0)
	{
		ret[idx] = target[idx];
		idx++;
	}
	ret[idx] = value;
	idx++;
	ret[idx] = 0;
	free(target);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	int		rb;
	char	buff;

	if (ft_salloc(line, 1, 1) == 0)
		return (-1);
	(*line)[0] = 0;
	while (1)
	{
		rb = read(fd, &buff, 1);
		if (rb <= 0)
			break ;
		if (buff == '\n')
			return (1);
		*line = ft_charappend(*line, buff);
		if (*line == 0)
			return (-1);
	}
	if (rb == -1)
		return (-1);
	else
		return (0);
}
