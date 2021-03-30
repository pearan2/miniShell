# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 21:49:15 by honlee            #+#    #+#              #
#    Updated: 2021/03/30 15:50:14 by honlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR	=		./srcs/
SRCNAME = 	\
					main.c\
					malloc_util1.c\
					split_util1.c\
					split_util2.c\
					split_util3.c\
					split_util4.c\
					split_util5.c\
					get_next_line.c\
					exit_util1.c\
					parse_util1.c\
					parse_util2.c\
					parse_util3.c\
					string_util1.c\
					error_util1.c\
					string_util2.c\
					proc_util1.c\
					termios_util1.c\
					termios_util2.c\
					termios_util3.c\
					list_util1.c\
					signal_util1.c\
					message_util1.c\
					init_util1.c\

SRCS		=	${addprefix ${SRCDIR}, ${SRCNAME}}
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
					lldb ${NAME}

fclean		:		clean
					rm -f ${NAME}

clean		:		
					rm -rf ./forTest/*

all			:		${NAME}

re			:		fclean all
