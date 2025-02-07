NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c\
		ft_printf_utils.c\
		ft_number.c\
		ft_printf_string.c\
		ft_unsi_number.c\

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
