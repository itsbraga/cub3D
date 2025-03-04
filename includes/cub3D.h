/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:08:40 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/04 16:29:01 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx/mlx.h"

# include "../LIBFT/INCLUDES/libft.h"
# include "../LIBFT/INCLUDES/ft_printf.h"
# include "structs.h"
# include "defines.h"
# include "colors.h"

/******************************************************************************\
 * PARSING
\******************************************************************************/

// check_map.c
bool	first_verification(char **map, int rows, t_point *start);

// check_rgb.c
bool	valid_rgb(unsigned int rgb[3]);

//map_data.c
void    get_map_data(t_data *data);

/******************************************************************************\
 * TOOLS
\******************************************************************************/

// error.c
void	err_msg(char *detail, char *reason, int quotes);
int		err_msg_cmd(char *cmd, char *detail, char *reason, int err_no);

// cleanup.c
void	free_array(char **array);
void	clean_structs(int exit_status);

// secure.c
void	secure_malloc(void *to_secure, bool cleanup);
void	free_and_set_null(void **to_free);

// draw_tools.c
void	swap_point(t_point *p0, t_point *p1);
bool	valid_point(t_point point, size_t win_x, size_t win_y);

/******************************************************************************\
 * GARBAGE_COLLECTOR
\******************************************************************************/
 
// lst_utils.c
int		remove_gc_node(t_gc_lst**yama, void *ptr);
void	add_gc_node(t_gc_lst **yama, t_gc_lst *node);
void	*new_gc_node(void *ptr, bool is_array);
 
// utils.c
void	*search_ptr(t_gc_lst **yama, void *ptr);
int		handle_remove(t_gc_lst **yama, void *ptr);
int		free_gc_array(t_gc_lst **y, char **array);
 
// garbage_collector.c
void	*yama(int flag, void *ptr, size_t size);

/******************************************************************************\
 * INIT
\******************************************************************************/

// init_aux_structs.c
void	init_data(t_data *data);
void	init_map(t_map *map, t_data *data);
void	init_raycast(t_raycast *ray, t_data *data);
void	init_keys(t_keys *keys, t_data *data);
void	init_structs(t_data *data, t_mlx *mlx);

// init_mlx.c
t_img	*init_texture_img(t_mlx *mlx);
void	init_mlx(t_mlx *mlx, t_data *data);

// singletons.c
t_mlx	*mlx_s(void);
t_data	*data_s(void);

// generate_img.c
t_img	generate_img(char *path_to_file);

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

// move_array.c
void	init_movearray(move_array *functions);
void	update_player_move(t_data *data, t_keys *key);
void	reset_var(t_data *data);

// setter.c
void	set_hooks(t_mlx *mlx, t_data *data);
 
// clean_exit.c
void	del_window(t_mlx *mlx);
void	del_img(t_mlx *mlx);
int		clean_exit(t_mlx *mlx, int err_status);

/******************************************************************************\
 * MATHS
\******************************************************************************/
  
// formulas.c
float	get_radian(int degree);
float	square(float to_square); // pas utilise
float	norm_angle(float angle);

// draw_line.c
void	draw_line(t_img *img, t_point p0, t_point p1, int color);

// raycasting.c
void	intersection_horizontal_line(t_data *d, t_raycast *r, float ray_rad);
void	intersection_vertical_line(t_data *d, t_raycast *r, float ray_rad);
void	find_closest_intersection(t_data *d, t_raycast *ray, t_point *closest_inter);
void	raycasting(t_data *data, t_raycast *r);

/******************************************************************************\
 * RENDER
\******************************************************************************/

// pixels.c
void	my_pixel_put_to_img(t_img *img, int color, int x, int y);
void	clear_img(t_img *img, size_t size_x, size_t size_y, int color);

// render.c
int		render(t_data *data);

/******************************************************************************\
 * EXEC
\******************************************************************************/

// map_info.c
void	get_map_info(t_map *m);

#endif