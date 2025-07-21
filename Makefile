# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 16:43:26 by ofilloux          #+#    #+#              #
#    Updated: 2025/07/21 19:30:08 by ofilloux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#     _____    ____    _         ____    _____     _____
#    / ____|  / __ \  | |       / __ \  |  __ \   / ____|
#   | |      | |  | | | |      | |  | | | |__) | | (___
#   | |      | |  | | | |      | |  | | |  _  /   \___ \
#   | |____  | |__| | | |____  | |__| | | | \ \   ____) |
#    \_____|  \____/  |______|  \____/  |_|  \_\ |_____/
#
GREEN	=	\e[1;92m
RED		=	\e[1;91m
DEFAULT	=	\e[0m
YELLOW	=	\e[1;33m


#   __      __             _____    _____              ____    _        ______    _____
#   \ \    / /     /\     |  __ \  |_   _|     /\     |  _ \  | |      |  ____|  / ____|
#    \ \  / /     /  \    | |__) |   | |      /  \    | |_) | | |      | |__    | (___
#     \ \/ /     / /\ \   |  _  /    | |     / /\ \   |  _ <  | |      |  __|    \___ \
#      \  /     / ____ \  | | \ \   _| |_   / ____ \  | |_) | | |____  | |____   ____) |
#       \/     /_/    \_\ |_|  \_\ |_____| /_/    \_\ |____/  |______| |______| |_____/
#
NAME	=	cub3D

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror #$(INC) $(LNK_FLAGS)
DEBUG	=	-g -O0

MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LNK_FLAGS	=-lm $(MLX_FLAGS)

INC 	=	-I./headers -I./libs/libft


#   ////////////////// SOURCES FILES //////////////////
SIGNALS	=	src/signals/signal_main.c

EXEC	=	src/exec/run_game_main_loop.c

PARSING	=	src/parsing/parse_map.c

UTILS	=	utils/frees/free_resources.c \
			utils/init/initialize_structures.c

SRC		=	main.c \
			$(SIGNALS) \
			$(UTILS) \
			$(PARSING) \
			$(EXEC)


#     ____    ____         _   ______    _____   _______    _____
#    / __ \  |  _ \       | | |  ____|  / ____| |__   __|  / ____|
#   | |  | | | |_) |      | | | |__    | |         | |    | (___
#   | |  | | |  _ <   _   | | |  __|   | |         | |     \___ \
#   | |__| | | |_) | | |__| | | |____  | |____     | |     ____) |
#    \____/  |____/   \____/  |______|  \_____|    |_|    |_____/
#
#////////////////// MLX && LIBS//////////////////
LIB_DIR =	libs

MLX_DIR	=	$(LIB_DIR)/minilibx
MLX		=	$(MLX_DIR)/libmlx.a
MLX_OBJ	=	$(MLX_DIR:.c=.o) #### TO CONFIRM ####

#### OBJ ####
BUILD_DIR	=	build
OBJ			=	$(SRC:%.c=$(BUILD_DIR)/%.o)

LIBFT_PATH	=	./libs/libft/libft.a
LIBFT_OBJ	:=	$(patsubst %.c,%.o,$(wildcard ./libs/libft/build/*.c))


#    ______  _____  _       ______      _______         _____    _____  ______  _______  _____
#   |  ____||_   _|| |     |  ____|    |__   __| /\    |  __ \  / ____||  ____||__   __|/ ____|
#   | |__     | |  | |     | |__          | |   /  \   | |__) || |  __ | |__      | |  | (___
#   |  __|    | |  | |     |  __|         | |  / /\ \  |  _  / | | |_ ||  __|     | |   \___ \
#   | |      _| |_ | |____ | |____        | | / ____ \ | | \ \ | |__| || |____    | |   ____) |
#   |_|     |_____||______||______|       |_|/_/    \_\|_|  \_\ \_____||______|   |_|  |_____/
#
$(BUILD_DIR)/%.o	:	%.c Makefile
						@mkdir -p $(dir $@)
						@printf "$(YELLOW)[cub3D] Compiling $< ...$(DEFAULT)                  \r"
						@$(CC) $(CFLAGS) $(INC) $(LNK_FLAGS) $(DEBUG) -c $< -o $@

$(NAME) 			:	$(OBJ) $(LIBFT_PATH) $(MLX)
						@$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIBFT_PATH) $(INC) $(LNK_FLAGS) -o $@
						@printf "\n$(GREEN)[cub3D] Compiled successfully.$(DEFAULT)\n"

$(LIBFT_PATH)		:	$(LIBFT_OBJ)
						@$(MAKE) -C ./libs/libft
						@printf "\n$(GREEN)[cub3D] libft compiled successfully.$(DEFAULT)\n" > /dev/null

$(MLX)				:	$(MLX_OBJ)
						make -C $(MLX_DIR) all

#    _____   _    _   ____   _   _ __     __    _______         _____    _____  ______  _______  _____
#   |  __ \ | |  | | / __ \ | \ | |\ \   / /   |__   __| /\    |  __ \  / ____||  ____||__   __|/ ____|
#   | |__) || |__| || |  | ||  \| | \ \_/ /       | |   /  \   | |__) || |  __ | |__      | |  | (___
#   |  ___/ |  __  || |  | || . ` |  \   /        | |  / /\ \  |  _  / | | |_ ||  __|     | |   \___ \
#   | |     | |  | || |__| || |\  |   | |         | | / ____ \ | | \ \ | |__| || |____    | |   ____) |
#   |_|     |_|  |_| \____/ |_| \_|   |_|         |_|/_/    \_\|_|  \_\ \_____||______|   |_|  |_____/
#
.PHONY: all clean fclean re
.DEFAULT_GOAL = all

all		:	$(NAME)

clean	:
			@make -s clean -C ./libs/libft
			@make -C $(MLX_DIR) clean
			@rm -rf $(BUILD_DIR)
			@printf "$(RED)[minishell] Object files cleaned.$(DEFAULT)\n"

fclean	:	clean
			@make -s fclean -C ./libs/libft
			@rm -f $(NAME)
			@printf "$(RED)[minishell] Cleaned successfully.$(DEFAULT)\n"

re		:	fclean all

test	:	$(NAME)
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./cub3D
