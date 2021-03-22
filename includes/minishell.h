/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 03:13:25 by honlee            #+#    #+#             */
/*   Updated: 2021/03/22 18:22:23 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct		s_info
{
	char			**env;
	char			*order;
	char			**opt;
	int				fd_stdin;
	int				fd_stdout;
	int				is_append;
}					t_info;

int					*ft_built_in(t_info *info);
int					ft_salloc(void **target, int type_size, int alloc_size);
unsigned int		ft_next(char *str, char *charset, unsigned int s, int is_sep);
char				**ft_split_free(char **target, unsigned int idx);
char				**ft_split(char *str, char *charset);
int					ft_len(char *str);
int					is_newline(char *str);
char				*ft_strdup(char *input);
int					get_next_line(int fd, char **line);
int					exit_with_strerror(void*free_target);
void				make_info(t_info *info, char **ret);
void				init_info(t_info *info, char **env);
int					ft_strcmp(char *s1, char *s2);
int					ft_string_append(char **target, char *value);
int					return_with_free(t_info *info, int en, char **splited);
void				ft_split_free2(char *target);

#endif 
