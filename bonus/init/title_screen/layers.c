/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_screen_layers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:15:26 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/04 18:06:58 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	background(t_title_screen *screen)
{
	screen->bg_img = xpm_from_img("./title_screen/xpm/teletubbies_wblood2.xpm");
	if (screen->bg_img.img_ptr == NULL)
		return (err_msg("Title screen", "Unable to load background image", 0));
}

void	start_button(t_title_screen *screen)
{
	screen->start_button.img = xpm_from_img("./title_screen/xpm/button.xpm");
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

void	controls_menu(t_title_screen *screen);
