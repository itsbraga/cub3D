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
PURPLE		:=	\033[38;2;211;211;255m

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

define combine
$(addprefix $(1), $(2))
endef

#******************************************************************************#
#	MANDATORY
#******************************************************************************#

NAME		=	cub3D

TOOLS_DIR	=	tools/
TOOLS_F		=	error_msg.c secure.c cleanup.c draw_tools.c

GARBAGE_DIR	=	garbage_collector/
GARBAGE_F	=	garbage_collector.c gc_utils.c lst_utils.c

PARSING_DIR	=	parsing/
PARSING_F	=	check_map.c check_map2.c check_cub_file.c check_rgb.c

CONFIG_DIR	=	configs/mlx_hooks/
CONFIG_F	=	movements.c camera.c move_tab.c setter.c clean_exit.c

MATHS_DIR	=	maths/
MATHS_F		=	draw_line.c formulas.c raycasting.c

INIT_DIR	=	init/
INIT_F		=	singletons.c init_mlx.c init_structs.c generate_img.c

RENDER_DIR	=	render/
RENDER_F	=	pixels.c render.c

EXEC_DIR	=	exec/
EXEC_F		=	map_info.c #config.c

SRCS_DIR	=	mandatory/
SRCS_F		=	$(call combine, $(TOOLS_DIR), $(TOOLS_F)) \
				$(call combine, $(GARBAGE_DIR), $(GARBAGE_F)) \
				$(call combine, $(PARSING_DIR), $(PARSING_F)) \
				$(call combine, $(CONFIG_DIR), $(CONFIG_F)) \
				$(call combine, $(MATHS_DIR), $(MATHS_F)) \
				$(call combine, $(INIT_DIR), $(INIT_F)) \
				$(call combine, $(RENDER_DIR), $(RENDER_F)) \
				$(call combine, $(EXEC_DIR), $(EXEC_F)) \
				main.c

# SRCS_DIR	=	$(shell find mandatory -type d)
# SRCS_F		=	$(shell find mandatory -type f -name '*.c')
# vpath %.c $(SRCS_DIR)

OBJS_DIR	=	mandatory/objs/
OBJS_F		=	$(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS_F))

DEPS_MANDAT	=	$(patsubst %.c,$(OBJS_DIR)%.d,$(SRCS_F))

#******************************************************************************#
#	BONUS
#******************************************************************************#

NAME_BONUS		=	cub3D_bonus

B_TOOLS_DIR		=	tools/
B_TOOLS_F		=	error_msg.c secure.c cleanup.c draw_tools.c

B_GARBAGE_DIR	=	garbage_collector/
B_GARBAGE_F		=	garbage_collector.c gc_utils.c lst_utils.c

B_PARSING_DIR	=	parsing/
B_PARSING_F		=	check_map.c check_map2.c check_cub_file.c check_rgb.c

B_CONFIG_DIR	=	configs/mlx_hooks/
B_CONFIG_F		=	movements.c camera.c move_tab.c setter.c clean_exit.c

B_MATHS_DIR		=	maths/
B_MATHS_F		=	draw_line.c formulas.c raycasting.c

B_INIT_DIR		=	init/
B_INIT_F		=	singletons.c init_mlx.c init_structs.c title_screen.c

B_RENDER_DIR	=	render/
B_RENDER_F		=	pixels.c draw_player_pos.c minimap.c render.c \
					generate_img.c

B_EXEC_DIR		=	exec/
B_EXEC_F		=	map_info.c collisions.c #config.c

BONUS_SRCS_DIR	=	bonus/
BONUS_SRCS_F	=	$(call combine, $(B_TOOLS_DIR), $(B_TOOLS_F)) \
					$(call combine, $(B_GARBAGE_DIR), $(B_GARBAGE_F)) \
					$(call combine, $(B_PARSING_DIR), $(B_PARSING_F)) \
					$(call combine, $(B_CONFIG_DIR), $(B_CONFIG_F)) \
					$(call combine, $(B_MATHS_DIR), $(B_MATHS_F)) \
					$(call combine, $(B_INIT_DIR), $(B_INIT_F)) \
					$(call combine, $(B_RENDER_DIR), $(B_RENDER_F)) \
					$(call combine, $(B_EXEC_DIR), $(B_EXEC_F)) \
					main.c

# BONUS_SRCS_DIR	=	$(shell find bonus -type d)
# BONUS_SRCS_F	=	$(shell find bonus -type f -name '*.c')
# vpath %.c $(BONUS_SRCS_DIR)

BONUS_OBJS_DIR	=	bonus/objs/
BONUS_OBJS_F	=	$(patsubst %.c,$(BONUS_OBJS_DIR)%.o,$(BONUS_SRCS_F))

