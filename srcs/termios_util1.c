/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 03:13:25 by honlee            #+#    #+#             */
/*   Updated: 2021/03/25 17:51:47 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_term(void)
{
	struct termios termios_p;
	tcgetattr(0, &termios_p);
	//이게 있어야 커서 이동 가능함.
	setupterm(NULL, STDOUT_FILENO, NULL);
	termios_p.c_lflag &= ~(ICANON|ECHO);
	termios_p.c_cc[VTIME] = 0;
	termios_p.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW, &termios_p);
}

int	ft_atoi(const char *str)
{
	unsigned int		ret;
	unsigned int		is_minus;

	ret = 0;
	is_minus = 0;
	while ((*str <= '\r' && *str >= '\t') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_minus = 1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
		ret = (ret * 10) + (*str++) - '0';
	if (is_minus)
		return (ret * (-1));
	return (ret);
}

int	ft_nbrlen(int	value)
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

int		putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void	do_term_loop(char **line)
{
	long	buff;
	char	c;
	int		pos;
	int		c_row;
	int		c_col;
	char	*cm = tgetstr("cm", NULL);

	buff = 0;
	pos = 0;
	while(read(0, &buff, sizeof(buff)) > 0)
	{
		if (buff > 0)
		{            
			if (buff == BACKSPACE)
			{
				get_cursor_position(&c_row, &c_col);
				printf("%d, %d\n", c_row, c_col);
				if (pos > 0)
				{
					write(1, DEL_BUF, ft_strlen(DEL_BUF));
					pos--;
				}
			}
			else if (buff == UP_ARROW)
			{
				tputs(tgoto(cm, 1, 1), 1, putchar_tc);
				//tputs(tgetstr("ce", NULL), 1, putchar_tc);
				write(1, "asdf", 4);
			}
			else if (buff == DOWN_ARROW)
				printf("DOWN_ARROW!!\n");
			else
			{
				c = (char)buff;
				if (is_printable(c) == 1)
				{
					ft_charappend2(line, c);
					write(1, &c, 1);
					pos++;
				}
				if (c == '\n')
				{
					write(1, &c, 1);
					return ;
				}
			}
		}
		buff = 0;
	}
}