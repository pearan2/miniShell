# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 21:49:15 by honlee            #+#    #+#              #
#    Updated: 2021/03/23 16:28:31 by honlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR	=		./srcs/
SRCNAME = 	\
					main.c\
					malloc_util1.c\
					split_util1.c\
					split_util2.c\
					get_next_line.c\
					exit_util1.c\
					parse_util1.c\
					string_util1.c\
					error_util1.c\
					string_util2.c\
					proc_util1.c\
					test_util1.c\

SRCS		=	${addprefix ${SRCDIR}, ${SRCNAME}}
OBJS		=	${SRCS:.c=.o}

INCDIR		=		./includes/
CC			=		gcc
#CF			=		-Wall -Wextra -Werror
CF			=		-g
NAME		=		miniShell

.c.o		:
					${CC} ${CF} -c $< -o ${<:.c=.o} -I${INCDIR}

${NAME}		:	${OBJS} 
					${CC} ${CF} ${OBJS} -o ${NAME}

fclean		:		clean
					rm -f ${NAME}

clean		:		
					rm -f ${OBJS}


all			:		${NAME}

re			:		fclean all
