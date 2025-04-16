/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:31:09 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/16 15:13:23 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	trigger_door(t_game *game)
{
	t_data 	*d;
	t_raycasting *r;

	r = game->ray;
	d = game->data;
	printf("doorray_x = %f\ndoorray_y = %f\n", r->door_ray.x, r->door_ray.y);
	printf("cellx = %d\ncelly = %d\n", (int)(r->door_ray.x / TILE_SIZE), (int)(r->door_ray.y / TILE_SIZE));
	if (is_door(game->data, r->door_ray))
	{
		get_door_index(r->door_ray, d);
		if (d->doors[d->door_index].state == CLOSED
			|| d->doors[d->door_index].state == CLOSING)
			d->doors[d->door_index].state = OPENING;
		else if (d->doors[d->door_index].state == OPEN
			|| d->doors[d->door_index].state == OPENING)
			d->doors[d->door_index].state = CLOSING;
	}
}
