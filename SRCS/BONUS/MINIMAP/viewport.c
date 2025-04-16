/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:36:56 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/16 01:41:10 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*
	Computes the viewport parameters for the minimap display.

	The function:
	- Sets the view perimeter (4 tiles in each direction).
	- Calculates the total number of tiles visible horizontally/vertically.
	- Calculates 'tile_size' using integer division based on minimap
	  dimensions and the number of visible tiles, ensuring tiles are
	  square by using the minimum constraint (width or height).
	- Calculates 'scale_factor' relating world size to minimap tile size
	- Calculates the viewport dimensions in pixels ('pixel_width/height')
	- Calculates the offsets required to center the viewport drawing area
	  within the minimap's total dimensions
*/
t_viewport	compute_viewport(t_minimap *mmap)
{
	t_viewport	vp;
	int			visible_tiles;
	size_t		tile_size_w;
	size_t		tile_size_h;

	vp.perimeter = 4;
	visible_tiles = (vp.perimeter * 2) + 1;
	if (visible_tiles > 0)
	{
		tile_size_w = mmap->width / visible_tiles;
		tile_size_h = mmap->height / visible_tiles;
		if (tile_size_w < tile_size_h)
			mmap->tile_size = tile_size_w;
		else
			mmap->tile_size = tile_size_h;
	}
	if (mmap->tile_size > 0)
		vp.scale_factor = (float)TILE_SIZE / mmap->tile_size;
	else
		vp.scale_factor = 1.0;
	vp.pixel_width = visible_tiles * mmap->tile_size;
	vp.pixel_height = visible_tiles * mmap->tile_size;
	vp.offset_x = (mmap->width - vp.pixel_width) / 2;
	vp.offset_y = (mmap->height - vp.pixel_height) / 2;
	return (vp);
}
