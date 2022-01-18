# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frrusso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 11:29:59 by frrusso           #+#    #+#              #
#    Updated: 2022/01/12 17:44:23 by frrusso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
AR		=	ar -r
RM		=	rm -f
FLAGS	=	-Wall -Werror -Wextra -D BUFFER_SIZE=1
NAME	=	get_next_line.a
SRCS	=	src/get_next_line.c src/get_next_line_utils.c
OBJS	=	${SRCS:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	${AR} ${NAME} ${OBJS}

all:${NAME}

clean:
	${RM} ${OBJS}

fclean:clean
	${RM} ${NAME} a.out

re:fclean all

debug:fclean all
	${CC} ${FLAGS} main.c ${NAME} && clear && ./a.out | cat -e

.PHONY: all clean fclean re debug
