NAME := fractol

PRINTF := libftprintf.a

SRCS := $(wildcard *.c) \
		$(wildcard fractal/*.c) \
		$(wildcard keypress/*.c) \
		$(wildcard init/*.c)


OBJS := $(SRCS:.c=.o)

CC := cc 
CFLAGS := -Wall -Wextra -Werror -g

MLX_DIR := minilibx-linux
MLX_LIB := $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS := -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
PRINTF_DIR := ft_printf

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) $(PRINTF)

$(PRINTF): 
	$(make) -C ft_printf
	cp ft_printf/libftprintf.a ./ 

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(PRINTF)

re: fclean all

.PHONY: all clean fclean re
