/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:31:53 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/26 21:28:03 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/******************************************************************************\
 * GRAPHIC LIBRARY
\******************************************************************************/

typedef struct s_img
{
	char	*img_buff;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

// changer la struct en ajoutant t_img
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	// t_img	img;
	void	*img_ptr;
	char	*img_buff;
	int		bpp;
	int		line_len;
	int		endian;
}				t_mlx;

/******************************************************************************\
 * CUB3D
\******************************************************************************/

typedef struct s_point
{
	float	x;
	float	y;
}				t_point;

typedef struct s_map
{
	char		**map2d;
	size_t		M_HEIGHT; // MAP
	size_t		M_WIDTH; 
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
}				t_ray;

typedef enum e_state
{
	STATE_TITLE,
	STATE_GAME
}			t_state;

// pour l'ecran titre (start_screen) a revoir
typedef struct s_game
{
	t_state		game_state;
	t_point		button;
	int			width;
	int			height;
}				t_game;

typedef	struct s_keys_event
{
	bool	key_tab[6];
}				t_keys;

// supprimer et remplacer par une t_img dans 
typedef struct s_minimap
{
	void	*img_ptr;
	void	*img_buff;
}				t_minimap;

typedef struct s_data
{
	char			*map_path;
	t_map			*map;
	t_ray			*ray;
	char			texture[4];
	unsigned int	f_rgb[3];
	unsigned int	c_rgb[3];
	int				player_dir;
	t_point			player;
	t_point			move; // peut-etre ajouter ptr
	t_mlx			*mlx;
	t_game			*game;
	t_keys			*keys;
	t_minimap		*minimap; 
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