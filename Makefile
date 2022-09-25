# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: go <go@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 22:37:19 by go                #+#    #+#              #
#    Updated: 2022/09/25 20:34:24 by go               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
OPRERATOR_DIR = operator/
SRCS = ft_push_swap.c ft_check_error.c 
SRCS_OPERATOR = ${OPRERATOR_DIR}ft_create_list.c \
		${OPRERATOR_DIR}ft_push_list.c \
		${OPRERATOR_DIR}ft_swap_list.c \
		${OPRERATOR_DIR}ft_rotate_list.c \
		${OPRERATOR_DIR}ft_reverse_rotate_list.c
LIB = libft.a
LIB_DIR = libft
RM = rm
RMFLAGS = -f
AR = ar
ARFLAGS = crs

all : ${NAME}
${NAME} : ${LIB} ${SRCS}
	${CC} ${CFLAGS} ${SRCS} ${SRCS_OPERATOR} -L${LIB_DIR} -lft -o ${NAME}
${LIB} :
	cd ${LIB_DIR} && make
clean :
	cd ${LIB_DIR} && make clean
fclean :
	${RM} ${RMFLAGS} ${NAME} 
	cd ${LIB_DIR} && make fclean
re : fclean all
.PHONY : all clean fclean re