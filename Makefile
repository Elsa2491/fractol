NAME = fractol
MLX = ./minilibx-linux/libmlx.a
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c handle_error.c maths_functions.c fractal.c \
       pixels_functions.c events_function.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C "./minilibx-linux"
	cc $(CFLAGS) $(OBJS) -I/usr/include $(MLX) -Lminilibx-linux -lX11 -lXext -o $(NAME)

clean:
	/bin/rm -rf $(OBJS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
