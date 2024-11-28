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

NAME		=	cub3d

LIBFT_PATH	=	./LIBFT/
LIBFT		=	$(LIBFT_PATH)libft.a
MLX_PATH	=	./MLX/
MLX			=	$(MLX_PATH)libmlx.a

CC			=	cc
INC			=	./INCLUDES/

CFLAGS		=	-Wall -Wextra -Werror -I
LFLAGS		=	-L $(LIBFT_PATH)
MLXFLAGS	=	-Lmlx -lX11 -lXext -lm
DEPFLAGS	=	-MMD -MP
MAKEFLAGS	+=	--no-print-directory

DEBUG		=	-O3

#******************************************************************************#
#	SOURCES
#******************************************************************************#

#TOOLS_DIR		=	TOOLS/
#TOOLS_F			=	error_handler.c lstclear.c cleanup.c secure.c

#******************************************************************************#
#	COMBINE FILES AND DIRECTORIES
#******************************************************************************#

SRCS_DIR		=	SRCS/
SRCS_F			=	parsing.c main.c
#$(addprefix $(TOOLS_DIR), $(TOOLS_F))

OBJS_DIR		=	OBJS/
OBJS_F			=	$(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS_F))

DEPS_F			=	$(patsubst %.c,$(OBJS_DIR)%.d,$(SRCS_F))

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(LIBFT) $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(GREEN)Compiled: $(RESET)$(ITAL)$<                                  \n"
				@$(CC) $(DEPFLAGS) $(CFLAGS) $(INC) -c $< -o $@
#				@$(CC) $(DEPFLAGS) $(CFLAGS) $(INC) -I/usr/include -Imlx -c $< -o $@
-include $(DEPS_F)

$(LIBFT):
		@make -sC $(LIBFT_PATH) $(MAKEFLAGS)

$(NAME): $(OBJS_F) $(LIBFT)
			@printf "\n\n================= CUB3D =================\n\n"
			@printf "$(BLINK)$(GREEN)\t\t  READY!$(RESET)\n\n"
			@printf "$(BOLD)=========================================\n\n$(RESET)"
			@$(CC) $(CFLAGS) $(INC) $(OBJS_F) $(LFLAGS) -I $(MLX) $(MLXFLAGS) -o $(NAME)
#			@$(CC) $(CFLAGS) $(INC) $(OBJS_F) $(LFLAGS) -I $(MLX) $(MLXFLAGS) -L/usr/lib -o $(NAME)

clean:
		@rm -rf $(OBJS_DIR)
#		@make clean -sC $(MLX_PATH) $(MAKEFLAGS)
		@make clean -sC $(LIBFT_PATH) $(MAKEFLAGS)
		@printf "\n$(BOLD)$(BLUE)[objs]:\t $(RESET)Clean completed\n"

fclean: clean
			@rm -rf $(NAME)
#			@make fclean -sC $(MLX_PATH) $(MAKEFLAGS)
			@make fclean -sC $(LIBFT_PATH) $(MAKEFLAGS)
			@printf "$(BOLD)$(CYAN)[execs]: $(RESET)Full clean completed!\n\n\n"

re:	fclean all
		@printf "\n$(BOLD)$(YELLOW)make re: $(RESET)All files have been rebuilt! ✨\n\n"

norm:
		@clear
		@norminette $(INC) $(SRC_DIR) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm