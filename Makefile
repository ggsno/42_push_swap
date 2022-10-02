# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: go <go@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 22:37:19 by go                #+#    #+#              #
#    Updated: 2022/10/02 17:05:05 by go               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
OPRERATOR_DIR = operator/
UTIL_DIR = util/
SRCS_OPERATOR = ${OPRERATOR_DIR}ft_set_list.c \
		${OPRERATOR_DIR}ft_push_list.c \
		${OPRERATOR_DIR}ft_swap_list.c \
		${OPRERATOR_DIR}ft_rotate_list.c \
		${OPRERATOR_DIR}ft_reverse_rotate_list.c \
		${UTIL_DIR}ft_atoi.c \
		${UTIL_DIR}ft_lstlast.c \
		${UTIL_DIR}ft_lstnew.c \
		${UTIL_DIR}ft_lstsize.c \
		${UTIL_DIR}ft_lstclear.c \
		${UTIL_DIR}ft_putstr.c \
		${UTIL_DIR}ft_itoa.c \
		${UTIL_DIR}ft_strlen.c \
		${UTIL_DIR}ft_get_bigger.c \
		${UTIL_DIR}ft_abs.c \
		${UTIL_DIR}ft_split.c \
		${UTIL_DIR}ft_substr.c
SRCS = ft_push_swap.c ft_check_error.c ft_get_rotate_count.c ft_sort.c ft_minor_sort.c ${SRCS_OPERATOR}
OBJS = ${SRCS:.c=.o}
RM = rm
RMFLAGS = -f

all : ${NAME}
${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
%.o : %.c
	${CC} ${CFLAGS}  -c -o $@ $^
clean :
	${RM} ${RMFLAGS} ${OBJS} 
fclean : clean
	${RM} ${RMFLAGS} ${NAME} 
re : fclean all
.PHONY : all clean fclean re