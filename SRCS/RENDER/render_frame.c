/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:09:28 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/15 18:44:12 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render_frame(t_game *game)
{
	t_mlx	*mlx;
	t_data	*data;

	mlx = game->mlx;
	data = game->data;
	if (game->state == TITLE_SCREEN)
		draw_title_screen(game, mlx);
	else if (game->state == GAME)
	{
		move_player(game, game->keys);
		reset_move(game->player);
		clear_img(&mlx->img, WIN_WIDTH, WIN_HEIGHT, GRAY_PIX);
		raycasting(data, game->player, game->ray);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img.img_ptr, 0, 0);
		if (BONUS)
		{
			render_minimap(game, game->mmap);
			if (data->weapon_count > 0)
				render_curr_weapon(game);
		}
	}
	return (SUCCESS);
}
