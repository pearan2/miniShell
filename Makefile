# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 21:49:15 by honlee            #+#    #+#              #
#    Updated: 2021/03/31 20:58:39 by honlee           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

SRCS = 	\
					./srcs/main.c\
					./srcs/malloc_util1.c\
					./srcs/split_util1.c\
					./srcs/split_util2.c\
					./srcs/split_util3.c\
					./srcs/split_util4.c\
					./srcs/split_util5.c\
					./srcs/get_next_line.c\
					./srcs/exit_util1.c\
					./srcs/parse_util1.c\
					./srcs/parse_util2.c\
					./srcs/parse_util3.c\
					./srcs/string_util1.c\
					./srcs/error_util1.c\
					./srcs/string_util2.c\
					./srcs/proc_util1.c\
					./srcs/termios_util1.c\
					./srcs/termios_util2.c\
					./srcs/termios_util3.c\
					./srcs/list_util1.c\
					./srcs/signal_util1.c\
					./srcs/message_util1.c\
					./srcs/init_util1.c\
					./builtIn/ft_built_in.c\
					./builtIn/ft_built_in_support1.c\
					./builtIn/ft_built_in_support2.c\
					./builtIn/ft_built_in_support3.c\
					./builtIn/ft_cd.c\
					./builtIn/ft_cd_support.c\
					./builtIn/ft_cd_support2.c\
					./builtIn/ft_cd_support3.c\
					./builtIn/ft_env.c\
					./builtIn/ft_exit.c\
					./builtIn/ft_export.c\
					./builtIn/ft_export_no_comp.c\
					./builtIn/ft_unset.c\
					./builtIn/ft_echo.c\
					./builtIn/ft_echo_support.c\
					./builtIn/ft_get_env.c\
					./builtIn/ft_my_atoi_itoa.c\
					./builtIn/ft_my_strjoin.c\
					./builtIn/ft_pwd.c\
					./builtIn/ft_strncmp.c\

OBJS		=	${SRCS:.c=.o}


INCDIR		=		./includes/
CC			=		clang
CF			=		-Wall -Wextra -Werror -I ${INCDIR} ${SRCS} -lncurses
DCF			=		-g -I ${INCDIR} ${SRCS} -lncurses
NAME		=		minishell

${NAME}		:		
					${CC} ${CF} -o ${NAME}

test		:
					${CC} ${DCF} -o ${NAME}

fclean		:		
					rm -f ${NAME}

clean		:		
					rm -f ${NAME}

all			:		${NAME}

re			:		fclean all
