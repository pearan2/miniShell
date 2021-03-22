/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 03:13:25 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 15:13:46 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>

typedef struct		s_info
{
	char			**env;
	char			*order;
	char			**opt;
	int				fd_stdin;
	int				fd_stdout;
}					t_info;

int					ft_salloc(void **target, int type_size, int alloc_size);
unsigned int		ft_next(char *str, char *charset, unsigned int s, int is_sep);
char				**ft_split_free(char **target, unsigned int idx);
char				**ft_split(char *str, char *charset);

#endif 
