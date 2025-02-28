/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:26:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/28 01:49:42 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	__init_imgs(t_mlx *mlx, t_data *data)
{
	// MAP
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->img.img_ptr == NULL)
		(err_msg("MLX", ERR_MLX, 0), del_img(mlx));
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bpp, 
			&mlx->img.line_len,
			&mlx->img.endian);
	if (mlx->img.addr == NULL)
		(err_msg("MLX", ERR_MLX, 0), exit_game(mlx, FAILURE)); // a verifier
	// MINIMAP superposee
	data->minimap.img_ptr = mlx_new_image(mlx->mlx_ptr, 250, 250);
	if (data->minimap.img_ptr == NULL)
		(err_msg("MLX", ERR_MLX, 0), del_img(data->minimap.img_ptr));
	data->minimap.addr = mlx_get_data_addr(data->minimap.img_ptr, 
			&data->minimap.bpp,
			&data->minimap.line_len,
			&data->minimap.endian);
	if (data->minimap.addr == NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, data->minimap.img_ptr);
		(err_msg("MLX", ERR_MLX, 0), exit_game(mlx, FAILURE)); // a verifier
	}
	data->minimap.width = 250;
	data->minimap.height = 250;
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
	__init_imgs(mlx, data);
	data->mlx = mlx;
}
