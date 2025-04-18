/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:26:51 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/18 21:25:01 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	_get_door_nb(char **map)
{
	int	nb;
	int	x;
	int	y;

	nb = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '2')
				nb++;
			x++;
		}
		y++;
	}
	return (nb);
}

static void	_get_door_pos(t_door *door, char **map, int door_index)
{
	int	x;
	int	y;
	int	curr_door;

	y = 0;
	curr_door = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '2')
			{
				if (curr_door == door_index)
				{
					door->pos.x = x;
					door->pos.y = y;
				}
				curr_door++;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	init_doors(t_data *d)
{
	int	i;
	int	door_nb;

	i = 0;
	door_nb = _get_door_nb(d->map->map2d);
	if (door_nb == 0)
		return ;
	d->door_nb = door_nb;
	d->doors = malloc(door_nb * sizeof(t_door));
	secure_malloc(d->doors, true);
	while (i < door_nb)
	{
		_get_door_pos(&d->doors[i], d->map->map2d, i);
		d->doors[i].state = CLOSED;
		d->doors[i].ratio = 0.0f;
		i++;
	}
	return ;
}
