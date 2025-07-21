# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 14:49:42 by lylfergu          #+#    #+#              #
#    Updated: 2025/02/14 16:11:39 by lylfergu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar -rc

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_check_type.c ft_print_char.c ft_print_digit.c ft_printf.c\
ft_print_hexa.c ft_print_pointer.c ft_print_str.c get_next_line.c\
get_next_line_utils.c

OBJ = $(SRC:.c=.o)

INCLUDE = libft.h ft_printf.h get_next_line.h

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c Makefile $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
