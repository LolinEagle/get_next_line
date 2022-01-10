# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frrusso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 11:29:59 by frrusso           #+#    #+#              #
#    Updated: 2022/01/10 15:56:21 by frrusso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
AR		=	ar -rcs
RM		=	rm -rf
FLAGS	=	-Wall -Werror -Wextra -D BUFFER_SIZE=42
NAME	=	get_next_line.a
SRCS	=	get_next_line.c get_next_line_utils.c
OBJS	=	${SRCS:.c=.o}
BSRCS	=	get_next_line_bonus.c get_next_line_utils_bonus.c
BOBJS	=	${SRCS:.c=.o}

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

bonus:${BOBJS}
	${AR} ${NAME} ${BOBJS}

debug:all
	${CC} main.c ${NAME} && clear && ./a.out

git:fclean
	${RM} a.out

