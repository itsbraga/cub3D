/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:31:53 by pmateo            #+#    #+#             */
/*   Updated: 2024/12/02 19:28:58 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_data
{
	char	*map_path;
	char	**map;
	char	*tex_path[4];
	int		f_rgb[3];
	int		c_rgb[3];
}				t_data;

typedef struct	s_mlx
{
	void		*mlxptr;
	void		*winptr;
	void		*img;
	char		*imgbuf;
	int			img_bpp;
	int			img_len;
	int			img_endian;
}				t_mlx;

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