/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:31:53 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/04 21:13:40 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int		*img_buff;
	int			bpp;
	int			line_len;
	int			endian;
}	t_mlx;

typedef struct	s_data
{
	char			*map_path;
	char			**map;
	char			texture[4];
	unsigned int	f_rgb[3];
	unsigned int	c_rgb[3];
	t_mlx			*mlx;
}				t_data;

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

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