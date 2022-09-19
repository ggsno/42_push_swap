# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: go <go@student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 22:37:19 by go                #+#    #+#              #
#    Updated: 2022/09/20 00:24:09 by go               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_push_swap.c ft_check_error.c
LIB = libft.a
LIB_DIR = libft
RM = rm
RMFLAGS = -f
AR = ar
ARFLAGS = crs

all : ${NAME}
${NAME} : ${LIB} ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -L${LIB_DIR} -lft -o ${NAME}
${LIB} :
	cd ${LIB_DIR} && make
clean :
	cd ${LIB_DIR} && make clean
fclean :
	${RM} ${RMFLAGS} ${NAME} 
	cd ${LIB_DIR} && make fclean
re : fclean all
.PHONY : all clean fclean re