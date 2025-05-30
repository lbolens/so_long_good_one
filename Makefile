# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 12:29:42 by lbolens           #+#    #+#              #
#    Updated: 2025/05/30 14:24:09 by lbolens          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

SRC = game.c \
	  get_next_line_utils.c \
	  get_next_line.c \
	  init_images.c \
	  is_map_solvable.c \
	  is_rectangle.c \
	  is_synthax_good.c \
	  is_walls.c \
	  main.c \
	  movements.c \
	  parsing.c \
	  render.c \
	  utils.c \
	  destroy.c \
	  utils_bis.c \
	  utils_ter.c \
	  utils_quater.c \
	  utils_quinter.c \
	  flood_fill.c \
	  utils_sexies.c

SRC_BONUS = destroy_bonus.c \
			init_images_bonus.c \
			manage_hundreds_bonus.c \
			utils_bis_bonus.c \
			flood_fill_bonus.c \
			is_map_solvable_bonus.c \
			manage_tens_bonus.c \
			utils_bonus.c \
			game_bonus.c \
			is_rectangle_bonus.c \
			manage_units_bonus.c \
			utils_quater_bonus.c \
			get_next_line_bonus.c \
			is_synthax_good_bonus.c \
			movements_bonus.c \
			utils_quinter_bonus.c \
			get_next_line_utils_bonus.c \
			is_walls_bonus.c \
			parsing_bonus.c \
			utils_sexies_bonus.c \
			init_asteroids_bonus.c \
			main_bonus.c \
			render_bonus.c \
			utils_ter_bonus.c

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
CCFLAGS = -Wall -Wextra -Werror -Imlx
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
	
$(OBJ): %.o: %.c
	@CURRENT=$$(echo "$(SRC)" | tr ' ' '\n' | nl -v 1 | awk -v f="$<" '$$2==f {print $$1}'); \
	TOTAL=$$(echo "$(SRC)" | wc -w); \
	PERCENT=$$((100 * $$CURRENT / $$TOTAL)); \
	BAR_LEN=20; \
	FILLED=$$((BAR_LEN * $$CURRENT / $$TOTAL)); \
	EMPTY=$$((BAR_LEN - $$FILLED)); \
	BAR=$$(printf "%*s" $$FILLED | tr ' ' '#'); \
	SPACE=$$(printf "%*s" $$EMPTY); \
	printf "\r[%s%s] %3d%% Compiling: %-20s" "$$BAR" "$$SPACE" "$$PERCENT" "$<"; \
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_BONUS): %.o: %.c
	@CURRENT=$$(echo "$(SRC_BONUS)" | tr ' ' '\n' | nl -v 1 | awk -v f="$<" '$$2==f {print $$1}'); \
	TOTAL=$$(echo "$(SRC_BONUS)" | wc -w); \
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
	@rm -f $(NAME)
	@echo "🧹 Fully cleaned project"

re: fclean all
