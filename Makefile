#—————————————————————————————————————————————
#	FEATURES
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

LIBFT_DIR		=	LIBFT/
LIBFT			=	$(addprefix $(LIBFT_DIR), libft.a)
MLX_DIR			=	mlx/
MLX				=	$(addprefix $(MLX_DIR), libmlx.a)

HEADERS			=	-Iincludes -I/usr/include -I$(MLX_DIR)

CFLAGS			=	-Wall -Wextra -Werror
LFLAGS			=	-L$(LIBFT_DIR) -lft
MLXFLAGS		=	-L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm
DEPFLAGS		=	-MMD -MP
DEBUG			=	-O3 -g3 #-0fast

#—————————————————————————————————————————————
#	MANDATORY
#—————————————————————————————————————————————

NAME			=	cub3D

SRCS_DIR		=	$(shell find mandatory -type d)
SRCS_F			=	$(shell find mandatory -type f -name '*.c')

OBJS_DIR		=	mandatory/objs/
OBJS_F			=	$(patsubst mandatory/%.c,$(OBJS_DIR)%.o,$(SRCS_F))
DEPENDENCIES	=	$(OBJS_F:.o=.d)

#—————————————————————————————————————————————
#	BONUS
#—————————————————————————————————————————————

NAME_BONUS		=	cub3D_bonus

BONUS_SRCS_DIR	=	$(shell find bonus -type d)
BONUS_SRCS_F	=	$(shell find bonus -type f -name '*.c')

BONUS_OBJS_DIR	=	bonus/objs/
BONUS_OBJS_F	=	$(patsubst bonus/%.c,$(BONUS_OBJS_DIR)%.o,$(BONUS_SRCS_F))
B_DEPENDENCIES	=	$(BONUS_OBJS_F:.o=.d)

#—————————————————————————————————————————————
#	CURSOR CONTROL
#—————————————————————————————————————————————

define save_cursor
	printf "\033[s"
endef

define restore_cursor
	printf "\033[u"
endef

define move_to_status_line
	printf "\033[%d;0H" "$$(($$(tput lines) - 1))"
endef

define clear_line
	printf "\033[K"
endef

#—————————————————————————————————————————————
#	COMPILATION PROGRESS FUNCTIONS
#—————————————————————————————————————————————

define building_msg
	printf "\033[H"
	printf "\033[2J"
	printf "$(BOLD)$(2)Building $(1)...$(RESET)\n\n"
endef

define draw_progress_bar
	$(save_cursor)
	$(move_to_status_line)
	$(clear_line)
	files_total=$$(echo "$(SRCS_F)" | wc -w); \
	files_compiled=$$(find $(OBJS_DIR) -name "*.o" 2>/dev/null | wc -l); \
	if [ $$files_total -eq 0 ]; then \
		percent=0; \
	else \
		percent=$$((files_compiled * 100 / files_total)); \
	fi; \
	bar_len=80; \
	completed=$$((bar_len * files_compiled / files_total)); \
	remaining=$$((bar_len - completed)); \
	bar=""; \
	for i in $$(seq 1 $$completed); do \
		bar="$$bar#"; \
	done; \
	for i in $$(seq 1 $$remaining); do \
		bar="$$bar "; \
	done; \
	printf "$(BOLD)Loading: [$(GREEN)$$bar$(RESET)$(BOLD)] $$percent%%$(RESET)"
	$(restore_cursor)
endef

define draw_bonus_progress_bar
	$(save_cursor)
	$(move_to_status_line)
	$(clear_line)
	files_total=$$(echo "$(BONUS_SRCS_F)" | wc -w); \
	files_compiled=$$(find $(BONUS_OBJS_DIR) -name "*.o" 2>/dev/null | wc -l); \
	if [ $$files_total -eq 0 ]; then \
		percent=0; \
	else \
		percent=$$((files_compiled * 100 / files_total)); \
	fi; \
	bar_len=80; \
	completed=$$((bar_len * files_compiled / files_total)); \
	remaining=$$((bar_len - completed)); \
	bar=""; \
	for i in $$(seq 1 $$completed); do \
		bar="$$bar#"; \
	done; \
	for i in $$(seq 1 $$remaining); do \
		bar="$$bar "; \
	done; \
	printf "$(BOLD)Loading: [$(GREEN)$$bar$(RESET)$(BOLD)] $$percent%%$(RESET)"
	$(restore_cursor)
