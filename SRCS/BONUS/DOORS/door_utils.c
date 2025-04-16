/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 02:52:25 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/16 15:12:41 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	get_door_index(t_point pos, t_data *d)
{
	int i;
	int	pos_x;
	int pos_y;
	int door_x;
	int door_y;

	i = 0;
	pos_x = (int)(pos.x / TILE_SIZE);
	pos_y = (int)(pos.y / TILE_SIZE);
	while (i < d->door_nb)
	{
		door_x = (int)d->doors[i].pos.x;
		door_y = (int)d->doors[i].pos.y;
		if (pos_x == door_x && pos_y == door_y)
		{
			d->door_index = i;
			return ;
		}
		i++;
	}
	d->door_index = -1;
	return ;
}

void	reset_door_ray(t_raycasting *r)
{
	r->door_ray.x = 0.0f;
	r->door_ray.y = 0.0f;
}
