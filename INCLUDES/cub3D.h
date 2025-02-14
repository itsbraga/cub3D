/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:08:40 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/14 20:09:20 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*******************************************/
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../MLX/mlx.h"
# include "../LIBFT/INCLUDES/libft.h"
# include "../LIBFT/INCLUDES/ft_printf.h"
# include "structs.h"
# include "defines.h"
# include "parsing.h"
# include "tools.h"
# include "colors.h"
/*******************************************/

// main.c
void	clear_window(t_mlx *mlx);

/******************************************************************************\
 * INIT
\******************************************************************************/

// init_structs.c
t_mlx	*mlx_s(void);
t_data	*data_s(void);
void	init_data(t_data *data);
void	init_mlx(t_mlx *mlx, t_data *data);
void	init_map(t_map *map, t_data *data);
void	init_ray(t_data *data, t_ray *ray);

// draw_map2d.c
void	draw_map2d(t_data *data, t_map *map);

/******************************************************************************\
 * CONFIGS
\******************************************************************************/

// mlx_events.c
int     set_keypress_flag(int key, t_data *data, t_kevent *k);


// mlx_exit.c
void	del_win(t_mlx *mlx);
void	del_img(t_mlx *mlx);
int		clean(t_mlx *mlx);

/******************************************************************************\
 * MATHS
\******************************************************************************/

// utils.c
bool	valid_point(t_point point);
float	get_radian(int degree);
float	square(float to_square);
float	norm_angle(float angle);

// draw_line.c
void	swap_point(t_point *p0, t_point *p1);
void	draw_line(t_mlx *mlx, t_point p0, t_point p1, int color);

// draw_player.c
void	draw_line(t_mlx *mlx, t_point p0, t_point p1, int color);
void	draw_player(t_data *data, t_mlx *mlx, t_point player);

// raycasting.c
void	raycasting(t_data *data, t_ray *r);

// 2d_to_3d.c

/******************************************************************************\
 * EXECUTION
\******************************************************************************/

// render_game.c
void	init_point(t_point *point, float x, float y);
int		render(t_data *data);

#endif