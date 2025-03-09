/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:09:28 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/09 22:54:43 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_textures(t_data *data)
{
	data->textures[NO] = img_from_xpm("./maps/mandat_valid_test/textures/LAB_2B.xpm");
	data->textures[SO] = img_from_xpm("./maps/mandat_valid_test/textures/TECH_4E.xpm");
	data->textures[WE] = img_from_xpm("./maps/mandat_valid_test/textures/PIPES_1A.xpm");
	data->textures[EA] = img_from_xpm("./maps/mandat_valid_test/textures/CONSOLE_1B.xpm");
}

int	render(t_game *game)
{
	// if (game->game_state == STATE_TITLE)
	// 	draw_title_screen(game, mlx_s());
	// else if (game->game_state == STATE_GAME)
	// {
		get_map_info(data_s()->map);
		get_textures(data_s());
		clear_img(&mlx_s()->img, WIN_WIDTH, WIN_HEIGHT, BLACK_PIX);
		raycasting(game, game->ray);
		// printf("play.pos.x = %f | play.pos.y = %f\n", game->player_pos.x, game->player_pos.y);
		mlx_put_image_to_window(mlx_s()->mlx_ptr, mlx_s()->win_ptr,
				mlx_s()->img.img_ptr, 0, 0);
	// }
	return (SUCCESS);
}
