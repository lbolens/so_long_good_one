# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 12:29:42 by lbolens           #+#    #+#              #
#    Updated: 2025/06/02 13:54:46 by lbolens          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

FT_PRINTF = \
	printf/ft_printf.c \
	printf/ft_putchar_printf.c \
	printf/ft_put_hex_up.c \
	printf/ft_put_hex_low.c \
	printf/ft_put_pointer.c \
	printf/ft_put_unsigned_dec_10.c \
	printf/ft_putnbr_printf.c \
	printf/ft_putstr_printf.c

SRC = game/game.c \
	  gnl/get_next_line_utils.c \
	  gnl/get_next_line.c \
	  game/init_images.c \
	  parsing/is_map_solvable.c \
	  parsing/is_rectangle.c \
	  parsing/is_synthax_good.c \
	  parsing/is_walls.c \
	  game/main.c \
	  game/movements.c \
	  parsing/parsing.c \
	  game/render.c \
	  utils/utils.c \
	  game/destroy.c \
	  utils/utils_bis.c \
	  utils/utils_ter.c \
	  utils/utils_quater.c \
	  utils/utils_quinter.c \
	  game/flood_fill.c \
	  utils/utils_sexies.c \
	  $(FT_PRINTF)
	  
SRC_BONUS = bonus/game/destroy_bonus.c \
			bonus/game/init_images_bonus.c \
			bonus/game/manage_hundreds_bonus.c \
			bonus/utils/utils_bis_bonus.c \
			bonus/game/flood_fill_bonus.c \
			bonus/parsing/is_map_solvable_bonus.c \
			bonus/game/manage_tens_bonus.c \
			bonus/utils/utils_bonus.c \
			bonus/game/game_bonus.c \
			bonus/parsing/is_rectangle_bonus.c \
			bonus/game/manage_units_bonus.c \
			bonus/utils/utils_quater_bonus.c \
			bonus/gnl/get_next_line_bonus.c \
			bonus/parsing/is_synthax_good_bonus.c \
			bonus/game/movements_bonus.c \
			bonus/utils/utils_quinter_bonus.c \
			bonus/gnl/get_next_line_utils_bonus.c \
			bonus/parsing/is_walls_bonus.c \
			bonus/parsing/parsing_bonus.c \
			bonus/utils/utils_sexies_bonus.c \
			bonus/game/init_asteroids_bonus.c \
			bonus/game/main_bonus.c \
			bonus/game/render_bonus.c \
			bonus/utils/utils_ter_bonus.c \
			bonus/game/check_images.c \
			$(FT_PRINTF)
			
