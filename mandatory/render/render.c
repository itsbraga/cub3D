/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:09:28 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 19:39:03 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render(t_game *game)
{
	if (game->game_state == STATE_TITLE)
		draw_title_screen(game, mlx_s());
	else if (game->game_state == STATE_GAME)
	{
		get_map_info(game->map);
		clear_img(&mlx_s()->img, WIN_WIDTH, WIN_HEIGHT, BLACK_PIX);
		raycasting(game, game->ray);
		// printf("play.pos.x = %f | play.pos.y = %f\n", game->player_pos.x, game->player_pos.y);
		mlx_put_image_to_window(mlx_s()->mlx_ptr, mlx_s()->win_ptr,
				mlx_s()->img.img_ptr, 0, 0);
	}
	return (SUCCESS);
}
