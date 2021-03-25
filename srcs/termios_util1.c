/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 03:13:25 by honlee            #+#    #+#             */
/*   Updated: 2021/03/24 17:34:30 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_term(void)
{
	struct termios termios_p;
	tcgetattr(0, &termios_p);

	termios_p.c_lflag &= ~(ICANON|ECHO);
	termios_p.c_cc[VTIME] = 0;
	termios_p.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW, &termios_p);
}

void	do_term_loop(char **line)
{
	long	buff;
	char	c;
	int		pos;

	buff = 0;
	pos = 0;
	while(read(0, &buff, sizeof(buff)) > 0)
	{
		if (buff > 0)
		{            
			if (buff == BACKSPACE)
			{
				if (pos > 0)
				{
					write(1, DEL_BUF, ft_strlen(DEL_BUF));
					pos--;
				}
			}
			else if (buff == UP_ARROW)
				printf("UP_ARROW!!\n");
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