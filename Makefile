# Nom de l'exécutable
NAME := fractol

# Sources
SRCS := fractol.c utils.c zoom.c

# Objets
OBJS := $(SRCS:.c=.o)

# Compilation
CC := cc 
CFLAGS := -Wall -Wextra -Werror

# MiniLibX
MLX_DIR := minilibx-linux
MLX_LIB := $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS := -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Règles
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
