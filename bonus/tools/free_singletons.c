/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_singletons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:39:53 by u4s2e0r           #+#    #+#             */
/*   Updated: 2025/03/04 15:32:02 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	__free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free_and_set_null(&mlx->mlx_ptr);
	// if (full_clean == true);
}

static void	__free_data(t_game *data)
{
	if (data != NULL)
	{
		if (data->map != NULL)
			free_array(data->map->map2d);
		// if (data->ray != NULL)
			// ?
	}
}

void	singletons_cleanup(int exit_status)
{
	if (mlx_s() != NULL)
		__free_mlx(mlx_s());
	if (game_s() != NULL)
		__free_data(game_s());
	// yama(CLEAN_ALL, NULL, 0);
	exit(exit_status);
}
