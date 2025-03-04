/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:51:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/04 15:28:50 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	render(t_game *data)
{
	if (data->game_state == STATE_TITLE)
		draw_title_screen(data);
	else if (data->game_state == STATE_GAME)
	{
		get_map_info(data->map);
		clear_img(&mlx_s()->img, WIN_WIDTH, WIN_HEIGHT, BLACK_PIX);
		raycasting(data, data->ray);
		draw_minimap(data, data->map);
		mlx_put_image_to_window(mlx_s()->mlx_ptr, mlx_s()->win_ptr,
				mlx_s()->img.img_ptr, 0, 0);
		mlx_put_image_to_window(mlx_s()->mlx_ptr, mlx_s()->win_ptr,
				data->minimap.img_ptr,
				data->minimap_pos.x, data->minimap_pos.y);
	}
	return (SUCCESS);
}
