/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:22:46 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/26 21:17:57 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define START_SCREEN "./Teletubbies.xpm"
# define VALID_MAP "01 NSEW"

/******************************************************************************\
 * MATHS
\******************************************************************************/

# define PI 3.1415926535
# define PI2 PI/2
# define PI3 3*PI/2
# define EPS 0.000001
# define TILE_SIZE 64
# define FOV 60
# define PROJ_DISTANCE ((WIN_WIDTH / 2) / tan(get_radian(FOV) / 2))
# define MOVE_SPEED 5

/******************************************************************************\
 * GARBAGE COLLECTOR FLAGS (Yama)
\******************************************************************************/

# define CREATE 0
# define CREATE_TAB 1
# define ADD 2
# define ADD_TAB 3
# define REMOVE -1
# define CLEAN_ALL -2
# define SEARCH -4

/******************************************************************************\
 * EXIT STATUS
\******************************************************************************/

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * ERROR
\******************************************************************************/

# define ERR_PREFIX "Error\n"
# define ERR_MLX "Something went wrong with MLX !"
# define ERR_MALLOC "Memory allocation failed"

# define ERR_ARGS "\033[5m\033[31m# BAD ARGUMENTS ! #\033[0m\n"
# define ERR_PATH "No such file or directory" // catch errno + given path before
# define ERR_PERM "Permission denied"
# define ERR_EXT "Bad extension (must be .cub)"

# define ERR_EMPTY "Oops! This file seems to be empty"
# define ERR_MAP "Invalid map"
# define ERR_CHAR "Invalid character in map"
# define ERR_RGB "Invalid RGB code"
# define ERR_CONFIG "Bad config file"

# define ERR_START_P "No starting position found for the player"
# define ERR_MPLAYER "Multiple starting positions found"

/******************************************************************************\
 * MLX
\******************************************************************************/

# define WIN_WIDTH 1024
# define WIN_HEIGHT 1024

# define DEL_WIN "\nWindow successfully destroyed.\n\n"
# define DEL_IMG "\nImage and window successfully destroyed.\n\n"
# define EXIT_PROG "\nCleaned everything and exited the program.\n\n"

/********************\
 * PLAYER MOVEMENTS
\********************/

// Array of pointers to functions
typedef void	(*move_tab)(t_data *data);

// Move_tab *f() indexes
# define W_KEY 0
# define S_KEY 1
# define A_KEY 2
# define D_KEY 3
# define LEFT_KEY 4
# define RIGHT_KEY 5

// Keyboard
# define W 119
# define A 97
# define S 115
# define D 100

/******************************************************************************\
 * MAP SETUP
\******************************************************************************/

/********************\
 * TEXTURES HELP
\********************/

# define NO	0
# define SO 180
# define WE 270
# define EA 90

/********************\
 * PIXEL COLORS
\********************/

# define RED_PIX 0x00FF0000
# define YELLOW_PIX 0x00FFFF00
# define WHITE_PIX 0x00FFFFFF
# define BLACK_PIX 0xFF000000
# define LAVENDER_PIX 0x009683EC
# define LPINK_PIX 0x00FFB6C1
# define ROY_PURPLE_PIX 0x005A006C
# define RUSS_PURPLE_PIX 0x0019001E

#endif