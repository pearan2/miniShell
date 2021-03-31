/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:44:08 by honlee            #+#    #+#             */
/*   Updated: 2021/03/31 17:53:13 by junhypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cursor_position(int *row, int *col)
{
	int		a;
	int		i;
	char	buf[255];
	int		ret;

	a = 0;
	i = 1;
	write(0, "\033[6n", 4);
	ret = read(0, buf, 254);
	buf[ret] = '\0';
	while (buf[i])
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			if (a == 0)
				*row = ft_atoi(&buf[i]) - 1;
			else
				*col = ft_atoi(&buf[i]) - 1;
			a++;
			i += ft_nbrlen(ft_atoi(&buf[i])) - 1;
		}
		i++;
	}
}

int		ft_nbrlen(int value)
{
	int		ret;

	ret = 0;
	while (value / 10 != 0)
	{
		ret++;
		value = value / 10;
	}
	ret++;
	return (ret);
}

int		putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

int		get_win_col(void)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

void	term_backspace(int col_max, char **line)
{
	int	n_row;
	int	n_col;

	if (ft_strlen(*line) <= 0)
		return ;
	ft_charbackspace(line);
	get_cursor_position(&n_row, &n_col);
	n_col--;
	if (n_col < 0)
	{
		n_row = n_row - 1;
		n_col = col_max;
	}
	tputs(tgoto(tgetstr("cm", NULL), n_col, n_row), 1, putchar_tc);
	tputs(tgetstr("ce", NULL), 1, putchar_tc);
}
