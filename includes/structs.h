/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:31:53 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/28 00:42:36 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/******************************************************************************\
 * GRAPHIC LIBRARY
\******************************************************************************/

typedef struct s_img
{
	char	*name;
	void	*img_ptr;
	char	*addr;
	int		bpp;
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
}				t_vector;

typedef struct s_map
{
	char			**map2d;
	size_t			MAP_HEIGHT; // MAP
	size_t			MAP_WIDTH; 
}				t_map;

typedef struct s_ray
{
	unsigned int	ray_amount;
	t_vector		h_ray_inter;
	t_vector		v_ray_inter;
	t_vector		h_offset;
	t_vector		v_offset;
	float			dist_wall;
	unsigned int	fov;
	float			player_rad;
}				t_raycast;

typedef enum e_state
{
	STATE_TITLE = 1,
	STATE_GAME = 2
}			t_state;

typedef struct s_button
{
	t_vector	pos;
	t_img		img;
	size_t		width;
	size_t		height;
}				t_button;

typedef struct s_title_screen
{
	t_img		bg_img;
	t_button	start_btn;
}				t_title_screen;

typedef	struct s_keys_event
{
	bool	key_tab[6];
}				t_keys;

typedef struct s_data
{
	t_mlx			*mlx;
	t_state			game_state;
	char			*map_path;
	t_map			*map;
	t_raycast		*ray;
	char			texture[4]; // peut-etre 5 pour les portes
	unsigned int	f_rgb[3]; // peut-etre mettre floor et ceiling ensemble
	unsigned int	c_rgb[3];
	int				player_dir;
	t_vector		player;
	t_vector		move; // peut-etre ajouter ptr
	t_keys			*keys;
	t_title_screen	title_screen;
	t_img			minimap;
	t_vector		minimap_pos;
}				t_data;

/******************************************************************************\
 * YAMA: Garbage collector
\******************************************************************************/

typedef struct s_gc_lst
{
	void			*ptr;
	bool			is_tab;
	struct s_gc_lst	*next;
}				t_gc_lst;

#endif