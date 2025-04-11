/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_singletons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:39:53 by u4s2e0r           #+#    #+#             */
/*   Updated: 2025/04/10 14:59:59 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_data(t_data *data)
{
	if (data != NULL)
	{
		if (data->map != NULL)
			free_map(data->map);
		// if (data->texture != NULL)
		// 	del_img(s_mlx(), data->texture->img_ptr); x4
	}
}

void	free_game(t_game *game)
{
	if (game != NULL)
	{
		// if (game->player != NULL)
		//
		// if (game->keys != NULL)
		// 	// free_keys func
	}
}

void	free_mlx(t_mlx *mlx)
{
	ft_printf(STDERR_FILENO, BOLD PY MLX_EXIT RESET);
	if (mlx != NULL)
	{
		if (mlx->img.img_ptr != NULL)
			mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
		if (mlx->win_ptr != NULL)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->mlx_ptr != NULL)
		{
			mlx_destroy_display(mlx->mlx_ptr);
			free(mlx->mlx_ptr);
			mlx->mlx_ptr = NULL;
		}
	}
}
