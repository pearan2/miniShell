# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 21:49:15 by honlee            #+#    #+#              #
#    Updated: 2021/03/22 13:48:35 by honlee           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

SRCDIR	=		./srcs/
SRCNAME = 	\
					main.c\
					malloc_util1.c\
					split_util1.c\
					split_util2.c\

SRCS		=	${addprefix ${SRCDIR}, ${SRCNAME}}
OBJS		=	${SRCS:.c=.o}

INCDIR		=		./includes/
CC			=		gcc
CF			=		-Wall -Wextra -Werror
#CF		=		-g
NAME		=		miniShell

.c.o		:
					${CC} ${CF} -c $< -o ${<:.c=.o} -I${INCDIR}

${NAME}		:	${OBJS} 
					${CC} ${CF} ${OBJS} -o ${NAME}

test		:	re ${OBJS}
					${CC} ${CF} ${OBJS} -o ${NAME}

fclean		:		clean
					rm -f ${NAME}

clean		:		
					rm -f ${OBJS}


all			:		${NAME}

re			:		fclean all
