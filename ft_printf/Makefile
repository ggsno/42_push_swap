# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: go <go@student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 16:46:29 by go                #+#    #+#              #
#    Updated: 2022/05/02 16:39:20 by go               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_print_addr_hex.c ft_putchar.c \
	ft_putnbr_base.c ft_putnbr.c ft_putstr.c \
	ft_putunsignednbr.c ft_strlen.c
OBJS = $(SRCS:.c=.o)
RM = rm
RMFLAGS = -f
AR = ar
ARFLAGS = crs

all : $(NAME)
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
%.o : %.c
	$(CC) $(CFLAGS) -c $^
clean :
	$(RM) $(RMFLAGS) $(OBJS)
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
re : fclean all
.PHONY : all clean fclean re
