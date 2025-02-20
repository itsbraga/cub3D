/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:12:07 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/20 19:11:26 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static void	__draw_vgrid(t_mlx *mlx)
{
	t_point p1;
	t_point p2;

	p1.x = (TILE_SIZE / 2);
	p1.y = 0;
	p2.x = (TILE_SIZE / 2);
	p2.y = (W_HEIGHT / 4);
	while (p1.x < (W_WIDTH / 4))
	{
		draw_line(mlx, p1, p2, HBLACK);
		p1.x += (TILE_SIZE / 2);
		p2.x += (TILE_SIZE / 2);
	}
	return ;
}

static void	__draw_hgrid(t_mlx *mlx)
{
	t_point p1;
	t_point p2;

	p1.x = 0;
	p1.y = (TILE_SIZE / 2);
	p2.x = (W_WIDTH / 4);
	p2.y = (TILE_SIZE / 2); 
	while (p1.y < (W_HEIGHT / 4))
	{
		draw_line(mlx, p1, p2, HBLACK);
		p1.y += (TILE_SIZE / 2);
		p2.y += (TILE_SIZE / 2);
	}
	return ;
}

void	draw_grid(t_mlx *mlx)
{
	__draw_hgrid(mlx);
	__draw_vgrid(mlx);
}
