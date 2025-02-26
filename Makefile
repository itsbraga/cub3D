#******************************************************************************#
#	FEATURES
#******************************************************************************#

RESET		:=	\033[0m
BOLD		:=	\033[1m
ITAL		:=	\033[3m
BLINK		:=	\033[5m
GREEN		:=	\033[32m
YELLOW		:=	\033[33m
BLUE		:=	\033[34m
CYAN		:=	\033[36m
PINK		:=	\033[38;2;255;182;193m

#******************************************************************************#
#	BASE
#******************************************************************************#

LIBFT_DIR	=	LIBFT/
LIBFT		=	$(addprefix $(LIBFT_DIR), libft.a)
MLX_DIR		=	mlx/
MLX			=	$(addprefix $(MLX_DIR), libmlx.a)

HEADERS		=	includes/

CFLAGS		=	-Wall -Wextra -Werror
LFLAGS		=	-L $(LIBFT_DIR) -lft
MLXFLAGS	=	-L $(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm
DEPFLAGS	=	-MMD -MP

DEBUG		=	-O3 -g3 #-0fast

#******************************************************************************#
#	MANDATORY
#******************************************************************************#

NAME		=	cub3D

TOOLS_DIR	=	tools/
TOOLS_F		=	error_msg.c secure.c cleanup.c pixels.c draw_tools.c

GARBAGE_DIR	=	tools/garbage_collector/
GARBAGE_F	=	garbage_collector.c gc_utils.c lst_utils.c

PARSING_DIR	=	parsing/
PARSING_F	=	check_map.c check_map2.c check_cub_file.c check_rgb.c

CONFIG_DIR	=	configs/mlx_hooks/
CONFIG_F	=	movements.c camera.c move_tab.c hooks.c mlx_exit.c

MATHS_DIR	=	maths/
MATHS_F		=	draw_line.c formulas.c raycasting.c

INIT_DIR	=	init/
INIT_F		=	singletons.c init_structs.c

EXEC_DIR	=	exec/
EXEC_F		=	map_info.c render.c

# REMOVE WHEN THE PROJECT WILL BE FINISHED! #
DEBUG_DIR	=	tools/2D_debug/
DEBUG_F		=	debug.c draw_line.c draw_grid.c draw_player.c

SRCS_DIR	=	mandatory/
SRCS_F		=	$(addprefix $(TOOLS_DIR), $(TOOLS_F)) $(addprefix $(GARBAGE_DIR), $(GARBAGE_F)) \
				$(addprefix $(DEBUG_DIR), $(DEBUG_F)) $(addprefix $(PARSING_DIR), $(PARSING_F)) \
				$(addprefix $(CONFIG_DIR), $(CONFIG_F)) $(addprefix $(MATHS_DIR), $(MATHS_F)) \
				$(addprefix $(INIT_DIR), $(INIT_F)) $(addprefix $(EXEC_DIR), $(EXEC_F)) \
				main.c

OBJS_DIR	=	objs/
OBJS_F		=	$(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS_F))

DEPS_MANDAT	=	$(patsubst %.c,$(OBJS_DIR)%.d,$(SRCS_F))

#******************************************************************************#
#	BONUS
#******************************************************************************#

NAME_BONUS		=	cub3D_bonus

B_TOOLS_DIR		=	tools/
B_TOOLS_F		=	error_msg.c secure.c cleanup.c pixels.c draw_tools.c

B_GARBAGE_DIR	=	tools/garbage_collector/
B_GARBAGE_F		=	garbage_collector.c gc_utils.c lst_utils.c

B_PARSING_DIR	=	parsing/
B_PARSING_F		=	check_map.c check_map2.c check_cub_file.c check_rgb.c

B_CONFIG_DIR	=	configs/mlx_hooks/
B_CONFIG_F		=	movements.c camera.c move_tab.c hooks.c mlx_exit.c

B_MATHS_DIR		=	maths/
B_MATHS_F		=	draw_line.c formulas.c raycasting.c

B_INIT_DIR		=	init/
B_INIT_F		=	singletons.c init_structs.c init.c

B_EXEC_DIR		=	exec/
B_EXEC_F		=	map_info.c render.c

B_START_DIR		=	start_screen/
B_START_F		=	start_screen.c

MINIMAP_DIR		=	minimap/
MINIMAP_F		=	draw_miniline.c draw_miniplayer.c minimap.c

BONUS_SRCS_DIR	=	bonus/
BONUS_SRCS_F	=	$(addprefix $(B_TOOLS_DIR), $(B_TOOLS_F)) $(addprefix $(B_GARBAGE_DIR), $(B_GARBAGE_F)) \
					$(addprefix $(B_PARSING_DIR), $(B_PARSING_F)) $(addprefix $(B_CONFIG_DIR), $(B_CONFIG_F)) \
					$(addprefix $(B_MATHS_DIR), $(B_MATHS_F)) $(addprefix $(B_INIT_DIR), $(B_INIT_F)) \
					$(addprefix $(B_EXEC_DIR), $(B_EXEC_F)) $(addprefix $(B_START_DIR), $(B_START_F)) \
					$(addprefix $(MINIMAP_DIR), $(MINIMAP_F)) \
					collisions.c main.c

BONUS_OBJS_DIR	=	bonus_objs/
BONUS_OBJS_F	=	$(patsubst %.c,$(BONUS_OBJS_DIR)%.o,$(BONUS_SRCS_F))

DEPS_BONUS		=	$(patsubst %.c,$(BONUS_OBJS_DIR)%.d,$(BONUS_SRCS_F))

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(LIBFT) $(MLX) $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(GREEN)Compiled: $(RESET)$(ITAL)$<                                  \n"
				@cc $(DEPFLAGS) $(CFLAGS) -I $(HEADERS) -I/usr/include -I $(MLX_DIR) -c $< -o $@
-include $(DEPS_MANDAT)

$(LIBFT):
		@make --no-print-directory -sC $(LIBFT_DIR)

$(MLX):
		@make --no-print-directory -sC $(MLX_DIR)

$(NAME): $(OBJS_F) $(LIBFT) $(MLX)
			@printf "\n\n================= CUB3D =================\n\n"
			@printf "$(BLINK)$(GREEN)\t\t  READY!$(RESET)\n\n"
			@printf "$(BOLD)=========================================\n\n$(RESET)"
			@cc $(CFLAGS) -I $(HEADERS) $(OBJS_F) $(LFLAGS) $(MLXFLAGS) -o $(NAME)

bonus: $(LIBFT) $(MLX) $(NAME_BONUS)

$(BONUS_OBJS_DIR)%.o: $(BONUS_SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(GREEN)Compiled: $(RESET)$(ITAL)$<                                  \n"
				@cc $(DEPFLAGS) $(CFLAGS) -I $(HEADERS) -I/usr/include -I $(MLX_DIR) -c $< -o $@
-include $(DEPS_BONUS)

$(NAME_BONUS): $(BONUS_OBJS_F) $(LIBFT) $(MLX)
			@printf "\n\n================= CUB3D =================\n\n"
			@printf "$(BLINK)$(GREEN)\t\tBONUS READY!$(RESET)\n\n"
			@printf "$(BOLD)=========================================\n\n$(RESET)"
			@cc $(CFLAGS) -I $(HEADERS) $(BONUS_OBJS_F) $(LFLAGS) $(MLXFLAGS) -o $(NAME_BONUS)

clean:
		@rm -rf $(OBJS_DIR) $(BONUS_OBJS_DIR)
		@make --no-print-directory clean -sC $(MLX_DIR)
		@make --no-print-directory clean -sC $(LIBFT_DIR)
		@printf "\n$(BOLD)$(BLUE)[objects]:\t$(RESET)Removed!\n"

fclean: clean
			@rm -rf $(NAME) $(NAME_BONUS)
			@rm -rf $(LIBFT) $(MLX)
			@printf "$(BOLD)$(CYAN)[executables]:\t$(RESET)Removed!\n\n\n"

re:	fclean all
		@printf "\n$(BOLD)$(YELLOW)make re: $(RESET)All files have been rebuilt! ✨\n\n"

.PHONY:	all clean fclean bonus re