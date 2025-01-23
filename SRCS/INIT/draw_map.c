/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:09:54 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/23 19:01:12 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_map(t_map *m)
{
	m->map = malloc(7 * sizeof(char *));
	printf("coucou\n");
	m->map[0] = ft_strdup("1111111111");
	m->map[1] = ft_strdup("1010000001");
	m->map[2] = ft_strdup("1010001001");
	m->map[3] = ft_strdup("1010001001");
	m->map[4] = ft_strdup("1000000001");
	m->map[5] = ft_strdup("1111111111");
	m->map[6] = NULL;
}

void	get_map_size(t_map *m)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (m->map[y][x] != '\0')
		x++;
	while (m->map[y] != NULL)
		y++;
	m->M_WIDTH = x;
	m->M_HEIGHT = y;
}

void	get_tiles_size(t_map *m)
{
	m->T_HEIGHT = (W_HEIGHT + m->M_HEIGHT / 2) / m->M_HEIGHT;
	m->T_WIDTH = (W_WIDTH + m->M_WIDTH / 2) / m->M_WIDTH;
}

void	draw_tile(t_data *data, t_map *m, size_t tile_x, size_t tile_y)
{
	size_t x;
	size_t y;
	size_t x_end;
	size_t y_end;

	x = tile_x * m->T_WIDTH;
	y = tile_y * m->T_HEIGHT;
	x_end = x + (m->T_WIDTH);
	y_end = y + (m->T_HEIGHT);
	while (y < y_end)
	{
		x = tile_x * m->T_WIDTH;
		while (x < x_end)
		{
			my_pixel_put(data->mlx, HLAVENDER, x, y);
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *data, t_map *m)
{
	size_t tile_x;
	size_t tile_y;
	
	tile_y = 0;
	get_map(m);
	printf("coucou\n");
	get_map_size(m);
	get_tiles_size(m);
	printf("coucou3\n");
	while (tile_y < m->M_HEIGHT)
	{
		tile_x = 0;
		while (tile_x < m->M_WIDTH)
		{
			if (m->map[tile_y][tile_x] == '1')
			{
				draw_tile(data, m, tile_x, tile_y);
				printf("[%lu][%lu]\n", tile_y, tile_x);
			}
			// printf("tile %lu\n", tile_x + tile_y);
			tile_x++;
		}
		tile_y++;
	}
}
