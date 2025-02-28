/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_title_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:45:00 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/28 22:24:45 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	init_title_screen(t_title_screen *screen)
{
	/******************** BACKGROUND ********************/
	printf("Loading background: ./start_img/xpm/teletubbies.xpm\n");
	if (access("./start_img/xpm/teletubbies.xpm", F_OK) == -1)
	{
		err_msg("Title screen", "Background image file not found", 0);
		return (FAILURE);
	}
	screen->bg_img = generate_img("./start_img/xpm/teletubbies.xpm");
	if (screen->bg_img.img_ptr == NULL)
	{
		err_msg("Title screen", "Unable to load background image", 0);
		return (FAILURE);
	}

	/******************* START BUTTON *******************/
	printf("Loading button: ./start_img/xpm/button.xpm\n");	
	if (access("./start_img/xpm/button.xpm", F_OK) == -1)
	{
		err_msg("Title screen", "Button image file not found", 0);
		del_img(mlx_s(), screen->bg_img.img_ptr);
		return (FAILURE);
	}
	screen->start_btn.img = generate_img("./start_img/xpm/button.xpm");
	if (screen->start_btn.img.img_ptr == NULL)
	{
		del_img(mlx_s(), screen->bg_img.img_ptr);
		err_msg("Title screen", "Unable to load button image", 0);
		return (FAILURE);
	}
	screen->start_btn.pos.x = (WIN_WIDTH - screen->start_btn.img.width) / 2;
	screen->start_btn.pos.y = WIN_HEIGHT - screen->start_btn.img.height - 50;
	screen->start_btn.width = screen->start_btn.img.width;
	screen->start_btn.height = screen->start_btn.img.height;
	
	printf(BOLD GREEN "\nTitle screen successfully initialized\n" RESET);
	return (SUCCESS);
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
