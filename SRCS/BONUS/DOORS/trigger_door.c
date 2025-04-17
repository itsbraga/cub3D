/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:31:09 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/17 00:07:53 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static t_point	__set_check_pos(t_player *p, t_raycasting *r)
{
	t_point	check_pos;

	check_pos.x = p->pos.x + cos(r->player_rad) * (TILE_SIZE * 1.30);
	check_pos.y = p->pos.y + sin(r->player_rad) * (TILE_SIZE * 1.30);
	return (check_pos);
}

static t_point	__set_door_pos(int cell_x, int cell_y)
{
	t_point	door_pos;

	door_pos.x = cell_x * TILE_SIZE + TILE_SIZE / 2;
	door_pos.y = cell_y * TILE_SIZE + TILE_SIZE / 2;
	return (door_pos);
}

static bool	__is_door(int cell_x, int cell_y, t_data *d)
{
	if (cell_x >= 0 && (size_t)cell_x < d->map->size.width
		&& cell_y >= 0 && (size_t)cell_y < d->map->size.height
		&& d->map->map2d[cell_y][cell_x] == '2')
		return (true);
	else
		return (false);
}

void	trigger_door(t_game *g)
{
	t_point			check_pos;
	t_point			door_pos;
	int				cell_x;
	int				cell_y;
	int				index;

	index = 0;
	check_pos = __set_check_pos(g->player, g->ray);
	cell_x = (int)(check_pos.x / TILE_SIZE);
	cell_y = (int)(check_pos.y / TILE_SIZE);
	if (__is_door(cell_x, cell_y, g->data) == true)
	{
		door_pos = __set_door_pos(cell_x, cell_y);
		index = get_door_index(door_pos, g->data);
		if (g->data->doors[index].state == CLOSED
			|| g->data->doors[index].state == CLOSING)
			g->data->doors[index].state = OPENING;
		else if (g->data->doors[index].state == OPEN
			|| g->data->doors[index].state == OPENING)
			g->data->doors[index].state = CLOSING;
	}
}
