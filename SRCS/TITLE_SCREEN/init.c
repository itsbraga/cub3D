/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:45:00 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/18 18:15:58 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// add: controls_menu(screen);
void	init_title_screen(t_title_screen *screen)
{
	background(screen);
	start_button(screen);
}

void	draw_title_screen(t_game *g, t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		g->title_screen.first_layer.img_ptr, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		g->title_screen.second_layer.img.img_ptr,
		g->title_screen.second_layer.pos.x,
		g->title_screen.second_layer.pos.y);
}
