/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:36:16 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 21:18:13 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static t_door	*__get_door_at(t_data *d, int cell_x, int cell_y)
{
	int	i;

	i = 0;
	while (i < d->door_nb)
	{
		if ((int)d->doors[i].pos.x == cell_x
			&& (int)d->doors[i].pos.y == cell_y)
			return (&d->doors[i]);
		i++;
	}
	return (NULL);
}

static bool	__collision_detected(t_data *d, int cell_x, int cell_y)
{
	t_door	*door;

	if (cell_x < 0 || cell_x >= (int)d->map->size.width
		|| cell_y < 0 || cell_y >= (int)d->map->size.height)
		return (false);
	if (d->map->map2d[cell_y][cell_x] == '1')
		return (ft_printf(2, BOLD"[WALL] "RED COLLISION_WARN RESET), 1);
	else if (d->map->map2d[cell_y][cell_x] == '2')
	{
		door = __get_door_at(d, cell_x, cell_y);
		if (door != NULL)
		{
			if (door->ratio >= 0.85f && door->ratio <= 1.0f)
				return (false);
			return (ft_printf(2, BOLD PY"[DOOR] "RED COLLISION_WARN RESET), 1);
		}
		return (true);
	}
	return (false);
}

/*
	[0] Top-left corner
	[1] Top-right corner
	[2] Bottom-left corner
	[3] Bottom-right corner

	Variable:
	- buffer: The larger the buffer, the further the player is from the wall
*/
static bool	__check_corners_collision(t_data *d, t_point pos)
{
	t_point	corners[4];
	float	buffer;
	int		i;
	int		cell_x;
	int		cell_y;

	buffer = TILE_SIZE / 20;
	corners[0] = (t_point){pos.x - buffer, pos.y - buffer};
	corners[1] = (t_point){pos.x + buffer, pos.y - buffer};
	corners[2] = (t_point){pos.x - buffer, pos.y + buffer};
	corners[3] = (t_point){pos.x + buffer, pos.y + buffer};
	i = 0;
	while (i < 4)
	{
		cell_x = (int)(corners[i].x / TILE_SIZE);
		cell_y = (int)(corners[i].y / TILE_SIZE);
		if (__collision_detected(d, cell_x, cell_y))
			return (true);
		i++;
	}
	return (false);
}

bool	is_position_colliding(t_data *d, t_point pos)
{
	int	cell_x;
	int	cell_y;

	if (pos.x < 0 || pos.x >= d->map->size.width * TILE_SIZE
		|| pos.y < 0 || pos.y >= d->map->size.height * TILE_SIZE)
		return (true);
	cell_x = (int)(pos.x / TILE_SIZE);
	cell_y = (int)(pos.y / TILE_SIZE);
	if (__collision_detected(d, cell_x, cell_y))
		return (true);
	if (__check_corners_collision(d, pos))
		return (true);
	return (false);
}
