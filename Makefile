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

CC		=	cc
AR		=	ar -r
RM		=	rm -f
FLAGS	=	-Wall -Werror -Wextra -D BUFFER_SIZE=9999
NAME	=	get_next_line.a
SRCS	=	get_next_line.c get_next_line_utils.c
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

debug:git all
	${CC} ${FLAGS} main.c ${NAME} && clear && ./a.out | cat -e

git:fclean
	${RM} a.out

.PHONY: all clean fclean re
