/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:08:40 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/16 15:08:03 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/**********************\
 *	LIBRARIES
\**********************/

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
# include "../MLX/mlx.h"

# include "../LIBFT/INCLUDES/libft.h"
# include "../LIBFT/INCLUDES/ft_printf.h"
# include "structs.h"
# include "defines.h"
# include "colors.h"
# include "cub3D_bonus.h"

/**********************\
 *	INIT
\**********************/

// singletons.c
t_data	*s_data(void);
t_game	*s_game(void);
t_mlx	*s_mlx(void);

// init_mlx.c
void	init_mlx(t_mlx *mlx, t_game *game);

// init_structs.c
void	init_structs(t_data *data, t_game *game, t_mlx *mlx);

/**********************\
 *	PARSING
\**********************/

// CHECKS/check_arg.c
int		check_cub_file(char *arg);

// CHECKS/check_xpm.c
int		check_xpm_file(char *arg);

// CHECKS/check_all_xpm_paths.c
int		check_mandatory_tex_paths(t_textures *tex);
int		check_bonus_tex_paths(t_textures *tex);
int		check_weapon_sprites_paths(t_weapon *w);

// CHECKS/check_map.c
bool	flood_fill(char **map, int y, int x, t_size size);
char	**normalize_map_for_flood(char **map, t_size size);

// CHECKS/check_player.c
void	get_player_direction(t_map *map, t_player *player);

// PROCESS_FILE/file_processing_utils.c
char	*skip_spaces(char *line);
bool	is_empty_line(char *line);
bool	is_wall_tex_line(char *line);
bool	is_weapon_typename(char *line);
bool	is_sprite_line(char *line);

// PROCESS_FILE/fill_tex_paths.c
char	*get_texture_path(char *line);
void	fill_tex_paths(char *line, t_textures *tex);
void	fill_bonus_tex_paths(char *line, t_textures *tex);

// PROCESS_FILE/decor_textures.c
void	process_mandatory_tex_lines(char *line, t_textures *tex);
void	process_bonus_tex_lines(char *line, t_textures *tex);

// PROCESS_FILE/weapon_utils.c
int		read_sprite_paths(int fd, char **tmp_paths, int max_sprites);
bool	allocate_and_copy_paths(t_weapon *w, char **tmp_paths, int count);
void	expand_weapons_array(t_data *d);
void	load_and_resize_sprites(t_weapon *w);

// PROCESS_FILE/weapon.c
int		process_weapon_sprites(int fd, t_weapon *w, t_data *d);

// PROCESS_FILE/armory_section.c
void	process_armory_section(int fd, t_data *d);

// PROCESS_FILE/color_rgb.c
void	process_color_lines(char *line);

// PROCESS_FILE/map.c
char	**normalize_final_map(char **map, size_t height, size_t width);
void	fill_map2d_array(t_map *map, char *line);

// PROCESS_FILE/map_utils.c
bool	is_map_line(char *line);
bool	is_bonus_map_line(char *line);
size_t	get_longest_line(char **map2d, size_t height);

// PROCESS_FILE/get_file_data.c
void	get_file_data(int fd, t_data *data);

// parse_file.c
int		parse_file(char *arg, t_data *data, t_game *game);

/**********************\
 *	UTILS
\**********************/

// err_msg.c
void	err_msg(char *context, char *reason);
void	err_msg_quoted(char *context, char *reason);

// secure.c
void	secure_malloc(void *to_secure, bool full_clean);
void	free_and_set_null(void **to_free);

// draw_utils.c
void	swap_point(t_point *p0, t_point *p1);
bool	is_valid_point(t_point point, size_t win_width, size_t win_height);
bool	is_within_map_bounds(int x, int y, t_map *map);
bool	is_door(t_data *data, t_point p);

// draw_line.c
void	draw_line(t_img *img, t_point p0, t_point p1, int color);

// img_utils.c
t_img	resize_img(float scale_factor, t_img *to_resize);
t_img	xpm_to_img(char *relative_path);

// our_mlx_utils.c
void	blit_transparent_img(t_img *src, t_img *dest, int img_pos_x,
			int img_pos_y);
void	my_pixel_put_to_img(t_img *img, int color, int x, int y);
void	my_put_img_to_window(t_img *src, t_img *dest, int pos_x, int pos_y);
void	clear_img(t_img *img, size_t size_x, size_t size_y, int color);

// math_formulas.c
float	degree_to_radian(int degree);
float	square(float to_square); // pas utilise
float	norm_rad_angle(float angle);
int		norm_h_angle(int angle);

// CLEANUP/free_array.c
void	free_array(char **array);
void	free_int_array(int **array);

// CLEANUP/free_structs.c
void	free_title_screen(t_title_screen *screen);
void	free_map(t_map *map);
void	free_textures(t_textures *tex);
void	free_bonus_textures(t_textures *tex);
void	free_weapon(t_weapon *w);

// CLEANUP/free_singletons.c
void	free_data(t_data *data);
void	free_game(t_game *game);
void	free_mlx(t_mlx *mlx);

// CLEANUP/delete_img.c
void	del_img(t_mlx *mlx, void *img_ptr);

// CLEANUP/clean_exit.c
int		exit_game(t_mlx *mlx, int exit_code);
void	clean_exit(int exit_code);

/**********************\
 *	GARBAGE
\**********************/

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

/**********************\
 *	TITLE_SCREEN
\**********************/

// layers.c
void	background(t_title_screen *s);
void	start_button(t_title_screen *s);
// void	controls_menu(t_title_screen *s);

// init.c
void	init_title_screen(t_title_screen *screen);
void	draw_title_screen(t_game *game, t_mlx *mlx);

/**********************\
 *	MLX_HOOKS
\**********************/

// movements.c
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	straf_leftward(t_game *game);
void	straf_rightward(t_game *game);

// camera.c
void	rotate_leftward(t_game *game);
void	rotate_rightward(t_game *game);

// move_array.c
void	move_player(t_game *game, t_keys *key);
void	reset_move(t_player *player);

// setter.c
void	set_hooks(t_mlx *mlx, t_game *game);

/**********************\
 *	RENDER
\**********************/

// DRAW/shadow.c
float	calculate_shadow_factor(float distance);
int		apply_shadow_factor(int color, float shadow_factor);

// DRAW/tex_buffer.c
void	load_tex_buffer(int orientation, int *tex_buffer);
void	handle_tex_buffer(int *tex_buffer, t_raycasting *r, float ray_rad);
void	handle_fc_tex_buffer(int orientation, int *tex_buffer);

// DRAW/draw_wall_tex.c
void	draw_wall_tex(t_raycasting *r, float ray_rad);

// DRAW/draw_fc_colors.c
void	draw_floor_color(t_raycasting *r, t_data *d);
void	draw_ceil_color(t_raycasting *r, t_data *d);

// RAYCASTING/raycast_loop.c
void	raycasting(t_data *d, t_player *p, t_raycasting *r);

// RAYCASTING/raycast_inter_h.c
void	inter_hline(t_data *d, t_player *p, t_raycasting *r, float ray_rad);

// RAYCASTING/raycast_inter_v.c
void	inter_vline(t_data *d, t_player *p, t_raycasting *r, float ray_rad);

// RAYCASTING/raycast_utils.c
void	get_draw_info(t_data *data, t_player *player, t_raycasting *r);

// render_frame.c
int		render_frame(t_game *game);

#endif