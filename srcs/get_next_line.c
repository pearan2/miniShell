/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:14:45 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 17:17:12 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniShell.h"

char		*bu_append(char *bu, char *buff)
{
	char			*ret;
	int				idx1;
	int				idx2;

	if (bu == 0)
		return (ft_strdup(buff));
	if (!(ret = malloc(ft_len(bu) + ft_len(buff) + 1)))
		return (NULL);
	idx1 = -1;
	while (bu[++idx1] != 0)
		ret[idx1] = bu[idx1];
	idx2 = -1;
	while (buff[++idx2] != 0)
		ret[idx1 + idx2] = buff[idx2];
	ret[idx1 + idx2] = 0;
	free(bu);
	return (ret);
}

int			bu_split(char **line, char *bu)
{
	int				nl_idx;
	int				idx;
	char			*temp;

	nl_idx = is_newline(bu);
	if (!(temp = malloc(nl_idx + 1)))
		return (-1);
	idx = -1;
	while (bu[++idx] != '\n')
		temp[idx] = bu[idx];
	temp[idx] = 0;
	*line = temp;
	idx = -1;
	nl_idx++;
	while (bu[++idx + nl_idx] != 0)
		bu[idx] = bu[idx + nl_idx];
	bu[idx] = 0;
	return (1);
}

int			return_end(int fd, char **bus, char **line, int rb)
{
	if (rb == -1)
		return (-1);
	if (bus[fd] != 0 && is_newline(bus[fd]) != -1)
		return (bu_split(line, bus[fd]));
	if (bus[fd] != 0)
	{
		*line = bus[fd];
		bus[fd] = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char					*bus[OPEN_MAX];
	char						*buff;
	int							rb;

	if (line == 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((rb = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rb] = 0;
		bus[fd] = bu_append(bus[fd], buff);
		if (is_newline(bus[fd]) != -1)
		{
			free(buff);
			return (bu_split(line, bus[fd]));
		}
	}
	free(buff);
	return (return_end(fd, bus, line, rb));
}
