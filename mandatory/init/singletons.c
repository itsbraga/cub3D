/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:01:31 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 19:27:17 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		// instance->mlx = NULL;
		instance->game_state = STATE_TITLE;
		instance->map = yama(CREATE, NULL, sizeof(t_map));
		secure_malloc(instance->map, true);
		instance->ray = yama(CREATE, NULL, sizeof(t_raycast));
		secure_malloc(instance->ray, true);
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

t_data	*data_s(void)
{
	static t_data	*instance = NULL;

	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_data));
		secure_malloc(instance, true);
		instance->cubfile_path = NULL;
		instance->fd = -1;
		instance->texture = NULL;
		instance->floor_color = 0;
		instance->ceiling_color = 0;
		instance->player_dir = S; // a remplacer par 0 puis set selon pos dans le .cub
	}
	return (instance);
}
