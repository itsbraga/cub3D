/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:15:54 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/08 22:52:43 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_2D.h"

static void	__draw_vgrid(t_mlx *mlx, float scale, t_map *map)
{
	t_point	p1;
	t_point	p2;
	float	scaled_tile;
	float	max_x;

	scaled_tile = TILE_SIZE * scale;
	max_x = map->size.width * scaled_tile;
	p1.x = scaled_tile;
	p1.y = 0;
	p2.x = scaled_tile;
	p2.y = map->size.height * scaled_tile;
	while (p1.x < max_x)
	{
		draw_line(&mlx->img, p1, p2, BLACK_PIX);
		p1.x += scaled_tile;
		p2.x += scaled_tile;
	}
}

static void	__draw_hgrid(t_mlx *mlx, float scale, t_map *map)
{
	t_point	p1;
	t_point	p2;
	float	scaled_tile;
	float	max_y;

	scaled_tile = TILE_SIZE * scale;
	max_y = map->size.height * scaled_tile;
	p1.x = 0;
	p1.y = scaled_tile;
	p2.x = map->size.width * scaled_tile;
	p2.y = scaled_tile;
	while (p1.y < max_y)
	{
		draw_line(&mlx->img, p1, p2, BLACK_PIX);
		p1.y += scaled_tile;
		p2.y += scaled_tile;
	}
}

void	draw_grid(t_mlx *mlx, float scale, t_map *map)
{
	__draw_hgrid(mlx, scale, map);
	__draw_vgrid(mlx, scale, map);
}
