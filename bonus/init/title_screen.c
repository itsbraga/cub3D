/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:45:00 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/28 01:45:25 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_title_screen(t_title_screen *screen)
{
	screen->bg_img = generate_img("start_img/xpm/teletubbies.xpm");
	screen->start_btn.img = generate_img("start_img/xpm/button.xpm");
	screen->start_btn.pos.x = (WIN_WIDTH - screen->start_btn.img.width) / 2;
	screen->start_btn.pos.y = WIN_HEIGHT - screen->start_btn.img.height - 50;
	screen->start_btn.width = screen->start_btn.img.width;
	screen->start_btn.height = screen->start_btn.img.height;
}

void	draw_title_screen(t_data *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->title_screen.bg_img.img_ptr, 0, 0);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->title_screen.start_btn.img.img_ptr,
		data->title_screen.start_btn.pos.x,
		data->title_screen.start_btn.pos.y);
}
