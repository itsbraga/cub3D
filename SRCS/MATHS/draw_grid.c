/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:12:07 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/31 04:55:19 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_vgrid(t_mlx *mlx)
{
	t_point p1;
	t_point p2;

	p1.x = TILE_SIZE;
	p1.y = 0;
	p2.x = TILE_SIZE;
	p2.y = W_HEIGHT;
	while (p1.x < W_WIDTH)
	{
		draw_line(mlx, p1, p2, HWHITE);
		p1.x += TILE_SIZE;
		p2.x += TILE_SIZE;
	}
}

void draw_hgrid(t_mlx *mlx)
{
	t_point p1;
	t_point p2;

	p1.x = 0;
	p1.y = TILE_SIZE;
	p2.x = W_WIDTH;
	p2.y = TILE_SIZE; 
	while (p1.y < W_HEIGHT)
	{
		draw_line(mlx, p1, p2, HWHITE);
		p1.y += TILE_SIZE;
		p2.y += TILE_SIZE;
	}
}

void	draw_grid(t_data *data)
{
	draw_hgrid(data->mlx);
	draw_vgrid(data->mlx);
}