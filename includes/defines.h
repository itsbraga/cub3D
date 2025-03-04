/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:22:46 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/04 02:34:56 by art3mis          ###   ########.fr       */
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
# define CREATE_array 1
# define ADD 2
# define ADD_array 3
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

# define ERR_PREFIX "\033[1m\033[31mError: \033[0m"
# define ERR_MLX "Something went wrong with MinilibX"
# define ERR_XPM "Unable to put .xpm file to image"
# define ERR_ADDR "Unable to find image address in memory"
# define ERR_MALLOC "Memory allocation failed"

# define ERR_PATH "No such file or directory" // catch errno + given path before
# define ERR_PERM "Permission denied"
# define ERR_EXT "Bad extension (must be .cub)"

# define ERR_EMPTY "Oops! This file seems to be empty"
# define ERR_MAP "Invalid map"
# define ERR_CHAR "Invalid character in map"
# define ERR_RGB "Invalid RGB"
# define ERR_CONFIG "Bad config file"

# define ERR_START_POS "No starting position found for the player_pos"
# define ERR_MULT_POS "Multiple starting positions found"

/******************************************************************************\
 * MLX
\******************************************************************************/

# define WIN_WIDTH 1024
# define WIN_HEIGHT 1024
// # define WIN_WIDTH 960
// # define WIN_HEIGHT 720

# define DEL_WIN "\nWindow successfully destroyed.\n\n"
# define DEL_IMG "\nImage and window successfully destroyed.\n\n"
# define EXIT_PROG "\nCleaned everything and exited the program.\n\n"

/********************\
 * PLAYER MOVEMENTS
\********************/

// Array of pointers to functions
typedef void	(*move_array)(t_data *data);

// Move_array *f() indexes
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

// Mouse
# define MOUSE_SENSITIVITY 0.2f

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
# define LGRAY_PIX 0x00D3D3D3
# define GRAY_PIX 0x00303030

#endif