endef

define draw_creepy_ascii_art
	printf "\n\
\t⢀⣾⣿⣿⣾⣿⣿⡿⣱⣿⣿⣿⡿⠁⢸⡟⢸⣿⣵⣿⣿⡿⣿⢻⡿⠀⠀⠀⠀⠀⠀⢀⡀⠈⢹⣾⣯⣿⣿⡙⣿⣿⣿⣇⡀⠀⠀⠀⠀⠀\n\
⠀ ⠀⠀⠀ ⢀⣿⣿⣿⣇⣿⣿⡿⣸⣿⣿⣿⣿⡁⢰⣿⢠⣿⣱⣿⣿⡟⣱⡟⣿⠆⠀⠀⠀⠀⠀⠀⠈⢱⠀⠆⢻⣾⣿⣿⣧⢻⣿⣿⣧⠱⠀⠀⠀⠀⠀\n\
 ⠀⠀⠀⠀ ⣾⣼⣿⣿⣼⣿⡿⣹⣿⣿⣿⣿⡗⠛⢦⣷⣿⢻⣿⣿⡿⣱⠟⢠⣿⠀⠀⠀⠀⠀⠀⠁⡅⢸⢇⠀⠙⣿⣿⣿⣿⣮⣿⣿⣿⣧⢣⠀⠀⠀⠀\n\
 ⠀⠀⠀ ⢰⢧⣿⣿⡯⣿⣿⣣⣯⡿⣿⣿⣿⡝⣀⢸⣿⢻⣿⣿⣿⢱⡛⣠⣼⡇⠀⠀⠀⠀⠀⠀⠀⠡⠘⢈⣦⡇⢹⣿⣿⢿⣏⣿⣿⣿⣿⡌⠀⠀⠀⠀\n\
 ⠀⠀⠀ ⢸⣼⣿⣿⣿⣿⠃⡟⣼⠃⣿⣿⡯⢃⣽⢿⢳⣿⣿⡿⢡⠛⠁⠇⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⡃⠘⣿⣿⢸⣇⣿⣿⣿⣿⡏⠀⠀⠀⠀\n\
 ⠀⠀⠀ ⠺⣿⣿⣿⣿⠏⠀⠛⠉⢰⣿⠹⡟⠉⢱⣹⣾⠋⣹⡾⠁⠀⠀⣸⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣸⡇⣿⣿⣿⣿⡷⠀⠀⠀⠀\n\
 ⠀⠀⠀ ⢀⣿⣿⣿⡟⠀⠀⠆⢠⢾⣿⣰⣄⠒⠋⠘⠱⠀⣿⠁⠀⠀⠀⣿⡁⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠇⠰⣼⣿⣿⣿⢿⣿⣿⣿⣿⣿⡀⠀⠀⠀\n\
 ⠀⠀ ⢀⢼⣿⣿⣿⠆⠀⣠⣼⣾⣾⣿⣾⣿⣿⣆⡀⠐⠊⠉⠀⠀⠀⢰⡿⠀⠀⠀⣀⣤⣾⣿⣿⣾⣿⣶⣦⣄⠀⣿⡎⢿⣿⢸⣿⣿⣿⣿⣿⣧⠀⠀⠀\n\
 ⠀⠀ ⠈⢺⣿⣿⣼⣠⣸⣿⣿⠟⠛⢻⠟⠻⣿⣿⣿⣆⡀⠀⠀⠀⠀⠀⠁⠀⡴⣶⣿⣿⣿⡿⠛⠛⠛⢿⣿⣿⡄⣀⡂⠂⠉⣸⣿⣿⣿⣿⣿⣟⠀⠀⠀\n\
 ⠀⠀ ⠀⢺⣿⡿⠀⣿⣽⣿⠇⢀⣼⣿⣶⣈⢋⠙⣿⣿⡗⠀⠀⠀⠀⠀⠀⠘⣽⣿⣿⡿⢋⢔⣂⣀⠀⠀⠈⢿⣿⠸⡤⠄⠀⢸⣿⣿⣿⣿⣿⣿⡄⠀⠀\n\
 ⠀⠀ ⠀⣼⣿⣯⠀⣿⣿⣯⠀⢸⣿⣿⣿⣿⣏⢀⣿⣿⣯⠀⠀⠀⠀⠀⠀⢾⣿⣿⣿⡴⣿⣿⣿⣿⣿⡄⡄⢸⣿⡀⠃⠀⠀⠸⣿⣿⣿⣿⣿⣿⡇⠀⠀\n\
⠀ ⠀⡄⣹⣿⡗⠈⢻⣾⣿⣇⠌⢻⠿⠿⣿⣼⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⣿⣿⣿⣧⢹⣿⣿⣿⣿⢧⢀⣾⣿⢃⠃⠀⠀⢸⣿⣿⣿⣿⣿⣿⡇⠀⠀\n\
  ⠀⠀⠃⣿⣿⣿⢠⠈⢹⣿⡿⣷⣶⣾⣾⣿⣿⣟⣿⡟⠙⡆⠀⠀⠀⠀⠀⠂⢹⣿⣿⣿⣷⣽⣿⣋⣷⣬⣿⣿⢣⠀⠁⠀⠀⣾⣿⣿⣿⣿⣿⣿⠌⠀⠀\n\
  ⠀⠀⠀⣿⣿⣿⣘⠆ ⠘⡟⡯⣿⣷⣼⣿⣿⣿⠟⠁⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⡿⡿⢿⠟⠛⣩⠲⠁⠀⠀⠀⢤⣿⣿⣿⣿⣿⣿⣿⠦⡆⠀\n\
  ⠀⠀⠀⣿⣿⣿⣿⠄⠀ ⠀⠙⠻⢻⡿⢿⠟⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠿⣿⣿⣶⣿⠿⠿⠃⠀⠀⠀⣠⣡⣸⣿⣿⣿⣿⣿⣿⣿⡟⠃⠀\n\
 ⠀ ⠀⠀⣿⣿⣿⣿⣶⡄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠩⠙⠌⠀⠠⠊⠀⠀⠰⠍⢿⣿⣿⣿⣿⣿⣿⣿⣿⡷⢀⠀\n\
 ⠀ ⠀⠈⣿⣿⣿⣿⣿⠉⠣⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⣀⣀⣴⢷⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀\n\
 ⠀ ⠀⢐⣿⣿⣿⣿⣿⡃⡀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠳⣴⣧⣦⠄⠀⠀⠀⠀⠀⠀⠀⠀⢀⠰⣶⣷⠿⣤⠞⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢀\n\
 ⠀ ⠀⣺⣾⣿⣿⣿⣿⣷⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⣿⣿⡶⠋⣿⣿⣾⠀⠀⠀⠀⠀⠀⠀⠀⣟⣊⡹⣺⣾⢟⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠈\n\
  ⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⡄⢾⣆⠀⠀⠀⠀⠀⠀⠐⣿⣿⠈⠃⠙⢿⠿⠀⠀⠀⠀⠀⠀⠀⠀⠉⣩⣾⡿⢃⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀\n\
  ⢆⠀⠀⣿⣿⣿⣿⣿⣿⣿⣟⣎⣿⣧⡄⠀⠀⠀⠀⠀⠙⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢐⣦⣾⡿⢋⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀\n\
  ⢸⡦⡆⣿⣿⣿⣿⣿⣿⣿⣿⣿⡌⠹⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⣀⣼⣿⣿⠉⣐⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⡇⠀\n\
  ⠀⢸⠃⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⠈⢻⣿⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣿⣿⡿⠃⣡⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀\n\
  ⠀⠀⠙⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠙⠿⣿⣿⣦⣤⣀⣠⣀⣤⣴⣿⣿⣿⠋⠁⠤⣬⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣄⠀⠀\n\
  ⠀⠀⡜⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣀⠉⠛⠻⣿⣿⣿⣿⠿⠛⠿⢉⣀⡤⡀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀\n\
  ⠀⠀⠇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⠂⠀⠈⢳⡒⢀⣀⠤⢀⠀⣭⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣼⠁⠀⠀\n\
 ⠀ ⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣈⠣⠄⠀⠉⠀⣠⣵⠞⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣧⠀⠀⠀\n\
  ⠀⠀⣤⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠒⢶⠒⠶⠀⠉⠀⠀⠈⣿⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣹⣯⠀⠀⠀\n\
  ⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢳⢀⠸⠀⠀⠀⠀⠀⠀⠐⣿⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢹⡾⡃⠀⠀\n\
  ⠀⠀⣿⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣞⡄⠀⠀⠀⠀⠀⠀⠂⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⣿⠀⠀⠀\n\
  ⠀⠀⣿⡟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣤⣿⣿⣿⣿⣿⣌⠀⠀⠀⠀⠠⠀⠀⣿⣿⣿⣿⣿⡟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠹⠃⠀⠀\n\
  ⠀⠰⣘⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⡃⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠈⠀⠀⠀\n\
  ⠀⠀⡿⠟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⢿⡇⠀⠀⠀⠀⠀⠈⡇⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣀⠀\n\
	"
