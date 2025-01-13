#******************************************************************************#
#	FEATURES
#******************************************************************************#

RESET		:=	\e[0m
BOLD		:=	\e[1m
ITAL		:=	\e[3m
BLINK		:=	\e[5m

GREEN		:=	\e[32m
YELLOW		:=	\e[33m
BLUE		:=	\e[34m
CYAN		:=	\e[36m
PINK		:=	\e[38;2;255;182;193m

#******************************************************************************#
#	BASICS
#******************************************************************************#

NAME		=	cub3D

LIBFT_DIR	=	./LIBFT/
LIBFT		=	$(addprefix $(LIBFT_DIR), libft.a)
MLX_DIR		=	./MLX/
MLX			=	$(addprefix $(MLX_DIR), libmlx.a)

CC			=	cc
INC			=	./INCLUDES/

CFLAGS		=	-Wall -Wextra -Werror
LFLAGS		=	-L $(LIBFT_DIR) -lft
MLXFLAGS	=	-L $(MLX_DIR) -lmlx -lm -lX11 -lXext
DEPFLAGS	=	-MMD -MP
MAKEFLAGS	+=	--no-print-directory

DEBUG		=	-O3 -g

#******************************************************************************#
#	SOURCES
#******************************************************************************#

TOOLS_DIR		=	TOOLS/
TOOLS_F			=	error.c secure.c pixel_put.c free_and_exit.c

GARBAGE_DIR		=	TOOLS/GARBAGE_COLLECTOR/
GARBAGE_F		=	garbage_collector.c utils.c lst_utils.c

INIT_DIR		=	INIT/
INIT_F			=	init_structs.c

PARSING_DIR		=	PARSING/
PARSING_F		=	check_map.c check_cub_file.c

CONFIG_DIR		=	CONFIGS/
CONFIG_F		=	mlx_events.c mlx_exit.c

MATHS_DIR		=	MATHS/
MATHS_F			=	draw.c

#******************************************************************************#
#	COMBINE FILES AND DIRECTORIES
#******************************************************************************#

SRCS_DIR		=	SRCS/
SRCS_F			=	$(addprefix $(TOOLS_DIR), $(TOOLS_F)) \
					$(addprefix $(GARBAGE_DIR), $(GARBAGE_F)) \
					$(addprefix $(INIT_DIR), $(INIT_F)) \
					$(addprefix $(PARSING_DIR), $(PARSING_F)) \
					$(addprefix $(CONFIG_DIR), $(CONFIG_F)) \
					$(addprefix $(MATHS_DIR), $(MATHS_F)) \
					main.c

OBJS_DIR		=	OBJS/
OBJS_F			=	$(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS_F))

DEPS_F			=	$(patsubst %.c,$(OBJS_DIR)%.d,$(SRCS_F))

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(LIBFT) $(MLX) $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(GREEN)Compiled: $(RESET)$(ITAL)$<                                  \n"
#				@$(CC) $(DEPFLAGS) $(CFLAGS) -I $(INC) -c $< -o $@
				@$(CC) $(DEPFLAGS) $(CFLAGS) -I $(INC) -I/usr/include -I $(MLX_DIR) -c $< -o $@
-include $(DEPS_F)

$(LIBFT):
		@make -sC $(LIBFT_DIR) $(MAKEFLAGS)

$(MLX):
		@make -sC $(MLX_DIR) $(MAKEFLAGS)

$(NAME): $(OBJS_F) $(LIBFT) $(MLX)
			@printf "\n\n================= CUB3D =================\n\n"
			@printf "$(BLINK)$(GREEN)\t\t  READY!$(RESET)\n\n"
			@printf "$(BOLD)=========================================\n\n$(RESET)"
#			@$(CC) $(CFLAGS) -I $(INC) $(OBJS_F) $(LFLAGS) $(MLXFLAGS) -o $(NAME)
			@$(CC) $(CFLAGS) -I $(INC) $(OBJS_F) $(LFLAGS) $(MLXFLAGS) -L/usr/lib -o $(NAME)

clean:
		@rm -rf $(OBJS_DIR)
		@make clean -sC $(MLX_DIR) $(MAKEFLAGS)
		@make clean -sC $(LIBFT_DIR) $(MAKEFLAGS)
		@printf "\n$(BOLD)$(BLUE)[objs]:\t $(RESET)Clean completed\n"

fclean: clean
			@rm -rf $(NAME)
			@rm -rf $(LIBFT) $(MLX)
			@printf "$(BOLD)$(CYAN)[execs]: $(RESET)Full clean completed!\n\n\n"

re:	fclean all
		@printf "\n$(BOLD)$(YELLOW)make re: $(RESET)All files have been rebuilt! ✨\n\n"

.PHONY:	all clean fclean re