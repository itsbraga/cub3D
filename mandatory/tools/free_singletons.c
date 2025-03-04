/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_singletons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:39:53 by u4s2e0r           #+#    #+#             */
/*   Updated: 2025/03/04 19:34:00 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__free_mlx(t_mlx *mlx) // semblable a clean_exit --> a check
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free_and_set_null((void **)mlx->mlx_ptr);
}

static void	__free_game(t_game *game)
{
	if (game != NULL)
	{
		if (game->map != NULL)
			free_array(game->map->map2d);
		// if (game->keys != NULL)
		// 	// free_keys func
	}
}

static void	__free_data(t_data *data)
{
	if (data != NULL)
	{
		if (data->cubfile_path != NULL)
			free_and_set_null((void **)data->cubfile_path);
		// if (data->texture != NULL)
		// 	// free_array func for int
	}
}

void	free_singletons(int exit_status)
{
	if (mlx_s() != NULL)
		__free_mlx(mlx_s());
	if (game_s() != NULL)
		__free_game(game_s());
	if (data_s() != NULL)
		__free_data(data_s());
	// yama(CLEAN_ALL, NULL, 0);
	exit(exit_status);
}
