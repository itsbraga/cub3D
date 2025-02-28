/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:09:28 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/27 23:19:49 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render(t_data *data)
{
	printf("Game state: %d\n", data->game_state);
	// if (data->game_state == STATE_TITLE)
	// 	draw_start_screen(mlx_s(), data->game);
	// else
	// {
		clear_img(&mlx_s()->img, WIN_WIDTH, WIN_HEIGHT, BLACK_PIX);
		get_map_info(data->map);
		raycasting(data, data->ray);
		printf("play.pos.x = %f | play.pos.y = %f\n", data->player.x, data->player.y);
		mlx_put_image_to_window(mlx_s()->mlx_ptr, mlx_s()->win_ptr,
			mlx_s()->img.img_ptr, 0, 0);
	// }
	return (SUCCESS);
}
