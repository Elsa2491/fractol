NAME = fractol
BONUS_NAME = fractol_bonus
MLX = ./minilibx-linux/libmlx.a
PRINTF = ./printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS_PATH = srcs/
OBJS_PATH = objs/
BONUS_SRCS_PATH = bonus/srcs/
BONUS_OBJS_PATH = bonus/objs/

SRCS = main.c handle_error.c maths_functions.c fractal.c \
	pixels_functions.c events_function.c events_messages.c \
	help_messages.c error_messages.c pattern_messages.c \
	init_structures.c check_params.c \

BONUS_SRCS = main_bonus.c handle_error_bonus.c maths_functions_bonus.c fractal_bonus.c \
	pixels_functions_bonus.c events_function_bonus.c events_messages_bonus.c \
	help_messages_bonus.c error_messages_bonus.c pattern_messages_bonus.c \
	keyboard_messages_bonus.c init_structures_bonus.c check_params_bonus.c \

OBJ = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
BONUS_OBJ = $(addprefix $(BONUS_OBJS_PATH), $(BONUS_SRCS:.c=.o))

all: $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(BONUS_OBJS_PATH):
	@mkdir -p $(BONUS_OBJS_PATH)


$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	cc $(CFLAGS) -c $< -o $@

$(BONUS_OBJS_PATH)%.o: $(BONUS_SRCS_PATH)%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS_PATH) $(OBJ)
	@echo "\nCompilation mandatory part: success\n"
	make -C "./minilibx-linux" && make -C "./printf"
	cc $(CFLAGS) $(OBJ) -Inc $(PRINTF) -Inc $(MLX) -Lminilibx-linux -lX11 -lXext -o $(NAME)
	@echo "\nCompilation minilibx: success\n"
	@echo "\nCompilation finished!\n"

bonus: $(BONUS_OBJS_PATH) $(BONUS_OBJ)
#	make -C "./minilibx-linux" && make -C "./printf"
	cc $(CFLAGS) $(BONUS_OBJ) -Inc $(PRINTF) -Inc $(MLX) -Lminilibx-linux -lX11 -lXext -o $(BONUS_NAME) 

clean:
	/bin/rm -rf $(OBJ)
	/bin/rm -rf $(OBJS_PATH)
	@echo "\nMandatory files objects and associated directories removed\n"
	/bin/rm -rf $(BONUS_OBJ)
	/bin/rm -rf $(BONUS_OBJS_PATH)
	@echo "\nBonus files objects and associated directories removed\n"

fclean: clean
	/bin/rm -rf $(NAME) $(BONUS_NAME)
	@echo "\nfractol destroyed\n"

re: fclean all

.PHONY: all clean fclean re bonus
