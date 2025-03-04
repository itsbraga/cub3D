/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:39:53 by u4s2e0r           #+#    #+#             */
/*   Updated: 2025/03/04 15:38:30 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free_and_set_null(&mlx->mlx_ptr);
	// if (full_clean == true);
}

void	free_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free_and_set_null((void **)&array[i]);
		i++;
	}
	free_and_set_null((void **)&array);
}

static void	__free_game(t_game *game)
{
	if (game != NULL)
	{
		if (game->map != NULL)
			free_array(game->map->map2d);
		// if (game->ray != NULL)
			// ?
	}
}

void	clean_structs(int exit_status)
{
	if (mlx_s() != NULL)
		__free_mlx(mlx_s());
	if (game_s() != NULL)
		__free_game(game_s());
	// yama(CLEAN_ALL, NULL, 0);
	exit(exit_status);
}