endef

#—————————————————————————————————————————————
#	RULES
#—————————————————————————————————————————————

all: $(NAME)

$(OBJS_DIR)%.o: mandatory/%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(PINK)Compiled: $(RESET)$(ITAL)$<                                  \n$(RESET)"
				@cc $(DEPFLAGS) $(CFLAGS) $(HEADERS) -c $< -o $@
				@$(draw_progress_bar)
-include $(DEPENDENCIES)

$(LIBFT) $(MLX):
			@make --no-print-directory -sC $(LIBFT_DIR)
			@make --no-print-directory -sC $(MLX_DIR) > /dev/null 2>&1

$(NAME): $(LIBFT) $(MLX)
			@$(call building_msg,$(NAME),$(PURPLE))
			@make --no-print-directory $(OBJS_F)
			@cc $(CFLAGS) $(HEADERS) $(OBJS_F) $(LFLAGS) $(MLXFLAGS) -o $(NAME)
			@clear
			@echo "\n\n$(BOLD)=================== $(shell bash rainbow.sh "cub3D") ===================\n"
			@echo "$(BLINK)$(GREEN)\t\t    READY!$(RESET)\n"
			@echo "$(BOLD)=============================================\n\n$(RESET)"

$(OBJS_F): | init_build

init_build:
		@$(call building_msg,$(NAME),$(PURPLE))

