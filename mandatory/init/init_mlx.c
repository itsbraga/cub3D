/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:26:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/28 01:52:11 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__init_img(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->img.img_ptr == NULL)
	{
		err_msg("MLX", ERR_MLX, 0); // specifier erreur
		del_img(mlx); // a verifier
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bpp,
			&mlx->img.line_len,
			&mlx->img.endian);
	if (mlx->img.addr == NULL)
	{
		err_msg("MLX", ERR_MLX, 0); // specifier erreur
		exit_game(mlx, FAILURE); // a verifier
	}
}

void	init_mlx(t_mlx *mlx, t_data *data)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		err_msg("MLX", ERR_MLX, 0); // specifier erreur
		exit_game(mlx, FAILURE); // a verifier
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			mlx->img.name);
	if (mlx->win_ptr == NULL)
	{
		err_msg("MLX", ERR_MLX, 0); // specifier erreur
		del_win(mlx); // ou exit_game(mlx) // a verifier
	}
	__init_img(mlx);
	data->mlx = mlx;
}
