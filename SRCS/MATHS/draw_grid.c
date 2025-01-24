/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:12:07 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/24 16:34:03 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_vgrid(t_mlx *mlx, t_map *m)
{
	t_point p1;
	t_point p2;

	p1.x = m->T_WIDTH;
	p1.y = 0;
	p2.x = m->T_WIDTH;
	p2.y = W_HEIGHT;
	while (p1.x < W_WIDTH)
	{
		draw_line(mlx, p1, p2, HWHITE);
		p1.x += m->T_WIDTH;
		p2.x += m->T_WIDTH;
	}
}

void draw_hgrid(t_mlx *mlx, t_map *m)
{
	t_point p1;
	t_point p2;

	p1.x = 0;
	p1.y = m->T_HEIGHT;
	p2.x = W_WIDTH;
	p2.y = m->T_HEIGHT; 
	while (p1.y < W_HEIGHT)
	{
		draw_line(mlx, p1, p2, HWHITE);
		p1.y += m->T_HEIGHT;
		p2.y += m->T_HEIGHT;
	}
}

void	draw_grid(t_data *data)
{
	draw_hgrid(data->mlx, data->map);
	draw_vgrid(data->mlx, data->map);
}