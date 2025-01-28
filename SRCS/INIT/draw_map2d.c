/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:09:54 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/28 18:52:34 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_map2d(t_map *m)
{
	m->map2d = malloc(7 * sizeof(char *));
	m->map2d[0] = ft_strdup("1111111111");
	m->map2d[1] = ft_strdup("1010000001");
	m->map2d[2] = ft_strdup("1010001001");
	m->map2d[3] = ft_strdup("1010001001");
	m->map2d[4] = ft_strdup("1000000001");
	m->map2d[5] = ft_strdup("1111111111");
	m->map2d[6] = NULL;
}

void	get_map_size(t_map *m)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (m->map2d[y][x] != '\0')
		x++;
	while (m->map2d[y] != NULL)
		y++;
	m->M_WIDTH = x;
	m->M_HEIGHT = y;
}

void	get_tiles_size(t_map *m)
{
	m->T_HEIGHT = (W_HEIGHT + m->M_HEIGHT / 2) / m->M_HEIGHT;
	m->T_WIDTH = (W_WIDTH + m->M_WIDTH / 2) / m->M_WIDTH;
}

void	draw_tile(t_data *data, t_map *m, t_point tile)
{
	t_point	pixel;
	size_t	x_end;
	size_t	y_end;

	pixel.x = tile.x * m->T_WIDTH;
	pixel.y = tile.y * m->T_HEIGHT;
	x_end = pixel.x + (m->T_WIDTH);
	y_end = pixel.y + (m->T_HEIGHT);
	while (pixel.y < y_end)
	{
		pixel.x = tile.x * m->T_WIDTH;
		while (pixel.x < x_end)
		{
			my_pixel_put(data->mlx, HLAVENDER, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

void	draw_map2d(t_data *data, t_map *m)
{
	t_point	tile;
	
	tile.y = 0;
	get_map2d(m);
	get_map_size(m);
	get_tiles_size(m);
	while (tile.y < m->M_HEIGHT)
	{
		tile.x = 0;
		while (tile.x < m->M_WIDTH)
		{
			if (m->map2d[(int)tile.y][(int)tile.x] == '1')
				draw_tile(data, m, tile);
			tile.x++;
		}
		tile.y++;
	}
}