bonus: $(NAME_BONUS) 

$(BONUS_OBJS_DIR)%.o: bonus/%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(PURPLE)Compiled: $(RESET)$(ITAL)$<                                  \n$(RESET)"
				@cc $(DEPFLAGS) $(CFLAGS) $(HEADERS) -c $< -o $@
				@$(draw_bonus_progress_bar)
-include $(B_DEPENDENCIES)

$(NAME_BONUS): $(LIBFT) $(MLX)
			@$(call building_msg,$(NAME),$(ORANGE))
			@make --no-print-directory $(BONUS_OBJS_F)
			@cc $(CFLAGS) $(HEADERS) $(BONUS_OBJS_F) $(LFLAGS) $(MLXFLAGS) -o $(NAME_BONUS)
			@clear
			@$(draw_creepy_ascii_art)
			@echo "\n\n$(BOLD)================ $(RED)Telecubbies3D Horror$(RESET)$(BOLD) ================\n"
			@echo "$(BLINK)$(GREEN)\t\t     BONUS READY!$(RESET)"
			@echo "\t\t        Grrrr\n"
			@echo "$(BOLD)======================================================\n\n$(RESET)"

$(OBJS_F): | init_bonus_build

init_bonus_build:
		@$(call building_msg,$(NAME),$(ORANGE))

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

debug: fclean $(LIBFT) $(MLX)
		@make --no-print-directory $(NAME) CFLAGS="$(CFLAGS) $(DEBUG)"

debug_bonus: fclean $(LIBFT) $(MLX)
		@make --no-print-directory $(NAME_BONUS) CFLAGS="$(CFLAGS) $(DEBUG)"

.PHONY:	all bonus init_build init_bonus_build clean fclean re debug debug_bonus