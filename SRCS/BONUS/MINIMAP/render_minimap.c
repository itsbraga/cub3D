/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:39:37 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/16 01:41:03 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*
	Calculates the world coordinates corresponding to a minimap pixel
*/
static t_point	__get_world_coords(t_minimap *mmap, t_point pixel)
{
	t_point	world_pos;
	t_point	center_draw;
	float	scale_f;

	center_draw.x = mmap->vp.offset_x + mmap->vp.pixel_width / 2.0f;
	center_draw.y = mmap->vp.offset_y + mmap->vp.pixel_height / 2.0f;
	scale_f = mmap->vp.scale_factor;
	world_pos.x = mmap->vp.player_pos.x + (pixel.x - center_draw.x) * scale_f;
	world_pos.y = mmap->vp.player_pos.y + (pixel.y - center_draw.y) * scale_f;
	return (world_pos);
}

/*
	Processes a single pixel of the minimap: determines its color based
	on the corresponding map tile and world position, then draws it
*/
static void	__process_mmap_pixel(t_minimap *mmap, t_map *map, t_point pixel)
{
	t_point	world_pos;
	int		map_x;
	int		map_y;
	int		color;
	char	tile_type;

	world_pos = __get_world_coords(mmap, pixel);
	map_x = floor(world_pos.x / TILE_SIZE);
	map_y = floor(world_pos.y / TILE_SIZE);
	if (is_within_map_bounds(map_x, map_y, map))
	{
		tile_type = map->map2d[map_y][map_x];
		if (tile_type == '1' || tile_type == '2')
			color = set_mmap_pixel_color(world_pos, tile_type);
		else
			color = mmap->bg_color;
	}
	else
		color = mmap->bg_color;
	if (is_valid_point(pixel, mmap->width, mmap->height))
		my_pixel_put_to_img(&mmap->img, color, pixel.x, pixel.y);
}

/*
	Draws the visible map tiles (walls, doors, background) pixel by pixel
*/
static void	__draw_tiles(t_minimap *mmap, t_map *map)
{
	t_point	pixel;

	pixel.y = mmap->vp.offset_y;
	while (pixel.y < mmap->vp.offset_y + mmap->vp.pixel_height)
	{
		pixel.x = mmap->vp.offset_x;
		while (pixel.x < mmap->vp.offset_x + mmap->vp.pixel_width)
		{
			__process_mmap_pixel(mmap, map, pixel);
			pixel.x++;
		}
		pixel.y++;
	}
}

/*
	Core function to draw the entire minimap content (tiles, player, frame)
*/
static void	__draw_minimap(t_game *game, t_minimap *mmap, t_map *map)
{
	mmap->vp = compute_viewport(mmap);
	mmap->vp.player_pos = game->player->pos;
	__draw_tiles(mmap, map);
	draw_centered_player(game, mmap);
	draw_minimap_frame(mmap);
}

void	render_minimap(t_game *game, t_minimap *mmap)
{
	clear_img(&mmap->img, mmap->width, mmap->height, mmap->bg_color);
	__draw_minimap(game, mmap, game->data->map);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		mmap->img.img_ptr, mmap->pos.x, mmap->pos.y);
}
