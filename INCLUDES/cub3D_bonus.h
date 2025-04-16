/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:37:13 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/16 19:41:04 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3D.h"

/**************************\
 *	COLLISIONS
\**************************/

// collisions.c
bool		is_position_colliding(t_data *data, t_point pos);

/**************************\
 *	MINIMAP
\**************************/

// minimap_utils.c
int			set_mmap_pixel_color(t_point world, char type);
void		draw_minimap_frame(t_minimap *mmap);

// init.c
void		init_minimap(t_minimap *mmap, t_game *game);

// triangle_utils.c
void		init_triangle(t_triangle *tr, t_point a, t_point b, t_point c);
void		draw_hline(t_minimap *mmap, t_triangle *tr, int start_y, int end_y);

// draw_triangle.c
void		fill_triangle(t_minimap *mmap, t_point a, t_point b, t_point c);

// draw_player.c
void		draw_centered_player(t_game *game, t_minimap *mmap);

// viewport.c
t_viewport	compute_viewport(t_minimap *mmap);

// render_minimap.c
void		render_minimap(t_game *game, t_minimap *mmap);

/**********************\
 *	DOORS
\**********************/

// door_utils.c
void		reset_door_ray(t_raycasting *r);
int			get_door_index(t_point pos, t_data *d);

// init_door.c
void		init_doors(t_data *data);

// door_movements.c
bool		can_vray_pass_door(t_point ray, t_data *d);
bool		can_hray_pass_door(t_point ray, t_data *d);
void 		handle_doors(int door_nb, t_door *doors);

// trigger_door.c
void		trigger_door(t_game *game);

/**************************\
 *	MOUSE
\**************************/

// mouse.c
void		toggle_mouse_visibility(t_mlx *mlx, t_game_state state);
int			mouse_motion(int x, int y, t_game *game);

// mouse_setter.c
void		set_mouse_hooks(t_mlx *mlx, t_game *game);

/**************************\
 *	ANIMATIONS
\**************************/

// create_weapon.c
int			set_weapon_id(char *name);
t_weapon	*new_weapon(char *name);

// draw_weapon.c
void		draw_weapon(int state, t_weapon *w, t_game *game);

// mp40.c
void		render_mp40(t_game *game, t_weapon *w);

// glock21.c
void		render_glock21(t_game *game, t_weapon *w);

// weapon_array.c
void		render_curr_weapon(t_game *game);

// shoot.c
void		shoot(t_game *game);

/**************************\
 *	ADDITIONAL_TEXTURES
\**************************/

// fc_render_utils.c
void		init_fc_render(t_fc_render *fc, t_raycasting *r,
		int (*wall_limits)[2]);
void		draw_hline_pixels(t_fc_render *fc);

// draw_fc_tex.c
void		draw_floor_tex(t_raycasting *r, int wall_limits[WIN_WIDTH][2],
		t_player *player);
void		draw_ceil_tex(t_raycasting *r, int wall_limits[WIN_WIDTH][2],
		t_player *player);

#endif