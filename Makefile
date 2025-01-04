# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 18:05:18 by pmateo            #+#    #+#              #
#    Updated: 2024/03/19 22:18:02 by pmateo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Werror -Wextra -Wall -g3 -g
RM = rm -f
.DEFAULT_GOAL := all

NAME = cub3D

DIR_MLX = ./MLX
MLX = ${DIR_MLX}/libmlx.a

DIR_LIBFT = ./LIBFT
LIBFT = ${DIR_LIBFT}/libft.a

DIRINC_CUB3D = ./INCLUDES
DIRINC_LIBFT = ${DIR_LIBFT}/INCLUDES
DIRINC_MLX = ${DIR_MLX}
INCFILES = ${DIRINC_CUB3D}/cub3D.h ${DIRINC_CUB3D}/structs.h ${DIRINC_CUB3D}/defines.h ${DIRINC_CUB3D}/tools.h

DIR_SRCS = ./SRCS/
SRCS =				main.c INIT/init_structs.c TOOLS/errmsg.c TOOLS/free_and_exit.c TOOLS/secure.c

OBJ = ${SRCS:.c=.o}

%.o: ${DIR_SRCS}%.c ${INCFILES}
	@${CC} ${FLAGS} -c $< -o $@ 

${LIBFT}:
	@${MAKE} -s -C ${DIR_LIBFT}

${MLX}:
	@${MAKE} -s -C ${DIR_MLX}

${NAME}: ${OBJ} ${LIBFT} ${MLX} ${INCFILES}
	@${CC} ${FLAGS} -o ${NAME} ${OBJ} -I ${DIRINC_FRACTOL} -I ${DIRINC_LIBFT} -I ${DIRINC_MLX} -L ${DIR_MLX} -lXext -lX11 -lmlx -lm -L ${DIR_LIBFT} -lft

all: ${LIBFT} ${MLX} ${NAME}
		@echo "\033[1;5;32m# CUB3D READY ! #\033[0m"

bonus: all

clean:
		@${MAKE} -s -C ${DIR_LIBFT} clean
		@${MAKE} -s -C ${DIR_MLX} clean
		@${RM} ${OBJ}
		@echo "\033[1;9;35m# No more object files. #\033[0m"

fclean: clean
		@${MAKE} -s -C ${DIR_LIBFT} fclean
		@${RM} ${NAME}
		@echo "\033[1;9;35m# No more executable files. #\033[0m"

re: fclean all

.PHONY: all re clean fclean