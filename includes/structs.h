/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:31:53 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/04 11:36:43 by pmateo           ###   ########.fr       */
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
	int		line_len;
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

typedef struct s_vector
{
	float		x;
	float		y;
}				t_point;

typedef struct s_map
{
	char		**map2d;
	size_t		height;
	size_t		width; 
}				t_map;

typedef struct s_ray
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

typedef enum e_state
{
	STATE_TITLE = 1,
	STATE_GAME = 2
}			t_state;

typedef struct s_layer
{
	t_point		pos;
	t_img		img;
	size_t		width;
	size_t		height;
}				t_layer;

typedef struct s_title_screen
{
	t_img		bg_img;
	t_layer		blood;
	t_layer		start_button;
}				t_title_screen;

typedef	struct s_keys_event
{
	bool	key_array[6];
}				t_keys;

typedef struct s_data
{
	t_mlx			*mlx;
	t_state			game_state;
	t_map			*map;
	t_raycast		*ray;
	char			*cubfile_path;
	int				fd;
	int				**texture;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	int				player_dir;
	t_point			player;
	t_point			move; // peut-etre ajouter ptr
	t_keys			*keys;
	t_title_screen	title_screen;
	t_img			minimap;
	t_point			minimap_pos;
}				t_data;

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