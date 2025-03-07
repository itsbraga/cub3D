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

#include "cub3D_bonus.h"

// t_img	*init_texture_img(t_mlx *mlx)
// {
// 	t_img *img;

// 	img->img_ptr = mlx_new_image(mlx->mlx_ptr, 64, 64);
// 	if (img->img_ptr == NULL)
// 	{
// 		err_msg("minilibX", ERR_IMG);
// 		return (NULL);
// 	}
// 	img->addr = mlx_get_data_addr(img->img_ptr, 
// 			&img->bits_per_pixel,
// 			&img->size_line,
// 			&img->endian);
// 	if (img->addr == NULL)
// 	{
// 		del_img(mlx, img->img_ptr);
// 		err_msg("minilibX", ERR_ADDR);
// 		return (NULL);
// 	}
// 	return (img);
// }

/*	Ajuster la taille de la minimap selon la taille de la window:

	WIN_SIZE (x,y) / (div TILE_SIZE) = MINIMAP_SIZE (x,y)
	WIN_SIZE (x,y) / MINIMAP_SIZE (x,y) = (div TILE_SIZE)
*/
static int	__init_minimap_img(t_mlx *mlx, t_game *game)
{
	game->minimap.img_ptr = mlx_new_image(mlx->mlx_ptr, 256, 256);
	if (game->minimap.img_ptr == NULL)
	{
		err_msg("minilibX", ERR_IMG);
		return (FAILURE);
	}
	game->minimap.addr = mlx_get_data_addr(game->minimap.img_ptr, 
			&game->minimap.bits_per_pixel,
			&game->minimap.size_line,
			&game->minimap.endian);
	if (game->minimap.addr == NULL)
	{
		del_img(mlx, game->minimap.img_ptr);
		free_mlx(mlx);
		return (err_msg("minilibX", ERR_ADDR), FAILURE);
		 // check si ok pour minimap
		 // a verifier, peut-etre supprimer les deux images
	}
	game->minimap.width = 256;
	game->minimap.height = 256;
	return (SUCCESS);
}

static int	__init_imgs(t_mlx *mlx, t_game *game)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->img.img_ptr == NULL)
	{
		err_msg("minilibX", ERR_IMG);
		return (FAILURE);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, 
			&mlx->img.size_line,
			&mlx->img.endian);
	if (mlx->img.addr == NULL)
	{
		free_mlx(mlx);
		return (err_msg("minilibX", ERR_ADDR), FAILURE);
		// a verifier, peut-etre supprimer les deux images
	}
	if (__init_minimap_img(mlx, game) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

void	init_mlx(t_mlx *mlx, t_game *game)
{
	(void)game;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		free_mlx(mlx);
		return (err_msg("minilibX", ERR_MLX));
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, W_NAME);
	if (mlx->win_ptr == NULL)
	{
		free_mlx(mlx);
		return (err_msg("minilibX", ERR_WIN));
	}
	if (__init_imgs(mlx, game) == FAILURE)
		return ;
}
