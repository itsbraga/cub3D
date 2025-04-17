/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:38:51 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/16 20:49:34 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*
	Checks if a world coordinate falls on the border zone of its tile
	@return: true if the position is within the border size distance of any
			 tile edge
			 false otherwise

	The function:
	- Defines a border size based on a fraction of TILE_SIZE (1/20th)
	- Calculates the position of the world coordinate within its tile using
	  floorf and subtraction
	- Calculates the position of the far edge (right/bottom) based on TILE_SIZE
	  and the border size
*/
static bool	__is_border_pixel(t_point world)
{
	float	border_size;
	t_point	pos_in_tile;
	t_point	tile_start;
	float	edge_of_tile;

	border_size = (float)TILE_SIZE / 20.0f;
	tile_start.x = floorf(world.x / TILE_SIZE) * TILE_SIZE;
	pos_in_tile.x = world.x - tile_start.x;
	tile_start.y = floorf(world.y / TILE_SIZE) * TILE_SIZE;
	pos_in_tile.y = world.y - tile_start.y;
	edge_of_tile = TILE_SIZE - border_size;
	if (pos_in_tile.x < border_size || pos_in_tile.x >= edge_of_tile
		|| pos_in_tile.y < border_size || pos_in_tile.y >= edge_of_tile)
		return (true);
	return (false);
}

int	set_mmap_pixel_color(t_point world, char type)
{
	if (__is_border_pixel(world) == true)
		return (GRAY_PIX);
	if (type == '1')
		return (WHITE_PIX);
	else
		return (MANDARINE_PIX);
}

/*
	Draws a red border frame around the minimap.
*/
void	draw_minimap_frame(t_minimap *mmap)
{
	t_point	p0;
	t_point	p1;
	int		color;

	color = RED_PIX;
	p0 = (t_point){.x = 0, .y = 0};
	p1 = (t_point){.x = mmap->width - 1, .y = 0};
	draw_line(&mmap->img, p0, p1, color);
	p0 = (t_point){.x = mmap->width - 1, .y = 0};
	p1 = (t_point){.x = mmap->width - 1, .y = mmap->height - 1};
	draw_line(&mmap->img, p0, p1, color);
	p0 = (t_point){.x = mmap->width - 1, .y = mmap->height - 1};
	p1 = (t_point){.x = 0, .y = mmap->height - 1};
	draw_line(&mmap->img, p0, p1, color);
	p0 = (t_point){.x = 0, .y = mmap->height - 1};
	p1 = (t_point){.x = 0, .y = 0};
	draw_line(&mmap->img, p0, p1, color);
}
