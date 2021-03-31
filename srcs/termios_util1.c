/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 03:13:25 by honlee            #+#    #+#             */
/*   Updated: 2021/03/31 20:53:58 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_term(struct termios *save, struct termios *setting)
{
	tcgetattr(0, save);
	tcgetattr(0, setting);
	setupterm(NULL, STDOUT_FILENO, NULL);
	setting->c_lflag &= ~(ICANON | ECHO);
	setting->c_cc[VTIME] = 0;
	setting->c_cc[VMIN] = 1;
	return ;
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

void	putchar_and_save(char c, t_list_info *list_info, char *content)
{
	write(1, &c, 1);
	ft_lstadd_back(list_info->head, ft_lstnew(ft_strdup(content)));
	list_info->pos++;
	list_info->size++;
	return ;
}

void	ft_charappend_write(char **line, char c)
{
	ft_charappend2(line, c);
	write(1, &c, 1);
	return ;
}

void	do_term_loop(char **line, t_list_info *list_info)
{
	long	buff;
	int		o_row;
	int		o_col;
	int		col_max;

	buff = 0;
	col_max = get_win_col();
	get_cursor_position(&o_row, &o_col);
	while (read(0, &buff, sizeof(buff)) > 0)
	{
		if (buff == BACKSPACE)
			term_backspace(col_max, line);
		else if (buff == UP_ARROW)
			term_uparrow(col_max, o_col, line, list_info);
		else if (buff == DOWN_ARROW)
			term_downarrow(col_max, o_col, line, list_info);
		else if (buff == EOF_KEY)
			sigcd_handler(ft_strlen(*line));
		else if (is_printable((char)buff) == 1)
			ft_charappend_write(line, (char)buff);
		if ((char)buff == '\n')
			return (putchar_and_save('\n', list_info, *line));
		buff = 0;
	}
}
