/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_util3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 01:00:41 by honlee            #+#    #+#             */
/*   Updated: 2021/03/30 13:29:32 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	term_uparrow(int col_max, int o_col, char **line,
						t_list_info *list_info)
{
	int	n_row;
	int	n_col;
	int	len;

	if (list_info->size == 0)
		return ;
	len = ft_strlen(*line);
	get_cursor_position(&n_row, &n_col);
	free(*line);
	list_info->pos--;
	if (list_info->pos < 0)
		list_info->pos = list_info->size - 1;
	while (len + o_col > col_max)
	{
		tputs(tgoto(tgetstr("cm", NULL), 0, n_row), 1, putchar_tc);
		tputs(tgetstr("ce", NULL), 1, putchar_tc);
		len -= col_max;
		n_row--;
	}
	tputs(tgoto(tgetstr("cm", NULL), o_col, n_row), 1, putchar_tc);
	tputs(tgetstr("ce", NULL), 1, putchar_tc);
	*line = ft_strdup(ft_lst_getdata(list_info));
	write(1, *line, ft_strlen(*line));
}

void	term_downarrow(int col_max, int o_col, char **line,
						t_list_info *list_info)
{
	int	n_row;
	int	n_col;
	int	len;

	if (list_info->size == 0)
		return ;
	len = ft_strlen(*line);
	get_cursor_position(&n_row, &n_col);
	free(*line);
	list_info->pos++;
	if (list_info->pos >= list_info->size)
		list_info->pos = 0;
	while (len + o_col > col_max)
	{
		tputs(tgoto(tgetstr("cm", NULL), 0, n_row), 1, putchar_tc);
		tputs(tgetstr("ce", NULL), 1, putchar_tc);
		len -= col_max;
		n_row--;
	}
	tputs(tgoto(tgetstr("cm", NULL), o_col, n_row), 1, putchar_tc);
	tputs(tgetstr("ce", NULL), 1, putchar_tc);
	*line = ft_strdup(ft_lst_getdata(list_info));
	write(1, *line, ft_strlen(*line));
}
