/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:40:21 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/18 18:25:13 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__keypress_handler(int keycode, t_data *data)
{
	float	move_x;
	float	move_y;

	move_x = 0;
	move_y = 0;
	if (data->game->game_state == STATE_TITLE)
	{
		if (keycode == XK_Return) // Touche Entrée
		{
			data->game->game_state = STATE_GAME;
			return (SUCCESS);
		}
	}
	if (keycode == XK_Escape)
		clean(data->mlx);
	if (keycode == XK_Left)
	{
		data->player_dir -= 4;
		if (data->player_dir < 0)
		data->player_dir += 360; // (pour rester entre 0 et 2 PI radians)
		data->ray->player_rad = get_radian(data->player_dir);
	}
	if (keycode == XK_Right)
	{
		data->player_dir += 4;
		if (data->player_dir > 360)
		data->player_dir = data->player_dir % 360;
		data->ray->player_rad = get_radian(data->player_dir);
	}
	/********************** Player mouvements *************************/
	if (keycode == W)
	{
		// cos = deplacement horizontal ; sin = deplacement vertical
		move_x = cos(get_radian(data->player_dir)) * 3;
		move_y = sin(get_radian(data->player_dir)) * 3;
	}
	if (keycode == A)
	{
		move_x = sin(get_radian(data->player_dir)) * 3;
		move_y = -cos(get_radian(data->player_dir)) * 3;
	}
	if (keycode == S)
	{
		move_x = -cos(get_radian(data->player_dir)) * 3;
		move_y = -sin(get_radian(data->player_dir)) * 3;
	}
	if (keycode == D)
	{
		move_x = -sin(get_radian(data->player_dir)) * 3;
		move_y = cos(get_radian(data->player_dir)) * 3;
	}
	data->player.x = roundf(data->player.x + move_x);
	data->player.y = roundf(data->player.y + move_y);
	/******************************************************************/
	return (SUCCESS);
}

static int	__mouse_handler(int button, int cursor_x, int cursor_y, t_data *data)
{
	t_game	*g;
	
	g = data->game;
	if (g->game_state == STATE_TITLE)
	{
		if (button == Button1) // Clic gauche
		{
			if ((cursor_x >= g->button.x && cursor_x <= g->button.x + 200)
				&& (cursor_y >= g->button.y && cursor_y <= g->button.y + 50))
				{
					data->game->game_state = STATE_GAME;
					return (SUCCESS);
				}
		}
	}
	return (SUCCESS);
}

void	set_hooks(t_mlx *mlx, t_data *data)
{
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &__keypress_handler, data);
	mlx_mouse_hook(mlx->win_ptr, &__mouse_handler, data);
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask, &clean, mlx);
}
