/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_singletons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:39:53 by u4s2e0r           #+#    #+#             */
/*   Updated: 2025/04/18 07:01:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data != NULL)
	{
		if (data->map != NULL)
			free_map(data->map);
		if (!BONUS && data->decor_tex != NULL)
			free_textures(data->decor_tex);
		if (BONUS && data->decor_tex != NULL)
			free_bonus_textures(data->decor_tex);
		if (BONUS && data->doors != NULL)
			free_and_set_null((void **)&data->doors);
		if (BONUS && data->weapons != NULL)
		{
			while (i < data->weapon_count && data->weapons[i] != NULL)
			{
				if (data->weapons[i] != NULL)
					free_weapon(data->weapons[i]);
				i++;
			}
			free_and_set_null((void **)&data->weapons);
		}
	}
	free_and_set_null((void **)&data);
}

void	free_game(t_game *game)
{
	if (game != NULL)
	{
		if (game->player != NULL)
			free_and_set_null((void **)&game->player);
		if (game->ray != NULL)
			free_and_set_null((void **)&game->ray);
		if (game->keys != NULL)
			free_and_set_null((void **)&game->keys);
		if (game->mmap != NULL)
		{
			if (game->mmap->img.img_ptr != NULL)
				mlx_destroy_image(game->mlx->mlx_ptr, game->mmap->img.img_ptr);
			free_and_set_null((void **)&game->mmap);
		}
	}
	free_and_set_null((void **)&game);
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx != NULL)
	{
		if (mlx->img.img_ptr != NULL)
		{
			ft_printf(STDERR_FILENO, BOLD PY DEL_IMG ": mlx\n" RESET);
			mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
			mlx->img.img_ptr = NULL;
		}
		if (mlx->win_ptr != NULL)
		{
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
			mlx->win_ptr = NULL;
		}
		if (mlx->mlx_ptr != NULL)
		{
			mlx_destroy_display(mlx->mlx_ptr);
			free_and_set_null((void **)&mlx->mlx_ptr);
		}
	}
	free_and_set_null((void **)&mlx);
}
