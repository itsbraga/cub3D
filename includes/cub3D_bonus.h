/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:58:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/04 19:33:31 by annabrag         ###   ########.fr       */
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

/******************************************************************************\
 * TOOLS
\******************************************************************************/

// error.c
void	err_msg(char *detail, char *reason, int quotes);
int		err_msg_cmd(char *cmd, char *detail, char *reason, int err_status);

// free.c
void	free_array(char **array);
void	free_title_screen(t_title_screen *screen);

// free_singletons.c
void	free_singletons(int exit_status);

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

// init_structs.c
void	init_game(t_game *game);
void	init_map(t_map *map, t_game *game);
void	init_raycast(t_raycast *ray, t_game *game);
void	init_keys(t_keys *keys, t_game *game);
void	init_structs(t_game *game, t_mlx *mlx);

// init_mlx.c
void	init_mlx(t_mlx *mlx, t_game *game);

// singletons.c
t_mlx	*mlx_s(void);
t_game	*game_s(void);
t_data	*data_s(void);;

// generate_xpm_from_img.c
t_img	xpm_from_img(char *relative_path);

// title_screen/layers.c
void	background(t_title_screen *screen);
void	start_button(t_title_screen *screen);
void	controls_menu(t_title_screen *screen);

// title_screen/init.c
void	init_title_screen(t_title_screen *screen);
void	draw_title_screen(t_game *game, t_mlx *mlx);

/******************************************************************************\
 * MLX_HOOKS
\******************************************************************************/

// movements.c
void	move_forward(t_game *game, t_data *data);
void	move_backward(t_game *game, t_data *data);
void	straf_leftward(t_game *game, t_data *data);
void	straf_rightward(t_game *game, t_data *data);

// camera.c
void	rotate_leftward(t_game *game, t_data *data);
void	rotate_rightward(t_game *game, t_data *data);

// move_array.c
void	update_player_move(t_game *game, t_keys *key);
void	reset_var(t_game *game);

// mouse.c
void	set_mouse_hooks(t_mlx *mlx, t_data *data, t_game *game);

// setter.c
void	set_hooks(t_mlx *mlx, t_game *game, t_data *data);

// clean_exit.c
void	del_window(t_mlx *mlx);
void	del_img(t_mlx *mlx, void *img_ptr);
// int		clean_exit(t_mlx *mlx, void *img_ptr, int err_status);
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

// draw_player_pos.c
void	draw_player_pos(t_game *game, t_point player_pos);

// minimap.c
void	draw_minimap(t_game *game, t_map *minimap);

// render.c
int		render(t_game *game);

/******************************************************************************\
 * EXEC
\******************************************************************************/

// map_info.c
void	get_map_info(t_map *m);

// collisions.c
int		handle_collisions(t_game *game, t_point *new_player_pos);
// int		handle_collisions(t_game *game, t_collision *col);

#endif