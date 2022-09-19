# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: go <go@student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 22:37:19 by go                #+#    #+#              #
#    Updated: 2022/09/19 23:45:30 by go               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_push_swap.c ft_check_error.c
LIB = libftprintf.a
LIB_DIR = ./ft_printf
LIB_SRCS = ${addprefix ${LIB_DIR}/,ft_printf.c ft_print_addr_hex.c ft_putchar.c \
	ft_putnbr_base.c ft_putnbr.c ft_putstr.c \
	ft_putunsignednbr.c ft_strlen.c}
LIB_OBJS = ${LIB_SRCS:.c=.o}
RM = rm
RMFLAGS = -f
AR = ar
ARFLAGS = crs

all : ${NAME}
${NAME} : ${LIB} ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -L./ -lftprintf -o ${NAME}
${LIB} : ${LIB_OBJS}
	$(AR) $(ARFLAGS) $(LIB) $(LIB_OBJS)
%.o : ${LIB_DIR}/%.c
	$(CC) $(CFLAGS) -c $^
clean :
	${RM} ${RMFLAGS} ${LIB_OBJS}
fclean : clean
	${RM} ${RMFLAGS} ${NAME} ${LIB}
re : fclean all
.PHONY : all clean fclean re