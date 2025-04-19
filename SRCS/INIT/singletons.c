/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:01:31 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/19 03:08:49 by annabrag         ###   ########.fr       */
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
		instance = malloc(sizeof(t_data));
		secure_singleton(instance);
		ft_bzero(instance, sizeof(t_data));
		instance->map = malloc(sizeof(t_map));
		secure_singleton(instance->map);
		instance->decor_tex = malloc(sizeof(t_textures));
		secure_singleton(instance->decor_tex);
	}
	return (instance);
}

t_game	*s_game(void)
{
	static t_game	*instance = NULL;

	if (instance == NULL)
	{
		instance = malloc(sizeof(t_game));
		secure_singleton(instance);
		ft_bzero(instance, sizeof(t_game));
		instance->state = TITLE_SCREEN;
		instance->player = malloc(sizeof(t_player));
		secure_singleton(instance->player);
		instance->ray = malloc(sizeof(t_raycasting));
		secure_singleton(instance->ray);
		instance->keys = malloc(sizeof(t_keys));
		secure_singleton(instance->keys);
		if (BONUS)
		{
			instance->mmap = malloc(sizeof(t_minimap));
			secure_singleton(instance->mmap);
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
		secure_singleton(instance);
		ft_bzero(instance, sizeof(t_mlx));
		ft_bzero(&instance->img, sizeof(t_img));
	}
	return (instance);
}
