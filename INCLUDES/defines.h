/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:22:46 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/04 16:24:40 by art3mis          ###   ########.fr       */
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

# define ERR "Error\n"
# define ERR_MLX "Something's wrong with MLX !"
# define ERR_MALLOC "Memory allocation failed"

# define ERR_BADARGS "\033[5m\033[31m# BAD ARGUMENTS ! #\033[0m\n"
# define ERR_MAP "Invalid map"
# define ERR_PATH "No such file or directory" // catch errno + given path before
# define ERR_PERM "Permission denied"
# define ERR_RGB "Invalid color code"
# define ERR_EXT "Bad extension (must be .cub)"
# define ERR_CONFIG "Bad config file"

/******************************************************************************\
 * MLX
\******************************************************************************/

# define WIDTH 1000
# define HEIGHT 1000

/******************************************************************************\
 * TEXTURES
\******************************************************************************/

# define NO	0
# define SO 1
# define WE 2
# define EA 3

/******************************************************************************\
 * MLX COLORS
\******************************************************************************/

# define MRED 0xFF0000
# define MWHITE 0xFFFFFF

/******************************************************************************\
 * NAVIGATION
\******************************************************************************/

// Keyboard
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
// # define ZERO 65438
// # define ONE 65436
// # define TWO 65433
// # define THREE 65435
// # define FOUR 65430
// # define FIVE 65437

// Mouse
# define MUP	4
# define MDOWN	5

#endif