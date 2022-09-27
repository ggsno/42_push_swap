# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: go <go@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 22:37:19 by go                #+#    #+#              #
#    Updated: 2022/09/28 07:19:21 by go               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
OPRERATOR_DIR = operator/
UTIL_DIR = util/
SRCS = ft_push_swap.c ft_check_error.c ft_sort.c
SRCS_OPERATOR = ${OPRERATOR_DIR}ft_set_list.c \
		${OPRERATOR_DIR}ft_push_list.c \
		${OPRERATOR_DIR}ft_swap_list.c \
		${OPRERATOR_DIR}ft_rotate_list.c \
		${OPRERATOR_DIR}ft_reverse_rotate_list.c \
		${UTIL_DIR}ft_atoi.c \
		${UTIL_DIR}ft_lstlast.c \
		${UTIL_DIR}ft_lstnew.c \
		${UTIL_DIR}ft_lstsize.c \
		${UTIL_DIR}ft_putstr.c \
		${UTIL_DIR}ft_itoa.c \
		${UTIL_DIR}ft_strlen.c
# LIB = libft.a
# LIB_DIR = libft
RM = rm
RMFLAGS = -f
# AR = ar
# ARFLAGS = crs

all : ${NAME}
# ${NAME} : ${LIB} ${SRCS}
# 	${CC} ${CFLAGS} ${SRCS} ${SRCS_OPERATOR} -L${LIB_DIR} -lft -o ${NAME}
${NAME} : ${SRCS}
	${CC} ${CFLAGS} ${SRCS} ${SRCS_OPERATOR} -o ${NAME}
# ${LIB} :
# 	cd ${LIB_DIR} && make
clean :
	cd ${LIB_DIR} && make clean
fclean :
	${RM} ${RMFLAGS} ${NAME} 
	cd ${LIB_DIR} && make fclean
re : fclean all
.PHONY : all clean fclean re