/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_setter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 03:28:07 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/16 03:51:51 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	__set_game_mouse_press(int button, int x, int y, t_game *game)
{
	t_layer	start_button;

	start_button = game->title_screen.second_layer;
	if (game->state == TITLE_SCREEN && button == Button1)
	{
		if ((x >= start_button.pos.x && x <= start_button.pos.x
				+ start_button.size.width)
			&& (y >= start_button.pos.y && y <= start_button.pos.y
				+ start_button.size.height))
		{
			game->state = GAME;
			toggle_mouse_visibility(game->mlx, game->state);
		}
	}
	else if (game->state == GAME)
	{
		if (button == Button1)
			game->keys->mouse_buttons[0] = 1;
		else if (button == Button3)
			game->keys->mouse_buttons[1] = 1;
		else if (button == Button2)
			game->keys->mouse_buttons[2] = 1;
	}
	return (SUCCESS);
}

static int	__set_game_mouse_release(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (game->state == GAME)
	{
		if (button == Button1)
			game->keys->mouse_buttons[0] = 0;
		else if (button == Button3)
			game->keys->mouse_buttons[1] = 0;
		else if (button == Button2)
			game->keys->mouse_buttons[2] = 0;
	}
	return (SUCCESS);
}

void	set_mouse_hooks(t_mlx *mlx, t_game *game)
{
	mlx_hook(mlx->win_ptr, ButtonPress, ButtonPressMask,
		&__set_game_mouse_press, game);
	mlx_hook(mlx->win_ptr, ButtonRelease, ButtonReleaseMask,
		&__set_game_mouse_release, game);
	mlx_hook(mlx->win_ptr, MotionNotify, PointerMotionMask,
		&mouse_motion, game);
}
