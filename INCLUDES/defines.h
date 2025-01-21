/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:22:46 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/21 16:22:11 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

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

# define W_WIDTH 1000
# define W_HEIGHT 1000

/**************\
 * NAVIGATION
\**************/

// Player
# define PLAYER_SPEED 3

// Keyboard
# define A 97
# define W 119
# define D 100
# define S 115

// Mouse
# define MUP	4
# define MDOWN	5

/**************\
 * MESSAGES
\**************/

# define DEL_WIN "\nWindow successfully destroyed.\n\n"
# define DEL_IMG "\nImage and window successfully destroyed.\n\n"
# define EXIT_PROG "\nExited the program cleanly.\n\n"

/******************************************************************************\
 * MAP SETUP
\******************************************************************************/

# define VALID_MAP "01 NSEW"

/**************\
 * TEXTURES
\**************/

# define NO	0
# define SO 180
# define WE 270
# define EA 90

/**************\
 * MLX COLORS
\**************/

# define HRED 0x00FF0000
# define HYELLOW 0x00FFFF00
# define HWHITE 0x00FFFFFF
# define HBLACK 0xFF000000

#endif