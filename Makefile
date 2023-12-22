NAME = fractol
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c handle_error.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	cc $(CFLAGS) $(OBJS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	/bin/rm -rf $(OBJS)


fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