DEPS_BONUS		=	$(patsubst %.c,$(BONUS_OBJS_DIR)%.d,$(BONUS_SRCS_F))

#******************************************************************************#
#	PROGRESS BAR FUNCTIONS
#******************************************************************************#

define save_cursor
	printf "\033[s"
endef

define restore_cursor
	printf "\033[u"
endef

define move_to_top
	printf "\033[3;0H"
endef

define clear_line
	printf "\033[K"
endef

define draw_progress_bar
	$(save_cursor)
	$(clear_line)
	@files_total=$$(echo "$(SRCS_F)" | wc -w); \
	files_compiled=$$(find $(OBJS_DIR) -name "*.o" 2>/dev/null | wc -l); \
	if [ $$files_total -eq 0 ]; then percent=0; else percent=$$((files_compiled * 100 / files_total)); fi; \
	bar_len=60; \
	completed=$$((bar_len * files_compiled / files_total)); \
	remaining=$$((bar_len - completed)); \
	bar=""; \
	for i in $$(seq 1 $$completed); do bar="$$bar#"; done; \
	for i in $$(seq 1 $$remaining); do bar="$$bar "; done; \
	printf "$(BOLD)Loading: [$(GREEN)$$bar$(RESET)$(BOLD)] $$percent%%$(RESET)" > /dev/tty
	printf "\n"
	$(restore_cursor)
endef

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(NAME)

# init_display:
# 		@clear
# 		@$(draw_progress_bar)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(PINK)Compiled: $(RESET)$(ITAL)$<                                  \n$(RESET)"
				@cc $(DEPFLAGS) $(CFLAGS) -I $(HEADERS) -I/usr/include -I $(MLX_DIR) -c $< -o $@
#				@$(draw_progress_bar)
-include $(DEPS_MANDAT)

#	> /dev/null 2>&1
#	redirige à la fois la sortie standard (stdout) et la sortie d'erreur (stderr)
#	vers /dev/null ---> tous les messages de la MLX sont donc mis en sourdine
$(LIBFT) $(MLX):
			@make --no-print-directory -sC $(LIBFT_DIR)
			@make --no-print-directory -sC $(MLX_DIR) > /dev/null 2>&1

$(NAME): $(OBJS_F) $(LIBFT) $(MLX)
			@cc $(CFLAGS) -I $(HEADERS) $(OBJS_F) $(LFLAGS) $(MLXFLAGS) -o $(NAME)
			@echo "\n\n=================== $(shell bash rainbow.sh "cub3D") ===================\n"
			@echo "$(BLINK)$(GREEN)\t\t    READY!$(RESET)\n"
			@echo "$(BOLD)=============================================\n\n$(RESET)"

clean:
		@rm -rf $(OBJS_DIR) $(BONUS_OBJS_DIR)
		@make --no-print-directory clean -sC $(MLX_DIR) > /dev/null 2>&1
		@make --no-print-directory clean -sC $(LIBFT_DIR)
		@echo "\n$(BOLD)$(BLUE)[objects]:\t$(RESET)Removed!"

fclean: clean
			@rm -rf $(NAME) $(NAME_BONUS)
			@rm -rf $(LIBFT) $(MLX)
			@echo "$(BOLD)$(CYAN)[executables]:\t$(RESET)Removed!\n"

re:	fclean all bonus
		@echo "\n$(BOLD)$(YELLOW)make re: $(RESET)Project successfully rebuilt! ✨\n\n"

bonus: $(NAME_BONUS)

$(BONUS_OBJS_DIR)%.o: $(BONUS_SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(PURPLE)Compiled: $(RESET)$(ITAL)$<                                  \n$(RESET)"
				@cc $(DEPFLAGS) $(CFLAGS) -I $(HEADERS) -I/usr/include -I $(MLX_DIR) -c $< -o $@
-include $(DEPS_BONUS)

$(NAME_BONUS): $(BONUS_OBJS_F) $(LIBFT) $(MLX)
			@echo "\n\n=================== $(shell bash rainbow.sh "Telecubbies3D Horror") ===================\n"
			@echo "$(BLINK)$(GREEN)\t\t\tBONUS READY!$(RESET)"
			@echo "\t\t\t   Grrrr\n"
			@echo "$(BOLD)============================================================\n\n$(RESET)"
			@cc $(CFLAGS) -I $(HEADERS) $(BONUS_OBJS_F) $(LFLAGS) $(MLXFLAGS) -o $(NAME_BONUS)

debug: fclean
		make $(NAME) CFLAGS="$(CFLAGS) $(DEBUG)"

debug_bonus: fclean
		make $(NAME_BONUS) CFLAGS="$(CFLAGS) $(DEBUG)"

.PHONY:	all clean fclean re bonus debug debug_bonus