/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:26:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 15:28:50 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

// t_img	*init_texture_img(t_mlx *mlx)
// {
// 	t_img *img;

// 	img->img_ptr = mlx_new_image(mlx->mlx_ptr, 64, 64);
// 	if (img->img_ptr == NULL)
// 	{
// 		err_msg("MinilibX", ERR_MLX, 0); // specifier erreur
// 		return (NULL);
// 	}
// 	img->addr = mlx_get_game_addr(img->img_ptr, 
// 			&img->bits_per_pixel,
// 			&img->line_len,
// 			&img->endian);
// 	if (img->addr == NULL)
// 	{
// 		del_img(mlx, img->img_ptr);
// 		err_msg("MinilibX", ERR_MLX, 0);
// 		return (NULL);
// 	}
// 	return (img);
// }

/*	Ajuster la taille de la minimap selon la taille de la window:

	WIN_SIZE (x,y) / (div TILE_SIZE) = MINIMAP_SIZE (x,y)
	WIN_SIZE (x,y) / MINIMAP_SIZE (x,y) = (div TILE_SIZE)
*/
// 960x720
static int	__init_minimap_img(t_mlx *mlx, t_game *data)
{
	data->minimap.img_ptr = mlx_new_image(mlx->mlx_ptr, 256, 256);
	if (data->minimap.img_ptr == NULL)
	{
		err_msg("MinilibX", ERR_MLX, 0); // specifier erreur
		return (FAILURE);
	}
	data->minimap.addr = mlx_get_game_addr(data->minimap.img_ptr, 
			&data->minimap.bits_per_pixel,
			&data->minimap.line_len,
			&data->minimap.endian);
	if (data->minimap.addr == NULL)
	{
		del_img(mlx, data->minimap.img_ptr);
		err_msg("MinilibX", ERR_MLX, 0);
		exit_game(mlx, data->minimap.img_ptr, FAILURE); // a verifier, peut-etre supprimer les deux images
	}
	data->minimap.width = 256;
	data->minimap.height = 256;
	return (SUCCESS);
}

static int	__init_imgs(t_mlx *mlx, t_game *data)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->img.img_ptr == NULL)
	{
		err_msg("MinilibX", ERR_MLX, 0); // specifier erreur
		return (FAILURE);
	}
	mlx->img.addr = mlx_get_game_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, 
			&mlx->img.line_len,
			&mlx->img.endian);
	if (mlx->img.addr == NULL)
	{
		err_msg("MinilibX", ERR_MLX, 0); // specifier erreur
		exit_game(mlx, mlx->img.img_ptr, FAILURE); // a verifier
	}
	if (__init_minimap_img(mlx, data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

void	init_mlx(t_mlx *mlx, t_game *data)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		err_msg("MinilibX", ERR_MLX, 0); // specifier erreur
		exit_game(mlx, mlx->img.img_ptr, FAILURE); // a verifier
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"Telecubbies Horror");
	if (mlx->win_ptr == NULL)
	{
		err_msg("MinilibX", ERR_MLX, 0); // specifier erreur
		del_window(mlx); // ou exit_game(mlx)
	}
	if (__init_imgs(mlx, data) == FAILURE)
		return ;
	data->mlx = mlx;
}
