
NAME 			= cube3D

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I$(INC_DIR)
MLX_FLAGS  		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRC_DIR			= ./src
INC_DIR 		= ./inc
LIB_DIR 		= ./lib
MLX_DIR			= $(LIB_DIR)/minilibx
LIBFT_DIR		= $(LIB_DIR)/libft

MLX				= $(MLX_DIR)/libmlx.a
LIBFT			= $(LIBFT_DIR)/libft.a
LIBS 			= $(LIBFT) $(MLX)

SRC_FILES		= $(wildcard $(SRC_DIR)/*.c)
			
OBJS 			= $(SRC_FILES:.c=.o)


all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR) all


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:

	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft