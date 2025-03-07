/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:08:40 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/07 20:37:19 by pmateo           ###   ########.fr       */
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

// utils.c
int		rgb_to_int(char *red, char *green, char *blue);

// map_data.c
void	get_map_data(t_data *data, char **argv);

/******************************************************************************\
 * TOOLS
\******************************************************************************/

// error.c
void	err_msg(char *detail, char *reason);
void	err_msg_quoted(char *detail, char *reason);

// secure.c
void	secure_malloc(void *to_secure, bool full_clean);
void	my_free(void **to_free);

// draw_tools.c
void	swap_point(t_point *p0, t_point *p1);
bool	valid_point(t_point point, size_t win_x, size_t win_y);

/******************************************************************************\
 * TOOLS/CLEANUP
\******************************************************************************/

// free.c
void	free_map(t_map *map);
void	free_array(char **array);
void	free_int_array(int **array);
void	free_title_screen(t_title_screen *screen);

// delete_img.c
void	del_img(t_mlx *mlx, void *img_ptr);

// cleanup.c
int		exit_game(t_mlx *mlx, int exit_code);
void	free_mlx(t_mlx *mlx);
void	clean_exit(int exit_code);

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
void	init_game(t_game *game);
void	init_map(t_map *map, t_game *game);
void	init_raycast(t_raycast *ray, t_game *game);
void	init_keys(t_keys *keys, t_game *game);
void	init_structs(t_data *data, t_game *game, t_mlx *mlx);

// init_mlx.c
t_img	*init_texture_img(t_mlx *mlx);
void	init_mlx(t_mlx *mlx, t_game *game);

// singletons.c
t_game	*game_s(void);
t_mlx	*mlx_s(void);
t_data	*data_s(void);

// generate_xpm_from_img.c
t_img	img_from_xpm(char *relative_path);

// title_screen/layers.c
void	background(t_title_screen *s);
void	start_button(t_title_screen *s);
void	controls_menu(t_title_screen *s);

// title_screen/init.c
void	init_title_screen(t_title_screen *screen);
void	draw_title_screen(t_game *game, t_mlx *mlx);

/******************************************************************************\
 * MLX_HOOKS
\******************************************************************************/

// movements.c
void	move_forward(t_game *game, t_data *data); // changer params
void	move_backward(t_game *game, t_data *data); // changer params
void	straf_leftward(t_game *game, t_data *data); // changer params
void	straf_rightward(t_game *game, t_data *data); // changer params

// camera.c
void	rotate_leftward(t_game *game, t_data *data); // changer params
void	rotate_rightward(t_game *game, t_data *data); // changer params

// move_array.c
void	move_player(t_game *game, t_keys *key); // changer params
void	reset_var(t_game *game); // changer params

// setter.c
void	set_hooks(t_mlx *mlx, t_game *game);

/******************************************************************************\
 * MATHS
\******************************************************************************/
  
// formulas.c
float	degree_to_radian(int degree);
float	square(float to_square); // pas utilise
float	norm_rad_angle(float angle);

// draw_line.c
void	draw_line(t_img *img, t_point p0, t_point p1, int color);

// raycasting.c
void	intersection_horizontal_line(t_game *d, t_raycast *r, float ray_rad);
void	intersection_vertical_line(t_game *d, t_raycast *r, float ray_rad);
void	find_closest_intersection(t_game *d, t_raycast *ray,
	t_point *closest_inter);
void	raycasting(t_game *game, t_raycast *r);

/******************************************************************************\
 * RENDER
\******************************************************************************/

// pixels.c
void	my_pixel_put_to_img(t_img *img, int color, int x, int y);
void	clear_img(t_img *img, size_t size_x, size_t size_y, int color);

// render.c
int		render(t_game *game);

/******************************************************************************\
 * EXEC
\******************************************************************************/

// map_info.c
void	get_map_info(t_map *m);

#endif