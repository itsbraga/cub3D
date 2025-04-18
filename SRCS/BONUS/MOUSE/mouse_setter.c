/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_setter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 03:28:07 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/17 20:46:59 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

// toggle_mouse_visibility(game->mlx, game->state);
static int	__set_game_mouse_press(int button, int x, int y, t_game *game)
{
	t_layer	start_btn;

	start_btn = game->title_screen.second_layer;
	if (game->state == TITLE_SCREEN && button == Button1)
	{
		if ((x >= start_btn.pos.x && x <= start_btn.pos.x
				+ start_btn.size.width)
			&& (y >= start_btn.pos.y && y <= start_btn.pos.y
				+ start_btn.size.height))
		{
			game->state = GAME;
		}
	}
	else if (game->state == GAME)
	{
		if (button == Button1)
			game->keys->mouse_btn[0] = 1;
		else if (button == Button3)
			game->keys->mouse_btn[1] = 1;
		else if (button == Button2)
			game->keys->mouse_btn[2] = 1;
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
			game->keys->mouse_btn[0] = 0;
		else if (button == Button3)
			game->keys->mouse_btn[1] = 0;
		else if (button == Button2)
			game->keys->mouse_btn[2] = 0;
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
