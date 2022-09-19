# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: go <go@student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 15:44:06 by go                #+#    #+#              #
#    Updated: 2022/09/20 00:22:47 by go               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
	ft_lstmap.c ft_get_next_line.c ft_lstadd_back_gnl.c ft_strjoin_free_args.c\
	ft_printf.c ft_print_addr_hex.c ft_putchar.c\
	ft_putnbr_base.c ft_putnbr.c ft_putstr.c\
	ft_putunsignednbr.c
OBJS = $(SRCS:.c=.o)
RM = rm
RMFLAGS = -f
AR = ar
ARFLAGS = crs

all : $(NAME)
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -c $^
clean :
	$(RM) $(RMFLAGS) $(OBJS) 
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
re : fclean all
.PHONY : all clean fclean re
