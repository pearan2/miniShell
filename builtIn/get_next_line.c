/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:11:02 by junhypar          #+#    #+#             */
/*   Updated: 2021/03/23 10:54:44 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t		ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t a;
	size_t b;

	if (!dest || !src)
		return (0);
	a = 0;
	b = 0;
	if (size != 0)
	{
		while (src[a] && a < size - 1)
		{
			dest[a] = src[a];
			a++;
		}
		dest[a] = '\0';
	}
	while (src[b])
	{
		b++;
	}
	return (b);
}

char			*gnl_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*out;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (!(out = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	ft_strlcpy(out, s1, len1 + 1);
	free(s1);
	ft_strlcpy(out + len1, s2, len2 + 1);
	return (out);
}

int		ft_config(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-22);
}

void	print_line(char **out, char **line, int i)
{
	int		j;
	char	*s;

	(*out)[i] = '\0';
	*line = ft_strdup(*out);
	j = ft_strlen(*out + i + 1);
	if (j == 0)
	{
		free(*out);
		*out = 0;
	}
	else
	{
		s = ft_strdup(*out + i + 1);
		free(*out);
		*out = s;
	}
}

int		final_print(char **out, char **line, int i)
{
	if (i < 0)
		return (-1);
	if (*out && (ft_config(*out) >= 0))
	{
		print_line(out, line, ft_config(*out));
		return (1);
	}
	else if (*out)
	{
		*line = *out;
		*out = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buff[2];
	static char	*out;
	int			count;
	int			i;

	while ((count = read(fd, buff, 1)) > 0)
	{
		buff[count] = '\0';
		out = gnl_strjoin(out, buff);
		if ((i = ft_config(out)) >= 0)
		{
			print_line(&out, line, i);
			return (1);
		}
	}
	return (final_print(&out, line, count));
}
