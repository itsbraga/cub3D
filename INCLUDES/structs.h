/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:31:53 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/18 17:02:51 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3D.h"

/******************************************************************************\
 * YAMA: Garbage Collector
\******************************************************************************/

typedef struct s_gc_lst
{
	void			*ptr;
	bool			is_array;
	struct s_gc_lst	*next;
}				t_gc_lst;

/******************************************************************************\
 * GRAPHIC LIBRARY
\******************************************************************************/

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;			// bits per line
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;

/******************************************************************************\
 * CUB3D
\******************************************************************************/

typedef enum e_game_state
{
	TITLE_SCREEN = 1,
	GAME = 2
}			t_game_state;

typedef struct s_point
{
	float	x;
	float	y;
}				t_point;

typedef struct s_size
{
	size_t	width;
	size_t	height;
}				t_size;

typedef struct s_layer
{
	t_point	pos;
	t_img	img;
	t_size	size;
}				t_layer;

typedef struct s_title_screen
{
	t_img	first_layer;
	t_layer	second_layer;
}				t_title_screen;

typedef struct s_map
{
	int		fd;
	char	*path_to_file;
	char	**map2d;
	t_size	size;
}				t_map;

typedef struct s_player
{
	int		dir;
	t_point	pos;
	t_point	move;
}				t_player;

typedef struct s_door
{
	t_point		pos;
	int 		state;
	float 		ratio;
}	t_door;

typedef struct s_raycasting
{
	t_point		closest_inter;
	t_point		h_ray_inter;
	t_point		v_ray_inter;
	t_point		h_offset;
	t_point		v_offset;
	float		dist_wall;
	int			wall_start_y;
	int			wall_end_y;
	float		wall_h;
	int			tex_x;
	float		step_tex_y;
	float		offset_tex_y;
	float		shadow_factor;
	bool		vertical_hit;
	bool		is_door;
	float		player_rad;
	uint32_t	fov;
	uint32_t	curr_ray;
}				t_raycasting;

typedef struct s_keys_event
{
	bool	key_array[7];
	bool	mouse_btn[3];
}				t_keys;

typedef struct s_fc_render
{
	t_img	*img;
	int		(*wall_limits)[2];
	int		*tex_buffer;
	float	leftmost_ray_dir_x;
	float	leftmost_ray_dir_y;
	float	rightmost_ray_dir_x;
	float	rightmost_ray_dir_y;
	int		horizon_line;
	float	v_scale_factor;
	int		y;
	float	row_dist;
	float	step_x;
	float	step_y;
	float	start_x;
	float	start_y;
	int		color;
	float	shadow_factor;
}			t_fc_render;

typedef struct s_textures
{
	char	**path;
	t_img	*imgs;
}				t_textures;

typedef struct s_weapon
{
	char		*name;
	int			id;
	int			xpm_count;
	t_textures	sprites;
	int			state;
	bool		frame_counter_started;
	int			frame;			// frame_counter
	t_point		pos;
}				t_weapon;

typedef struct s_data
{
	t_map		*map;
	t_textures	*decor_tex;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	uint32_t	features;
	int			door_nb;
	t_door		*doors;
	t_weapon	**weapons;
	int			weapon_count;
	int			weapon_capacity;
	int			curr_weapon_idx;
}				t_data;

typedef struct s_trigo
{
	float	cos_theta;
	float	sin_theta;
	float	cos_theta_plus_pi2;
	float	sin_theta_plus_pi2;
	float	cos_theta_minus_pi2;
	float	sin_theta_minus_pi2;
}				t_trigo;

typedef struct s_triangle
{
	t_point	a;
	t_point	b;
	t_point	c;
	float	theta;				// line angle
	double	slope1;				// line slope
	double	slope2;
	double	slope3;
	double	curr_x1;			// coordinates of point 1
	double	curr_x2;			// coordinates of point 2
	double	curr_slope1;
	double	curr_slope2;
	t_trigo	trig;
}				t_triangle;

typedef struct s_viewport
{
	int		pixel_width;		// window width
	int		pixel_height;
	int		offset_x;			// offset to center the minimap
	int		offset_y;
	int		perimeter;			// visible area on minimap
	t_point	player_pos;			// player's precise world position (x, y)
	float	scale_factor;		// ratio of world TILE_SIZE to minimap tile_size
}				t_viewport;

typedef struct s_minimap
{
	t_viewport	vp;
	t_img		img;
	t_point		pos;
	float		ratio;			// ratio of minimap to window (%)
	int			width;
	int			height;
	size_t		tile_size;
	int			bg_color;
}				t_minimap;

typedef struct s_game
{
	t_game_state	state;
	t_title_screen	title_screen;
	t_player		*player;
	t_raycasting	*ray;
	t_keys			*keys;
	t_minimap		*mmap;
	t_mlx			*mlx;
	t_data			*data;
}				t_game;

#endif