/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_setter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 03:28:07 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 22:31:22 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	__set_game_mouse_press(int button, int x, int y, t_game *g)
{
	t_layer	start_btn;

	start_btn = g->title_screen.second_layer;
	if (g->state == TITLE_SCREEN && button == Button1)
	{
		if ((x >= start_btn.pos.x && x <= start_btn.pos.x
				+ start_btn.size.width)
			&& (y >= start_btn.pos.y && y <= start_btn.pos.y
				+ start_btn.size.height))
		{
			g->state = GAME;
			toggle_mouse_visibility(g->mlx, g->state);
		}
	}
	else if (g->state == GAME)
	{
		if (button == Button1)
			g->keys->mouse_btn[0] = 1;
		else if (button == Button3)
			g->keys->mouse_btn[1] = 1;
		else if (button == Button2)
			g->keys->mouse_btn[2] = 1;
	}
	return (SUCCESS);
}

static int	__set_game_mouse_release(int button, int x, int y, t_game *g)
{
	(void)x;
	(void)y;
	if (g->state == GAME)
	{
		if (button == Button1)
			g->keys->mouse_btn[0] = 0;
		else if (button == Button3)
			g->keys->mouse_btn[1] = 0;
		else if (button == Button2)
			g->keys->mouse_btn[2] = 0;
	}
	return (SUCCESS);
}

void	set_mouse_hooks(t_mlx *mlx, t_game *g)
{
	mlx_hook(mlx->win_ptr, ButtonPress, ButtonPressMask,
		&__set_game_mouse_press, g);
	mlx_hook(mlx->win_ptr, ButtonRelease, ButtonReleaseMask,
		&__set_game_mouse_release, g);
	mlx_hook(mlx->win_ptr, MotionNotify, PointerMotionMask,
		&mouse_motion, g);
}
