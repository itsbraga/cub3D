/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:09:54 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/22 04:29:13 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_map(t_map *s)
{
	s->map = malloc(6 * sizeof(char *));
	printf("coucou\n");
	s->map[0] = ft_strdup("111111");
	s->map[1] = ft_strdup("100001");
	s->map[2] = ft_strdup("100101");
	s->map[3] = ft_strdup("100001");
	s->map[4] = ft_strdup("111111");
	s->map[5] = NULL;
}

void	get_map_size(t_map *s)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (s->map[y][x] != '\0')
		x++;
	while (s->map[y] != NULL)
		y++;
	s->M_WIDTH = x;
	s->M_HEIGHT = y;
}

void	get_tiles_size(t_map *map)
{
	map->T_HEIGHT = W_HEIGHT / map->M_HEIGHT;
	map->T_WIDTH = W_WIDTH / map->M_WIDTH;
}

void	draw_tile(t_data *data, t_map *s, size_t tile_x, size_t tile_y)
{
	size_t x;
	size_t y;
	size_t x_end;
	size_t y_end;

	x = tile_x * s->T_WIDTH;
	y = tile_y * s->T_HEIGHT;
	x_end = x + (s->T_WIDTH);
	y_end = y + (s->T_HEIGHT);
	while (y < y_end)
	{
		x = tile_x * s->T_WIDTH;
		while (x < x_end)
		{
			my_pixel_put(data->mlx, HWHITE, x, y);
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *data, t_map *map)
{
	size_t tile_x;
	size_t tile_y;
	
	tile_y = 0;
	get_map(map);
	printf("coucou\n");
	get_map_size(map);
	get_tiles_size(map);
	printf("coucou3\n");
	while (tile_y < map->M_HEIGHT)
	{
		tile_x = 0;
		while (tile_x < map->M_WIDTH)
		{
			if (map->map[tile_y][tile_x] == '1')
			{
				draw_tile(data, map, tile_x, tile_y);
				printf("[%lu][%lu]\n", tile_y, tile_x);
			}
			// printf("tile %lu\n", tile_x + tile_y);
			tile_x++;
		}
		tile_y++;
	}
}