/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:58:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/26 22:03:42 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx/mlx.h"

# include "../LIBFT/INCLUDES/libft.h"
# include "../LIBFT/INCLUDES/ft_printf.h"
# include "structs.h"
# include "defines.h"
# include "tools.h"
# include "colors.h"

/******************************************************************************\
 * PARSING
\******************************************************************************/

// check_map.c
bool	first_verification(char **map, int rows, t_point *start);

// check_rgb.c
bool	valid_rgb(unsigned int rgb[3]);

/******************************************************************************\
 * INIT
\******************************************************************************/

// init_structs.c
void	init_map(t_map *map, t_data *data);
void	init_ray(t_ray *ray, t_data *data);
void	init_keys(t_keys *key, t_data *data);
void	init_game(t_game *game, t_data *data);
void	init_minimap(t_minimap *mini, t_data *data);
void	init_structs(t_data *data, t_mlx *mlx);

// singletons.c
t_mlx	*mlx_s(void);
t_data	*data_s(void);
void	init_data(t_data *data);
void	init_mlx(t_mlx *mlx, t_data *data);

// collisions.c
int		avoid_collisions(t_data *data, t_point *new_player);

/******************************************************************************\
 * CONFIGS/MLX_HOOKS
\******************************************************************************/

// movements.c
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	straf_leftward(t_data *data);
void	straf_rightward(t_data *data);

// camera.c
void	rotate_leftward(t_data *data);
void	rotate_rightward(t_data *data);

// move_tab.c
void	init_movetab(move_tab *functions);
void	handle_movement(t_data *data, t_keys *key);
void	reset_var(t_data *data);

// hooks.c
void	set_hooks(t_mlx *mlx, t_data *data);
 
// mlx_exit.c
void	del_win(t_mlx *mlx);
void	del_img(t_mlx *mlx);
int		exit_game(t_mlx *mlx);
 
/******************************************************************************\
 * MATHS
\******************************************************************************/
  
// formulas.c
float	get_radian(int degree);
float	square(float to_square);
float	norm_angle(float angle);

// draw_line.c
void	draw_line(t_mlx *mlx, t_point p0, t_point p1, int color);
  
// raycasting.c
void	intersection_horizontal_line(t_data *d, t_ray *r, float ray_rad);
void	intersection_vertical_line(t_data *d, t_ray *r, float ray_rad);
void	find_closest_intersection(t_data *d, t_ray *ray, t_point *closest_inter);
void	raycasting(t_data *data, t_ray *r);

/******************************************************************************\
 * EXEC
\******************************************************************************/
   
// render.c
int		render(t_data *data);

// start_screen.c
void	draw_start_screen(t_mlx *mlx, t_game *game);
   
// map_info.c
void	get_map_info(t_map *m);

/******************************************************************************\
 * MINIMAP
\******************************************************************************/

// draw_miniline.c
void	draw_miniline(t_mlx *mlx, t_point p0, t_point p1, int color);

// draw_miniplayer.c
void	draw_miniplayer(t_mlx *mlx, t_data *data, t_point player);

// minimap.c
int		render_minimap(t_data *data, t_minimap *mini);

#endif