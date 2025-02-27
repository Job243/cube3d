NAME = cub3D

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

SRC = $(SRC_DIR)/parsing/check_map_utils.c $(SRC_DIR)/parsing/check_map.c \
		 $(SRC_DIR)/parsing/check_data.c  $(SRC_DIR)/ft_error.c  \
		  $(SRC_DIR)/main.c  $(SRC_DIR)/utils.c

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CC = gcc
FLAGS = -Wall -Wextra -Werror -g3 -I$(LIBFT_DIR) -I$(MLX_DIR) -I/usr/include

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJ) $(MLX_LIB)
	$(CC) $(OBJ) $(LIBFT) -o $@ $(FLAGS) -lreadline -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@) # Crée les sous-dossiers nécessaires
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	echo "\033[1;31m======== object files removed ========\033[0m"

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	echo "\033[1;31m======= executable removed =======\033[0m"

re: fclean all

.PHONY: all clean fclean re
