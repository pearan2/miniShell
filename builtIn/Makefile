NAME = test
SRCS = tester.c \
	   get_next_line.c \
	   \
	   ft_strdup.c \
	   ft_strlen.c \
	   \
	   ft_built_in.c\
	   ft_env.c\


OBJS = ${SRCS:.c=.o}
CC	=	gcc -Wall -Werror -Wextra

all: ${NAME}

.c.o:
		${CC} -c $< -o ${<:.c=.o} -I../include

${NAME}: ${OBJS}
		${CC} ${OBJS} -o ${NAME}

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re .c.o
