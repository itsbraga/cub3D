/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:36:16 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/14 23:09:14 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	__collision_detected(t_data *data, int cell_x, int cell_y)
{
	if (cell_x < 0 || cell_x >= (int)data->map->size.width
		|| cell_y < 0 || cell_y >= (int)data->map->size.height)
		return (false);
	if (data->map->map2d[cell_y][cell_x] == '1')
	{
		printf(BOLD "[WALL] " RED COLLISION_WARN RESET);
		return (true);
	}
	else if (data->map->map2d[cell_y][cell_x] == '2')
	{
		printf(BOLD PY "[DOOR] " RED COLLISION_WARN RESET);
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
static bool	__check_corners_collision(t_data *data, t_point pos)
{
	t_point	corners[4];
	float	buffer;
	int		i;
	int		cell_x;
	int		cell_y;

	buffer = TILE_SIZE / 32;
	corners[0] = (t_point){pos.x - buffer, pos.y - buffer};
	corners[1] = (t_point){pos.x + buffer, pos.y - buffer};
	corners[2] = (t_point){pos.x - buffer, pos.y + buffer};
	corners[3] = (t_point){pos.x + buffer, pos.y + buffer};
	i = 0;
	while (i < 4)
	{
		cell_x = (int)(corners[i].x / TILE_SIZE);
		cell_y = (int)(corners[i].y / TILE_SIZE);
		if (__collision_detected(data, cell_x, cell_y))
			return (true);
		i++;
	}
	return (false);
}

bool	is_position_colliding(t_data *data, t_point pos)
{
	int	cell_x;
	int	cell_y;

	if (pos.x < 0 || pos.x >= data->map->size.width * TILE_SIZE
		|| pos.y < 0 || pos.y >= data->map->size.height * TILE_SIZE)
		return (true);
	cell_x = (int)(pos.x / TILE_SIZE);
	cell_y = (int)(pos.y / TILE_SIZE);
	if (__collision_detected(data, cell_x, cell_y))
		return (true);
	if (__check_corners_collision(data, pos))
		return (true);
	return (false);
}
