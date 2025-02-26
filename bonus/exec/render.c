/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:09:28 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/26 21:16:41 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	render(t_data *data)
{
	t_mlx	*mlx;
	
	mlx = mlx_s();
	printf("Game state: %d\n", data->game->game_state);

	// if (data->game != NULL && data->game->game_state == STATE_TITLE)
	// 	draw_start_screen(mlx, data->game);
	// else
	// {
		clear_window(mlx, WIN_WIDTH, WIN_HEIGHT, BLACK_PIX);
		get_map_info(data->map);
		raycasting(data, data->ray);
		printf("play.pos.x = %f | play.pos.y = %f\n", data->player.x, data->player.y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img_ptr, 0, 0);
	// }
	return (SUCCESS);
}
