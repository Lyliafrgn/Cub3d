# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/14 18:35:56 by sarodrig          #+#    #+#              #
#    Updated: 2025/06/18 17:44:01 by ofilloux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#     _____    ____    _         ____    _____     _____
#    / ____|  / __ \  | |       / __ \  |  __ \   / ____|
#   | |      | |  | | | |      | |  | | | |__) | | (___
#   | |      | |  | | | |      | |  | | |  _  /   \___ \
#   | |____  | |__| | | |____  | |__| | | | \ \   ____) |
#    \_____|  \____/  |______|  \____/  |_|  \_\ |_____/
#
GREEN		=	\e[1;92m
RED			=	\e[1;91m
DEFAULT		=	\e[0m
YELLOW		=	\e[1;33m

#   __      __             _____    _____              ____    _        ______    _____
#   \ \    / /     /\     |  __ \  |_   _|     /\     |  _ \  | |      |  ____|  / ____|
#    \ \  / /     /  \    | |__) |   | |      /  \    | |_) | | |      | |__    | (___
#     \ \/ /     / /\ \   |  _  /    | |     / /\ \   |  _ <  | |      |  __|    \___ \
#      \  /     / ____ \  | | \ \   _| |_   / ____ \  | |_) | | |____  | |____   ____) |
#       \/     /_/    \_\ |_|  \_\ |_____| /_/    \_\ |____/  |______| |______| |_____/
#
FLAGS		=	-Wall -Werror -Wextra

NAME		=	libft.a

BONUS_SRC 	=	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

SRC			=	./ft_atoi.c \
				./ft_bzero.c \
				./ft_calloc.c \
				./ft_isalnum.c \
				./ft_isalpha.c \
				./ft_isascii.c \
				./ft_isdigit.c \
				./ft_isprint.c \
				./ft_itoa.c \
				./ft_memchr.c \
				./ft_memcmp.c \
				./ft_memcpy.c \
				./ft_memmove.c \
				./ft_memset.c \
				./ft_putchar_fd.c \
				./ft_putendl_fd.c \
				./ft_putnbr_fd.c \
				./ft_putstr_fd.c \
				./ft_split.c \
				./ft_strchr.c \
				./ft_strdup.c \
				./ft_striteri.c \
				./ft_strjoin.c \
				./ft_strlcat.c \
				./ft_strlcpy.c \
				./ft_strlen.c \
				./ft_strmapi.c \
				./ft_strcmp.c	ft_strncmp.c \
				./ft_strnstr.c \
				./ft_strrchr.c \
				./ft_strtrim.c \
				./ft_substr.c \
				./ft_tolower.c \
				./ft_toupper.c # \
				$(BONUS_SRC)

#     ____    ____         _   ______    _____   _______    _____
#    / __ \  |  _ \       | | |  ____|  / ____| |__   __|  / ____|
#   | |  | | | |_) |      | | | |__    | |         | |    | (___
#   | |  | | |  _ <   _   | | |  __|   | |         | |     \___ \
#   | |__| | | |_) | | |__| | | |____  | |____     | |     ____) |
#    \____/  |____/   \____/  |______|  \_____|    |_|    |_____/
#
BUILD_DIR	=	./build
OBJ			=	$(SRC:%.c=$(BUILD_DIR)/%.o)

OBJ_BONUS	=	$(BONUS_SRC:.c=.o)

#    ______  _____  _       ______      _______         _____    _____  ______  _______  _____
#   |  ____||_   _|| |     |  ____|    |__   __| /\    |  __ \  / ____||  ____||__   __|/ ____|
#   | |__     | |  | |     | |__          | |   /  \   | |__) || |  __ | |__      | |  | (___
#   |  __|    | |  | |     |  __|         | |  / /\ \  |  _  / | | |_ ||  __|     | |   \___ \
#   | |      _| |_ | |____ | |____        | | / ____ \ | | \ \ | |__| || |____    | |   ____) |
#   |_|     |_____||______||______|       |_|/_/    \_\|_|  \_\ \_____||______|   |_|  |_____/
#
$(BUILD_DIR)/%.o	:	%.c libft.h Makefile
						@mkdir -p $(dir $@)
						@printf "$(YELLOW)[libft] Compiling $<...$(DEFAULT)                  \r"
						@cc $(FLAGS) -c $< -o $@

$(NAME)				:	$(OBJ)
						@ar rcs $(NAME) $(OBJ)
						@ranlib $(NAME)
# ranlib Met à jour l'index (sommaire) de l'archive pour
# permettre au linker de trouver rapidement les symboles
# (fonctions/variables) lors de la compilation.
# plus rapide, plus robust

#    _____   _    _   ____   _   _ __     __    _______         _____    _____  ______  _______  _____
#   |  __ \ | |  | | / __ \ | \ | |\ \   / /   |__   __| /\    |  __ \  / ____||  ____||__   __|/ ____|
#   | |__) || |__| || |  | ||  \| | \ \_/ /       | |   /  \   | |__) || |  __ | |__      | |  | (___
#   |  ___/ |  __  || |  | || . ` |  \   /        | |  / /\ \  |  _  / | | |_ ||  __|     | |   \___ \
#   | |     | |  | || |__| || |\  |   | |         | | / ____ \ | | \ \ | |__| || |____    | |   ____) |
#   |_|     |_|  |_| \____/ |_| \_|   |_|         |_|/_/    \_\|_|  \_\ \_____||______|   |_|  |_____/
#
.PHONY: all, clean, fclean, re, bonus
.DEFAULT_GOAL = all

all		:	$(NAME)

bonus	:	${NAME} $(OBJ_BONUS)
			@ar rcs $(NAME) $(OBJ_BONUS)

clean	:
			@rm -rf $(BUILD_DIR)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all
