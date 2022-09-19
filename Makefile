# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: go <go@student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 22:37:19 by go                #+#    #+#              #
#    Updated: 2022/09/20 00:04:09 by go               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_push_swap.c ft_check_error.c
LIB = libftprintf.a
LIB_DIR = ft_printf
RM = rm
RMFLAGS = -f
AR = ar
ARFLAGS = crs

all : ${NAME}
${NAME} : ${LIB} ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -L${LIB_DIR} -lftprintf -o ${NAME}
${LIB} :
	cd ${LIB_DIR} && make
clean :
	cd ${LIB_DIR} && make clean
fclean :
	${RM} ${RMFLAGS} ${NAME} 
	cd ${LIB_DIR} && make fclean
re : fclean all
.PHONY : all clean fclean re