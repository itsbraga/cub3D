/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_door.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 03:01:44 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/13 03:13:40 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

bool	can_vray_pass_door(t_point ray, t_data *d)
{
	int	tile_y;
	float	normalized_pos_y;
	int	door_index;

	door_index = get_door_index(ray, d);
	tile_y = (int)ray.y / TILE_SIZE;
	normalized_pos_y = (ray.y - (tile_y * TILE_SIZE)) / TILE_SIZE;
	if (normalized_pos_y > (1.0f - d->doors[door_index].ratio))
		return (true);
	return (false);
}

bool	can_hray_pass_door(t_point ray, t_data *d)
{
	int	tile_x;
	float	normalized_pos_x;
	int	door_index;

	door_index = get_door_index(ray, d);
	tile_x = (int)ray.x / TILE_SIZE;
	normalized_pos_x = (ray.x - (tile_x * TILE_SIZE)) / TILE_SIZE;
	if (normalized_pos_x > (1.0f - d->doors[door_index].ratio))
		return (true);
	return (false);
}

static void	__open_door(t_door *door)
{
	if (door->ratio < 1)
		door->ratio += DOOR_SBF;
	if (door->ratio >= 1)
	{
		door->ratio = 1;
		door->state = OPEN;
	}
}

static void	__close_door(t_door *door)
{
	if (door->ratio > 0)
		door->ratio -= DOOR_SBF;
	if (door->ratio <= 0)
	{
		door->ratio = 0;
		door->state = CLOSED;
	}
}

void handle_doors(int door_nb, t_door *doors)
{
	int i;

	i = 0;
	if (door_nb == -1)
		return ;
	while (i < door_nb)
	{
		if (doors[i].state == OPENING)
			__open_door(&doors[i]);
		else if (doors[i].state == CLOSING)
			__close_door(&doors[i]);
		// printf("door[%d].ratio = %f\n", i, doors[i].ratio);
		i++;
	}
}
