/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:26:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 19:26:28 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__init_img(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->img.img_ptr == NULL)
	{
		err_msg("MinilibX", ERR_MLX, 0); // specifier erreur
		del_img(mlx); // a verifier
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel,
			&mlx->img.line_len,
			&mlx->img.endian);
	if (mlx->img.addr == NULL)
	{
		err_msg("MinilibX", ERR_MLX, 0); // specifier erreur
		clean_exit(mlx, FAILURE); // a verifier
	}
}

void	init_mlx(t_mlx *mlx, t_game *game)
{
	(void)game;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		err_msg("MinilibX", ERR_MLX, 0); // specifier erreur
		clean_exit(mlx, FAILURE); // a verifier
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"Telecubbies");
	if (mlx->win_ptr == NULL)
	{
		err_msg("MinilibX", ERR_MLX, 0); // specifier erreur
		del_window(mlx); // ou clean_exit(mlx) // a verifier
	}
	__init_img(mlx);
	// game->mlx = mlx;
}
