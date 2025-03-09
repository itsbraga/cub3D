/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:58:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/10 00:38:25 by art3mis          ###   ########.fr       */
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

// utils.c
bool			is_empty_line(char *line);
size_t			get_longest_line(char **map2d, size_t height);
unsigned int	convert_rgb_into_uint(char *red, char *green, char *blue);

// checks/check_arg.c
int		check_cub_file(char *arg);

// checks/check_xpm.c
bool	check_xpm_file(char *arg);

// checks/check_map.c
bool	is_map_line(char *line);
bool	map_fully_enclosed(char **map, size_t height, size_t width,
	t_point pos);

// checks/find_player.c
void	get_player_direction(t_map *map, t_player *player);

// process_file/textures.c
void	process_texture_lines(char *line, t_textures *tex);

// process_file/rgb.c
void	process_color_lines(char *line, t_data *data);

// process_file/map.c
char	**normalize_map2d(char **map, size_t height, size_t width);
void	fill_map2d_array(t_map *map, char *line);

// process_file/get_file_data.c
void	get_file_data(int fd, t_data *data);

// parsing.c
short	parsing(char *arg, t_map *map);

/******************************************************************************\
 * TOOLS
\******************************************************************************/

// error.c
void	err_msg(char *context, char *reason);
void	err_msg_quoted(char *context, char *reason);

// secure.c
void	secure_malloc(void *to_secure, bool full_clean);
void	my_free(void **to_free);

// draw_tools.c
void	swap_point(t_point *p0, t_point *p1);
bool	valid_point(t_point point, size_t win_x, size_t win_y);

// cleanup/free.c
void	free_map(t_map *map);
void	free_array(char **array);
void	free_int_array(int **array);
void	free_title_screen(t_title_screen *screen);

// cleanup/delete_img.c
void	del_img(t_mlx *mlx, void *img_ptr);

// cleanup/cleanup.c
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

// singletons.c
t_mlx	*mlx_s(void);
t_game	*game_s(void);
t_data	*data_s(void);

// init_mlx.c
void	init_mlx(t_mlx *mlx, t_game *game);

// init_textures.c
void	init_textures(t_textures *tex, t_data *data);
void	fill_textures_paths(char *line, t_textures *tex);
short	check_textures_paths(t_textures *tex);

// init_structs.c
void	init_map(t_map *map, char *path_to_file, int fd, t_data *data);
void	init_structs(t_game *game, t_mlx *mlx);

// title_screen/layers.c
void	background(t_title_screen *s);
void	start_button(t_title_screen *s);
void	controls_menu(t_title_screen *s);

// title_screen/init.c
void	init_title_screen(t_title_screen *screen);
void	draw_title_screen(t_game *game, t_mlx *mlx);

/******************************************************************************\
 * EXEC
\******************************************************************************/

// collisions.c
short	handle_collisions(t_player *player, t_point *new_player_pos);

// maths/formulas.c
float	degree_to_radian(int degree);
float	square(float to_square); // pas utilise
float	norm_rad_angle(float angle);
float	norm_angle_h(float angle); // for mouse cursor_x
float	norm_angle_v(float angle); // for mouse cursor_y ---> UNUSED yet

// maths/draw_line.c
void	draw_line(t_img *img, t_point p0, t_point p1, int color);

// maths/raycasting.c
void	intersection_h_line(t_player *player, t_raycasting *r, float ray_rad);
void	intersection_v_line(t_player *player, t_raycasting *r, float ray_rad);
void	find_closest_intersection(t_player *player, t_raycasting *r, 
	t_point *closest_inter);
void	raycasting(t_game *game, t_raycasting *r);

// mlx_hooks/movements.c
void	move_forward(t_player *player);
void	move_backward(t_player *player);
void	straf_leftward(t_player *player);
void	straf_rightward(t_player *player);

// mlx_hooks/camera.c
void	rotate_leftward(t_player *player);
void	rotate_rightward(t_player *player);

// mlx_hooks/move_array.c
void	move_player(t_player *player, t_keys *key);
void	reset_var(t_player *player);

// mlx_hooks/mouse.c
void	set_mouse_hooks(t_mlx *mlx, t_game *game);

// mlx_hooks/setter.c
void	set_hooks(t_mlx *mlx, t_game *game);

// render/xpm_to_mlx_img.c
t_img	xpm_to_mlx_img(char *relative_path);

// render/pixels.c
void	my_pixel_put_to_img(t_img *img, int color, int x, int y);
void	clear_img(t_img *img, size_t size_x, size_t size_y, int color);

// render/draw_player.c
void	draw_player(t_img *minimap, t_player *player);

// render/minimap.c
void	draw_minimap(t_game *game, t_map *minimap);

// render/render.c
int		render(t_game *game);

#endif