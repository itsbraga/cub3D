/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:47:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 19:38:12 by annabrag         ###   ########.fr       */
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
			my_pixel_put_to_img(&game_s()->minimap, WHITE_PIX,
					pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

void	draw_minimap(t_game *game, t_map *minimap)
{
	t_point	tile;

	tile.y = 0;
	game->minimap_pos.x = WIN_WIDTH - game->minimap.width - 20;
	game->minimap_pos.y = WIN_HEIGHT - game->minimap.height - 20;
	clear_img(&game->minimap, game->minimap.width, game->minimap.height,
			GRAY_PIX);
	while (tile.y < minimap->height)
	{
		tile.x = 0;
		while (tile.x < minimap->width)
		{
			if (minimap->map2d[(int)tile.y][(int)tile.x] == '1')
				__draw_tile(tile);
			tile.x++;
		}
		tile.y++;
	}
	draw_player_pos(game, game->player_pos);
}
