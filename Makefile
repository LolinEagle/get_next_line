# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frrusso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 11:29:59 by frrusso           #+#    #+#              #
#    Updated: 2021/12/20 16:32:05 by frrusso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
AR		=	ar -r
RM		=	rm
FLAGS	=	-Wall -Werror -Wextra -D BUFFER_SIZE=42
NAME	=	get_next_line.a
SRCS	=	get_next_line.c main.c
OBJS	=	${SRCS:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	${AR} ${NAME} ${OBJS}

all:${NAME}

clean:
	${RM} ${OBJS}

fclean:clean
	${RM} ${NAME}

re:fclean all

debug:all
	${CC} main.c ${NAME}
	./a.out

git:fclean
	${RM} a.out
