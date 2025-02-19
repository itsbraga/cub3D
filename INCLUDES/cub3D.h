/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:08:40 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/20 00:10:48 by annabrag         ###   ########.fr       */
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

/******************************************************************************\
* INITIALIZATION
\******************************************************************************/

// init_structs.c
void	init_map(t_map *map, t_data *data);
void	init_ray(t_ray *ray, t_data *data);
void	init_keys(t_keys *key, t_data *data);
void	init_game(t_game *game);
void	init_structs(t_data *data, t_mlx *mlx);

// singletons.c
t_mlx	*mlx_s(void);
t_data	*data_s(void);
void	init_data(t_data *data);
void	init_mlx(t_mlx *mlx, t_data *data);

/******************************************************************************\
* CONFIGS/MLX_HOOKS
\******************************************************************************/
 
// mlx_events.c
int		set_keypress_flag(int keycode, t_data *data);
int		set_keyrelease_flag(int keycode, t_data *data);

// mlx_events2.c
void	set_hooks(t_mlx *mlx, t_data *data);
 
// mlx_exit.c
void	del_win(t_mlx *mlx);
void	del_img(t_mlx *mlx);
int		clean(t_mlx *mlx);
 
/******************************************************************************\
* MATHS
\******************************************************************************/
  
// utils.c
float	get_radian(int degree);
float	square(float to_square);
float	norm_angle(float angle);

// draw_line.c
void	draw_line(t_mlx *mlx, t_point p0, t_point p1, int color);
  
// draw_player.c
void	draw_line(t_mlx *mlx, t_point p0, t_point p1, int color);
void	draw_player(t_mlx *mlx, t_data *data, t_point player);
  
// raycasting.c
void	inter_hline(t_data *d, t_ray *r, float ray_rad);
void	inter_vline(t_data *d, t_ray *r, float ray_rad);
void	find_closest_inter(t_data *d, t_ray *ray, t_point *closest_inter);
void	raycasting(t_data *data, t_ray *r);

/******************************************************************************\
* EXECUTION
\******************************************************************************/
   
// render.c
void	my_pixel_put(t_mlx *mlx, int color, int x, int y);
void	clear_window(t_mlx *mlx);
int		render(t_data *data);

// start_screen.c
void	draw_start_screen(t_mlx *mlx, t_game *game);
   
// map_info.c
void	get_map2d(t_map *m);
void	get_map_size(t_map *m);
void	get_map_info(t_map *m);

/******************************************************************************\
 * BONUS
 \******************************************************************************/
 
// collisions.c
int		avoid_collisions(int keycode, t_data *data);

// minimap.c
void	draw_map2d(t_data *data, t_map *map);
void	raycasting_2d(t_data *data, t_ray *r);
int		render_2d(t_data *data);

#endif