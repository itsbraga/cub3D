/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_singletons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:39:53 by u4s2e0r           #+#    #+#             */
/*   Updated: 2025/04/18 18:16:01 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_data(t_data *d)
{
	int	i;

	i = 0;
	if (d != NULL)
	{
		if (d->map != NULL)
			free_map(d->map);
		if (!BONUS && d->decor_tex != NULL)
			free_textures(d->decor_tex);
		if (BONUS && d->decor_tex != NULL)
			free_bonus_textures(d->decor_tex);
		if (BONUS && d->doors != NULL)
			free_and_set_null((void **)&d->doors);
		if (BONUS && d->weapons != NULL)
		{
			while (i < d->weapon_count && d->weapons[i] != NULL)
			{
				if (d->weapons[i] != NULL)
					free_weapon(d->weapons[i]);
				i++;
			}
			free_and_set_null((void **)&d->weapons);
		}
	}
	free_and_set_null((void **)&d);
}

void	free_game(t_game *g)
{
	if (g != NULL)
	{
		if (g->player != NULL)
			free_and_set_null((void **)&g->player);
		if (g->ray != NULL)
			free_and_set_null((void **)&g->ray);
		if (g->keys != NULL)
			free_and_set_null((void **)&g->keys);
		if (g->mmap != NULL)
		{
			if (g->mmap->img.img_ptr != NULL)
				mlx_destroy_image(g->mlx->mlx_ptr, g->mmap->img.img_ptr);
			free_and_set_null((void **)&g->mmap);
		}
	}
	free_and_set_null((void **)&g);
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