define ASCII_ART
	@echo ""
	@echo "         /\    \                 /::\    \                 /\    \   /::\    \                 /\    \                  /\    \            "
	@echo "	/::\    \               /::::\    \               /::\    \ /::::\    \               /::\    \                /::\    \           "
	@echo "       /::::\    \             /::::::\    \             /:::/    //::::::\    \             /::::|   |               /::::\    \           "
	@echo "      /::::::\    \           /::::::::\    \           /:::/    //::::::::\    \           /:::::|   |              /::::::\    \      "
	@echo "     /:::/\:::\    \         /:::/~~\:::\    \         /:::/    //:::/~~\:::\    \         /::::::|   |             /:::/\:::\    \     "
	@echo "    /:::/  \:::\    \       /:::/    \:::\    \       /:::/    //:::/    \:::\    \       /:::/|::|   |            /:::/  \:::\    \    "
	@echo "    \:::\   \:::\    \     /:::/    / \:::\    \     /:::/    //:::/    / \:::\    \     /:::/ |::|   |           /:::/    \:::\    \   "
	@echo "     \:::\   \:::\    \   /:::/    /   \:::\    \   /:::/    //:::/    /   \:::\    \   /:::/  |::|   |          /:::/    / \:::\    \  "
	@echo " /\   \:::\   \:::\    \ |:::|    |     |:::|    | /:::/    /|:::|    |     |:::|    | /:::/   |::|   |/\    \  /:::/    /   \:::\    \ "
	@echo "/::\   \:::\   \:::\____\|:::|    |     |:::|    |/:::/    / |:::|    |     |:::|    |/:: /    |::|   /::\    \/:::/    /     \:::|    |"
	@echo "\:::\   \:::\   \::/    / \:::\    \   /:::/    / \:::\    \  \:::\    \   /:::/    / \::/    /|::|  /:::/    /\:::\    \ /\  /:::|    |"
	@echo " \:::\   \:::\   \/____/   \:::\    \ /:::/    /   \:::\    \  \:::\    \ /:::/    /   \/    / |::| /:::/    /  \:::\    /::\ \::/    / "
	@echo "  \:::\   \:::\    \        \:::\    /:::/    /     \:::\    \  \:::\    /:::/    /            |::|/:::/    /    \:::\   \:::\ \/    /  "
	@echo "   \:::\   \:::\    \        \:::\  /:::/    /       \:::\    \  \:::\  /:::/    /             |::::::/    /      \:::\   \:::\    \    "
	@echo "    \:::\  /:::/    /         \::::::::/    /         \:::\    \  \::::::::/    /              |:::::/    /        \:::\  /:::/    /    "
	@echo "     \:::\/:::/    /           \::::::/    /           \:::\    \  \::::::/    /               |::::/    /          \:::\/:::/    /     "
	@echo "      \::::::/    /             \::::/    /             \:::\    \  \::::/    /                /:::/    /            \::::::/    /      "
	@echo "       \::::/    /               \::/____/               \:::\    \  \::/____/                /:::/    /              \::::/    /       "
	@echo "        \::/    /                                         \::/    /                           \::/    /                \::/____/        "
	@echo "         \/____/                                           \/____/                             \/____/                                  "
	@echo ""
endef


OBJ := $(SRC:%.c=%.o)
OBJ_BONUS := $(SRC_BONUS:%.c=%.o)

CC = gcc
CCFLAGS = -Wall -Wextra -Werror -Imlx -Iprintf
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
	MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
else
	MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm
endif

TOTAL := $(words $(SRC))
COUNT = 0

all: $(NAME)

$(NAME): $(OBJ)
	$(ASCII_ART)
	@make -C mlx --no-print-directory > /dev/null 2>&1
	@echo ""
	@$(CC) $(CCFLAGS) $^ $(MLX_FLAGS) -o $@
	@echo "✅ Build complete"

bonus: $(OBJ_BONUS)
	$(ASCII_ART)
	@echo "🔧 Compiling BONUS version..."
	@make -C mlx --no-print-directory > /dev/null 2>&1
	@$(CC) $(CCFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "🎯 Build complete"
	
%.o: %.c
	@CURRENT=$$(echo "$(SRC) $(SRC_BONUS)" | tr ' ' '\n' | nl -v 1 | awk -v f="$<" 'BEGIN{n=0} $$2==f{n=$$1} END{print n}'); \
	TOTAL=$$(echo "$(SRC) $(SRC_BONUS)" | wc -w); \
	PERCENT=$$((100 * $$CURRENT / $$TOTAL)); \
	BAR_LEN=20; \
	FILLED=$$((BAR_LEN * $$CURRENT / $$TOTAL)); \
	EMPTY=$$((BAR_LEN - $$FILLED)); \
	BAR=$$(printf "%*s" $$FILLED | tr ' ' '#'); \
	SPACE=$$(printf "%*s" $$EMPTY); \
	printf "\r[%s%s] %3d%% Compiling: %-20s" "$$BAR" "$$SPACE" "$$PERCENT" "$<"; \
	$(CC) $(CCFLAGS) -c $< -o $@
	
clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@echo "🧹 Cleaned object files"

fclean: clean
	@make clean -C mlx > /dev/null
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "🧹 Fully cleaned project"

re: fclean all
