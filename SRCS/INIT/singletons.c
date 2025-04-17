/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:01:31 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/17 01:26:52 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	A singleton ensures a class or structure has only
	one instance and provides a global access point
	to it.
*/
t_data	*s_data(void)
{
	static t_data	*instance = NULL;

	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_data));
		secure_malloc(instance, true);
		ft_bzero(instance, sizeof(t_data));
		instance->map = yama(CREATE, NULL, sizeof(t_map));
		secure_malloc(instance->map, true);
		instance->decor_tex = yama(CREATE, NULL, sizeof(t_textures));
		secure_malloc(instance->decor_tex, true);
	}
	return (instance);
}

t_game	*s_game(void)
{
	static t_game	*instance = NULL;

	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_game));
		secure_malloc(instance, true);
		ft_bzero(instance, sizeof(t_game));
		instance->state = TITLE_SCREEN;
		instance->player = yama(CREATE, NULL, sizeof(t_player));
		secure_malloc(instance->player, true);
		instance->ray = yama(CREATE, NULL, sizeof(t_raycasting));
		secure_malloc(instance->ray, true);
		instance->keys = yama(CREATE, NULL, sizeof(t_keys));
		secure_malloc(instance->keys, true);
		if (BONUS)
		{
			instance->mmap = yama(CREATE, NULL, sizeof(t_minimap));
			secure_malloc(instance->mmap, true);
		}
	}
	return (instance);
}

t_mlx	*s_mlx(void)
{
	static t_mlx	*instance = NULL;

	if (instance == NULL)
	{
		instance = malloc(sizeof(t_mlx));
		secure_malloc(instance, true);
		ft_bzero(instance, sizeof(t_mlx));
		ft_bzero(&instance->img, sizeof(t_img));
	}
	return (instance);
}
