/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_title_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:45:00 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 15:28:50 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	background(t_title_screen *screen)
{
	screen->bg_img = generate_img("./title_screen/xpm/teletubbies_wblood2.xpm");
	if (screen->bg_img.img_ptr == NULL)
		return (err_msg("Title screen", "Unable to load background image", 0));
}

// void	blood_splashes(t_title_screen *screen)
// {
// 	screen->blood.img = generate_img("./title_screen/xpm/blood_splashes.xpm");
// 	if (screen->blood.img.img_ptr == NULL)
// 	{
// 		del_img(mlx_s(), screen->bg_img.img_ptr);
// 		return (err_msg("Title screen", "Unable to load button image", 0));
// 	}
// 	screen->blood.pos.x = (WIN_WIDTH - screen->blood.img.width) / 2;
// 	screen->blood.pos.y = WIN_HEIGHT - screen->blood.img.height + 80;
// 	screen->blood.width = screen->blood.img.width;
// 	screen->blood.height = screen->blood.img.height;
// }

void	start_button(t_title_screen *screen)
{
	screen->start_button.img = generate_img("./title_screen/xpm/button.xpm");
	if (screen->start_button.img.img_ptr == NULL)
	{
		del_img(mlx_s(), screen->bg_img.img_ptr);
		return (err_msg("Title screen", "Unable to load button image", 0));
	}
	screen->start_button.pos.x = (WIN_WIDTH - screen->start_button.img.width) / 2;
	screen->start_button.pos.y = WIN_HEIGHT - screen->start_button.img.height - 50;
	screen->start_button.width = screen->start_button.img.width;
	screen->start_button.height = screen->start_button.img.height;
}

void	init_title_screen(t_title_screen *screen)
{
	background(screen);
	// blood_splashes(screen);
	start_button(screen);
}

void	draw_title_screen(t_game *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->title_screen.bg_img.img_ptr, 0, 0);
	// mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
	// 	data->title_screen.blood.img.img_ptr,
	// 	data->title_screen.blood.pos.x,
	// 	data->title_screen.blood.pos.y);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->title_screen.start_button.img.img_ptr,
		data->title_screen.start_button.pos.x,
		data->title_screen.start_button.pos.y);
}
