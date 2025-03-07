/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:26:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/07 11:48:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__init_img(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->img.img_ptr == NULL)
		err_msg("minilibX", ERR_IMG);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel,
			&mlx->img.size_line,
			&mlx->img.endian);
	if (mlx->img.addr == NULL)
	{
		err_msg("minilibX", ERR_ADDR);
		del_img(mlx, mlx->img.img_ptr);
		mlx_exit(mlx, FAILURE); // a verifier
	}
}

void	init_mlx(t_mlx *mlx, t_game *game)
{
	(void)game;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		err_msg("minilibX", ERR_MLX);
		mlx_exit(mlx, FAILURE); // a verifier
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, W_NAME);
	if (mlx->win_ptr == NULL)
	{
		err_msg("minilibX", ERR_WIN);
		mlx_exit(mlx, FAILURE); // a verifier
	}
	__init_img(mlx);
}
