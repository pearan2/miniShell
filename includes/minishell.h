/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 03:13:25 by honlee            #+#    #+#             */
/*   Updated: 2021/03/26 01:58:45 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include <term.h>
# include <sys/ioctl.h>
# include <termios.h>

# define BACKSPACE 127
# define EOF_KEY 4
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699
# define DEL_BUF "\b \b"

typedef struct		s_info
{
	char			**env;
	char			**opt;
	int				fd_stdin;
	int				fd_stdout;
	int				fd_stdout_r;
	int				is_print;
	int				built_result_num;
}					t_info;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_list_info
{
	t_list			**head;
	int				pos;
	int				size;
}					t_list_info;

int					*ft_built_in(t_info *info);
int					ft_salloc(void **target, int type_size, int alloc_size);
unsigned int		ft_next(char *str, char *charset, unsigned int s, int is_sep);
char				**ft_split_free(char **target, unsigned int idx);
char				**ft_split(char *str, char *charset);
int					ft_len(char *str);
int					is_newline(char *str);
int					get_next_line(int fd, char **line);
int					exit_with_strerror(void*free_target);
int					make_info(t_info *info, char **ret);
int					init_info(t_info *info, char *od);
int					ft_strcmp(char *s1, char *s2);
int					ft_string_append(char ***target, char *value);
void				free_info(t_info *info);
int					ft_split_free2(char **target);
char				*ft_strdup(const char *src);
int					ft_strlen(const char *src);
void				ft_puterror(char *p_name, int en);
char				*ft_find_pc(char *target);
char				**ft_copy_string_arr(char **target);
char				**find_path(t_info *info);
char				*str_append(char *target, char *value);
int					proc_inner(t_info *info, char *path);
int					check_quotes(char *line);
char				**ft_split_input(char *line);
char    			*str_trim_free(char **tg);
char				*ft_string_trim_free(char **line);
int					get_char(char **line);
char				*str_trim_dup(char *line);
void				init_term(struct termios *save, struct termios *setting);
void				do_term_loop(char **line, t_list_info *list_info);
int					is_printable(char c);
char 				*ft_charappend2(char **target, char value);
char				**ft_split_input2(char *line);
void				get_cursor_position(int *rows, int *cols);
int					ft_nbrlen(int value);
int					ft_atoi(const char *str);
void				term_backspace(int col_max, char **line);
void				term_uparrow(int col_max, int o_col, char **line, t_list_info *list_info);
void				term_downarrow(int col_max, int o_col, char **line, t_list_info *list_info);
int					putchar_tc(int tc);
int					get_win_col(void);
void				ft_charbackspace(char **line);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
char				*ft_lst_getdata(t_list_info *list_info);

/*for test */
void	show_info(t_info *info);
/*for test */

/**/
void				ft_env(t_info *info, int fd[2]);
void				ft_pwd(t_info *info, int fd[2]);
void				ft_exit(t_info *info, int fd[2]);

long				my_atoi(char *str);
char				*my_itoa(long num);
/**/

#endif 
