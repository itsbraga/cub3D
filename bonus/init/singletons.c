/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:01:31 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 15:32:02 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*	A singleton ensures a class or structure has only
	one instance and provides a global access point
	to it.
*/
t_game	*game_s(void)
{
	static t_game	*instance = NULL;

	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_game));
		secure_malloc(instance, true);
		instance->mlx = NULL;
		instance->map = yama(CREATE, NULL, sizeof(t_map));
		secure_malloc(instance->map, true);
		instance->ray = yama(CREATE, NULL, sizeof(t_raycast));
		secure_malloc(instance->ray, true);
		instance->fd = -1;
		instance->texture = NULL;
		instance->floor_color = 0;
		instance->ceiling_color = 0;
		instance->keys = yama(CREATE, NULL, sizeof(t_keys));
		secure_malloc(instance->keys, true);
	}
	return (instance);
}

t_mlx	*mlx_s(void)
{
	static t_mlx	*instance = NULL;
	
	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_mlx));
		secure_malloc(instance, true);
		instance->mlx_ptr = NULL;
		instance->win_ptr = NULL;
		instance->img.img_ptr = NULL;
		instance->img.addr = NULL;
		instance->img.bits_per_pixel = 0;
		instance->img.line_len = 0;
		instance->img.endian = 0;
	}
	return (instance);
}
