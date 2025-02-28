/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:47:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/28 23:30:05 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	__draw_tile(t_point tile)
{
	t_point	pixel;
	t_point	end;

	pixel.x = tile.x * (TILE_SIZE / 4);
	pixel.y = tile.y * (TILE_SIZE / 4);
	end.x = pixel.x + (TILE_SIZE / 4);
	end.y = pixel.y + (TILE_SIZE / 4);
	while (pixel.y < end.y)
	{
		pixel.x = tile.x * (TILE_SIZE / 4);
		while (pixel.x < end.x)
		{
			my_pixel_put_to_img(&data_s()->minimap, WHITE_PIX,
					pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

void	draw_minimap(t_data *data, t_map *minimap)
{
	t_point	tile;

	tile.y = 0;
	data->minimap_pos.x = WIN_WIDTH - data->minimap.width - 20;
	data->minimap_pos.y = WIN_HEIGHT - data->minimap.height - 20;
	clear_img(&data->minimap, data->minimap.width, data->minimap.height,
			GRAY_PIX);
	while (tile.y < minimap->MAP_HEIGHT)
	{
		tile.x = 0;
		while (tile.x < minimap->MAP_WIDTH)
		{
			if (minimap->map2d[(int)tile.y][(int)tile.x] == '1')
				__draw_tile(tile);
			tile.x++;
		}
		tile.y++;
	}
	draw_player_pos(data, data->player);
}
