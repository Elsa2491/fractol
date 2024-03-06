#################################################################################
#																				#
#				      				COLORS										#
#																				#
#################################################################################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM			:=	\e[2m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

BLACK		:=	\e[30m
GRAY		:=	\e[90m
RED			:=	\e[31m
GREEN		:=	\e[32m
YELLOW		:=	\e[33m
ORANGE		:=	\e[38;5;208m
BLUE		:=	\e[34m
PURPLE		:=	\e[35m
PINK		:=	\033[38;2;255;182;193m
CYAN		:=	\e[36m

BRIGHT_BLACK	:=	\e[90m
BRIGHT_GREEN	:=	\e[92m
BRIGHT_YELLOW	:=	\e[93m
BRIGHT_BLUE		:=	\e[94m
BRIGHT_PURPLE	:=	\e[95m
BRIGHT_CYAN		:=	\e[96m

# define rainbow
# $(shell echo $(1) | sed -e "s/./\$(shell printf '\033[38;5;%dm' \$$(shell expr \( \$$(od -An -N1 -tu1 /dev/urandom) \% 6 + 196))&) /g")
# endef

# COLORED_TEXT	:= $(call (rainbow))


#################################################################################
#																				#
#				    				BASICS										#
#																				#
#################################################################################

NAME		=	fractol
# NAME_BONUS	=	fractol_bonus

LIBFT_PATH	=	./printf/libftprintf.a
MLX_PATH	=	./minilibx-linux/libmlx.a

CC			=	cc

MAKEFLAGS	+=	--no-print-directory
MLXFLAGS	=	-Lminilibx-linux -lX11 -lXext
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf


#################################################################################
#																				#
#				    				SOURCES										#
#																				#
#################################################################################



#################################################################################
#																				#
#								COMBINE FILES									#
#				    				and											#
#								DIRECTORIES										#
#									  											#
#################################################################################
SRCS_PATH = srcs/
OBJS_PATH = objs/

SRCS = main.c handle_error.c maths_functions.c fractal.c \
        pixels_functions.c events_function.c events_messages.c \
        help_messages.c error_messages.c pattern_messages.c \
        init_structures.c check_params.c \

OBJ = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

#############################	  BONUS PART	#################################

# BONUS_SRC_DIR	=	bonus/

# OBJ_B_DIR		=	obj_bonus/


#################################################################################
#																				#
#								DEPENDENCIES									#
#																				#
#################################################################################


#################################################################################
#																				#
#				     				RULES										#
#																				#
#################################################################################

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<          \r"
				@$(CC)  $(CFLAGS) -c $< -o $@

# @printf "\n\n"
# @if [ ! -f .build ]; then \
# 	printf "\t\t\t%s\n" \
			# 	"──▒▒▒▒▒▒───▄████▄" \
			# 	"─▒─▄▒─▄▒──███▄█▀" \
			# 	"─▒▒▒▒▒▒▒─▐████──█─█" \
			# 	"─▒▒▒▒▒▒▒──█████▄" \
			# 	"─▒─▒─▒─▒───▀████▀"; \
			# 	printf "\n\n"; \
			# 	touch .build; fi

# links .o files to libraries, constructs the necessary dependencies and do ASCII art
$(NAME): $(OBJ)
			make --no-print-directory -C "./minilibx-linux" && make -C "./printf"
			@cc $(CFLAGS) $(OBJ) -Inc $(LIBFT_PATH) -Inc $(MLX_PATH) -Lminilibx-linux -lX11 -lXext -o $(NAME)
#			@$(CC) $(CFLAGS) $(OBJS) -Inc $(LIBFT_X) -Inc $(MLX_X) $(MLXFLAGS) -o $(NAME)
			@printf "\n$(BOLD)$(PINK). ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .$(RESET)\n\n\n"
			@printf "$(BOLD)[Mandatory]: $(GREEN)Compilation done!$(RESET)\n\n"
			@printf "\n\n$(RESET)$(BOLD)$(BLUE)[fract-ol]:\t$(RESET)"
			@printf "$(BLUE)./fractol ready to draw fractals $(RESET)🌈\n\n"

all:	$(NAME)

clean:
		@$(RM) $(OBJs_PATH)
		@printf "\n$(BOLD)$(GREEN)[objs]:\t\t$(RESET)Clean completed\n"

fclean: clean
			@$(RM) $(NAME)
			@$(RM) libmlx.a libft.a
			@find . -name ".build" -delete
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(BLUE)[execs]:\t$(RESET)Full clean completed!\n\n"
			@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n\n"

re:		fclean all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n\n"

diff:
		$(info Repository's status, and the volume of per-file changes:)
		@printf "$(RESET)\n\n"
		@git status
		@git diff --stat


#################################################################################
#																				#
#				     				BONUS										#
#																				#
#################################################################################

# $(NAME_BONUS): $(OBJS_BONUS)
# 			@printf "\n\n$(RESET)$(BOLD)$(CYAN)[FRACT-OL BONUS]:\t$(RESET)"
# 			@$(CC) $(CFLAGS) $(INC) $(OBJS_BONUS) libft.a -o $(CHECKER)
# 			@printf "$(CYAN) ./? ready to launch !$(RESET)\n\n"

# $(OBJ_B_DIR)%.o: $(BONUS_SRC_DIR)%.c
# 			@mkdir -p $(dir $@)
# 			@printf "$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<                  \r"
# 			@$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INC) -c $< -o $@

# -include $(BONUS_DEP_NAMES)

# bonus:
# 		@make -sC $(MLX_PATH) $(MAKEFLAGS)
# 		@make -sC $(LIBFT_PATH) $(MAKEFLAGS)
# 		@cp $(MLX_PATH)/libmlx.a .
# 		@cp $(LIBFT) .
#		@make $(NAME_BONUS)
# 		@printf "\n\n✨ $(BOLD)$(YELLOW)Bonuses successfully compiled! $(RESET)✨\n"


.PHONY:		build all clean fclean re diff norm
