/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:01:31 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/02 17:35:30 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*	A singleton ensures a class or structure has only
	one instance and provides a global access point
	to it.
*/
t_data	*data_s(void)
{
	static t_data	*instance = NULL;

	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_data));
		secure_malloc(instance, true);
		instance->mlx = NULL;
		instance->game_state = STATE_TITLE;
		instance->map = yama(CREATE, NULL, sizeof(t_map));
		secure_malloc(instance->map, true);
		instance->ray = yama(CREATE, NULL, sizeof(t_raycast));
		secure_malloc(instance->ray, true);
		instance->fd_cubfile = -1;
		ft_bzero(instance->texture, 4);
		instance->floor_color = NULL;
		instance->ceiling_color = NULL;
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
		instance->img.name = "Telecubbies";
	}
	return (instance);
}
