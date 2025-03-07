/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:31:53 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/07 21:42:56 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/******************************************************************************\
 * GRAPHIC LIBRARY
\******************************************************************************/

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
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

typedef enum e_state
{
	STATE_TITLE = 1,
	STATE_GAME = 2
}			t_state;

typedef struct s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct s_layer
{
	t_point		pos;
	t_img		img;
	size_t		width;
	size_t		height;
}				t_layer;

typedef struct s_title_screen
{
	t_img		first_layer;
	t_layer		second_layer;
}				t_title_screen;

typedef struct s_map
{
	char		*path_to_file;
	int			fd;
	char		**map2d;
	size_t		height;
	size_t		width;
}				t_map;

typedef struct s_player
{
	int			dir;
	t_point		pos;
	t_point		move;
	// int			pitch; // garder si mouse_y OK
}				t_player;

typedef struct s_raycasting
{
	unsigned int	ray_amount;
	t_point			h_ray_inter;
	t_point			v_ray_inter;
	t_point			h_offset;
	t_point			v_offset;
	float			dist_wall;
	unsigned int	fov;
	float			player_rad;
}				t_raycast;

typedef struct s_collision
{
	t_point		next_player_pos;
	t_point		next_cell;
	float		safety_radius; // not used yet
}				t_collision;

typedef	struct s_keys_event
{
	bool	key_array[6];
}				t_keys;

typedef struct s_data
{
	t_map			*map;
	t_img			*texture;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	unsigned int	feature_filled;
}				t_data;

typedef struct s_game
{
	t_state			game_state;
	t_title_screen	title_screen;
	t_player		*player;
	t_raycast		*ray;
	t_keys			*keys;
	t_collision		collision;
	t_img			minimap;
	t_point			minimap_pos;
}				t_game;

/******************************************************************************\
 * YAMA: Garbage collector
\******************************************************************************/

typedef struct s_gc_lst
{
	void			*ptr;
	bool			is_array;
	struct s_gc_lst	*next;
}				t_gc_lst;

#endif