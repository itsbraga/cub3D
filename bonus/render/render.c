/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:51:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/04 19:38:28 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	render(t_game *game)
{
	if (game->game_state == STATE_TITLE)
		draw_title_screen(game, mlx_s());
	else if (game->game_state == STATE_GAME)
	{
		get_map_info(game->map);
		clear_img(&mlx_s()->img, WIN_WIDTH, WIN_HEIGHT, BLACK_PIX);
		raycasting(game, game->ray);
		draw_minimap(game, game->map);
		mlx_put_image_to_window(mlx_s()->mlx_ptr, mlx_s()->win_ptr,
				mlx_s()->img.img_ptr, 0, 0);
		mlx_put_image_to_window(mlx_s()->mlx_ptr, mlx_s()->win_ptr,
				game->minimap.img_ptr,
				game->minimap_pos.x, game->minimap_pos.y);
	}
	return (SUCCESS);
}
