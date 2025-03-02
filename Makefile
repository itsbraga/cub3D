#—————————————————————————————————————————————
#	ANSI
#—————————————————————————————————————————————

RESET			:=	\033[0m
BOLD			:=	\033[1m
ITAL			:=	\033[3m
BLINK			:=	\033[5m

RED				:=	\033[31m
GREEN			:=	\033[32m
YELLOW			:=	\033[33m
BLUE			:=	\033[34m
CYAN			:=	\033[36m
PINK			:=	\033[38;2;255;182;193m
PURPLE			:=	\033[38;2;211;211;255m
ORANGE			:=	\033[38;2;255;178;127m

#—————————————————————————————————————————————
#	BASE
#—————————————————————————————————————————————

LIBFT_DIR		:=	LIBFT/
LIBFT			:=	$(addprefix $(LIBFT_DIR), libft.a)
MLX_DIR			:=	mlx/
MLX				:=	$(addprefix $(MLX_DIR), libmlx.a)

HEADERS			:=	-Iincludes -I/usr/include -I$(MLX_DIR)

CFLAGS			+=	-Wall -Wextra -Werror
DEPFLAGS		+=	-MMD -MP
LFLAGS			+=	-L$(LIBFT_DIR) -lft
MLXFLAGS		+=	-L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11
MATHFLAGS		+=	-lm
ADDFLAGS		+=	$(LFLAGS) $(MLXFLAGS) $(MATHFLAGS)
DEBUG			+=	-O3 -g3 #-0fast
NO_PRINT_DIR	+=	--no-print-directory

#—————————————————————————————————————————————
#	MANDATORY
#—————————————————————————————————————————————

NAME			:=	cub3D

SRCS_DIR		:=	$(shell find mandatory -type d)
SRCS_F			:=	$(shell find mandatory -type f -name '*.c')

OBJS_DIR		:=	mandatory/objs/
OBJS_F			:=	$(patsubst mandatory/%.c,$(OBJS_DIR)%.o,$(SRCS_F))
DEPENDENCIES	:=	$(OBJS_F:.o=.d)

#—————————————————————————————————————————————
#	BONUS
#—————————————————————————————————————————————

NAME_BONUS		:=	cub3D_bonus

BONUS_SRCS_DIR	:=	$(shell find bonus -type d)
BONUS_SRCS_F	:=	$(shell find bonus -type f -name '*.c')

BONUS_OBJS_DIR	:=	bonus/objs/
BONUS_OBJS_F	:=	$(patsubst bonus/%.c,$(BONUS_OBJS_DIR)%.o,$(BONUS_SRCS_F))
B_DEPENDENCIES	:=	$(BONUS_OBJS_F:.o=.d)

#—————————————————————————————————————————————
#	CURSOR CONTROL
#—————————————————————————————————————————————

define save_cursor
	printf "\033[s"
endef

define restore_cursor
	printf "\033[u"
endef

define move_to_bottom
	printf "\033[$$(tput lines);1H"
endef

define clear_line
	printf "\033[K"
endef

#—————————————————————————————————————————————
#	COMPILATION PROGRESS FUNCTIONS
#—————————————————————————————————————————————

define building_msg
	printf "$(BOLD)$(2)Building $(1)...$(RESET)\n\n"
endef

define display_compiled_file
	printf "$(BOLD)$(ITAL)$(1)Compiled: $(RESET)$(ITAL)$(2)                                  \n$(RESET)"
endef

define progress_bar
	$(save_cursor)
	$(move_to_bottom)
	$(clear_line)
	files_total=$$(echo "$(SRCS_F)" | wc -w); \
	files_compiled=$$(find $(OBJS_DIR) -name "*.o" 2>/dev/null | wc -l); \
	if [ $$files_total -eq 0 ]; then percent=0; else percent=$$((files_compiled * 100 / files_total)); fi; \
	bar_len=60; \
	completed=$$((bar_len * files_compiled / files_total)); \
	remaining=$$((bar_len - completed)); \
	bar=""; \
	for i in $$(seq 1 $$completed); do bar="$$bar#"; done; \
	for i in $$(seq 1 $$remaining); do bar="$$bar "; done; \
	printf "\r$(BOLD)Loading: [$(GREEN)$$bar$(RESET)$(BOLD)] $$percent%%$(RESET)" > /dev/tty; \
	$(restore_cursor)
endef

define bonus_progress_bar
	$(save_cursor)
	$(move_to_bottom)
	$(clear_line)
	files_total=$$(echo "$(BONUS_SRCS_F)" | wc -w); \
	files_compiled=$$(find $(BONUS_OBJS_DIR) -name "*.o" 2>/dev/null | wc -l); \
	if [ $$files_total -eq 0 ]; then percent=0; else percent=$$((files_compiled * 100 / files_total)); fi; \
	bar_len=60; \
	completed=$$((bar_len * files_compiled / files_total)); \
	remaining=$$((bar_len - completed)); \
	bar=""; \
	for i in $$(seq 1 $$completed); do bar="$$bar#"; done; \
	for i in $$(seq 1 $$remaining); do bar="$$bar "; done; \
	printf "\r$(BOLD)Loading: [$(GREEN)$$bar$(RESET)$(BOLD)] $$percent%%$(RESET)" > /dev/tty; \
	$(restore_cursor)
endef

#—————————————————————————————————————————————
#	RULES
#—————————————————————————————————————————————

all: init_display $(NAME)

init_display: .init_done

.init_done:
		@clear
		@$(call building_msg,$(NAME),$(PURPLE))
		@$(progress_bar)
		@echo ""
		@touch .init_done

$(OBJS_DIR)%.o: mandatory/%.c
		@mkdir -p $(dir $@)
		@$(progress_bar)
		@$(call display_compiled_file,$(PINK),$<)
		@cc $(DEPFLAGS) $(CFLAGS) $(HEADERS) -c $< -o $@
		@$(progress_bar)
-include $(DEPENDENCIES)

$(LIBFT) $(MLX):
		@make $(NO_PRINT_DIR) -sC $(LIBFT_DIR)
		@make $(NO_PRINT_DIR) -sC $(MLX_DIR) > /dev/null 2>&1

$(NAME): $(OBJS_F) $(LIBFT) $(MLX)
		@echo "\n\n$(BOLD)=================== $(shell bash rainbow.sh "cub3D") $(BOLD)===================\n"
		@echo "$(BLINK)$(GREEN)\t\t    READY!$(RESET)\n"
		@echo "$(BOLD)=============================================\n\n"
		@cc $(CFLAGS) $(HEADERS) $(OBJS_F) $(ADDFLAGS) -o $(NAME)

init_bonus_display: .bonus_init_done

.bonus_init_done:
		@clear
		@$(call building_msg,$(NAME_BONUS),$(ORANGE))
		@$(bonus_progress_bar)
		@echo ""
		@touch .bonus_init_done

$(BONUS_OBJS_DIR)%.o: bonus/%.c
		@mkdir -p $(dir $@)
		@$(bonus_progress_bar)
		@$(call display_compiled_file,$(PURPLE),$<)
		@cc $(DEPFLAGS) $(CFLAGS) $(HEADERS) -c $< -o $@
		@$(bonus_progress_bar)
-include $(B_DEPENDENCIES)

bonus: init_bonus_display $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS_F) $(LIBFT) $(MLX)
		@echo "\n\n$(BOLD)================ $(RED)Telecubbies3D Horror$(RESET)$(BOLD) ================\n"
		@echo "$(BLINK)$(GREEN)\t\t     BONUS READY!$(RESET)\n"
		@echo "$(BOLD)======================================================\n\n";
		@cc $(CFLAGS) $(HEADERS) $(BONUS_OBJS_F) $(ADDFLAGS) -o $(NAME_BONUS)

clean:
		@rm -rf $(OBJS_DIR) $(BONUS_OBJS_DIR)
		@make $(NO_PRINT_DIR) clean -sC $(MLX_DIR) > /dev/null 2>&1
		@make $(NO_PRINT_DIR) clean -sC $(LIBFT_DIR)
		@echo "\n$(BOLD)$(BLUE)[objects]:\t$(RESET)Removed!"

fclean: clean
		@rm -rf $(NAME) $(NAME_BONUS)
		@rm -rf $(LIBFT) $(MLX)
		@rm -rf .init_done .bonus_init_done
		@echo "$(BOLD)$(CYAN)[executables]:\t$(RESET)Removed!\n"

re:	fclean all
		@echo "$(BOLD)$(YELLOW)make re: $(RESET)Project successfully rebuilt! ✨ (mandatory only)\n"

debug: fclean $(LIBFT) $(MLX)
		@make $(NO_PRINT_DIR) $(NAME) CFLAGS="$(CFLAGS) $(DEBUG)"

debug_bonus: fclean $(LIBFT) $(MLX)
		@make $(NO_PRINT_DIR) $(NAME_BONUS) CFLAGS="$(CFLAGS) $(DEBUG)"

.PHONY:	all clean fclean re bonus