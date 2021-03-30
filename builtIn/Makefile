NAME = test

SRCDIR	=		../srcs/
SRCNAME = 	\
					malloc_util1.c\
					split_util1.c\
					split_util2.c\
					split_util3.c\
					get_next_line.c\
					exit_util1.c\
					parse_util1.c\
					parse_util2.c\
					parse_util3.c\
					string_util1.c\
					error_util1.c\
					string_util2.c\
					proc_util1.c\
					get_char_util1.c\
					test_util1.c\

SRCS = ${addprefix ${SRCDIR}, ${SRCNAME}}\
		tester.c \
	   ft_built_in.c\
	   ft_env.c\
	   ft_pwd.c\
	   ft_exit.c\
	   ft_cd.c\
	   ft_my_atoi_itoa.c\
	   ft_my_strjoin.c\
	   ft_get_env.c\
	   ft_strncmp.c\
	   ft_cd_support.c\


OBJS = ${SRCS:.c=.o}
CC	=	gcc #-Wall -Werror -Wextra

all: ${NAME}

.c.o:
		${CC} -c $< -o ${<:.c=.o} -I../includes

${NAME}: ${OBJS}
		${CC} ${OBJS} -o ${NAME}

clean:
		rm -f ${OBJS}
		rm stdout
		rm stdin
		echo >stdout
		echo >stdin

fclean: clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re .c.o
