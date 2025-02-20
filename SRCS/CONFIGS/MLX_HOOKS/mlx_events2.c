/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:40:21 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/20 18:16:20 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// cos = deplacement horizontal ; sin = deplacement vertical
static int	__keypress_handler(int keycode, t_data *d)
{
	float	move_x;
	float	move_y;
	
	move_x = 0;
	move_y = 0;
	if (d->game->game_state == STATE_TITLE)
	{
		if (keycode == XK_Return) // Touche Entrée
		{
			d->game->game_state = STATE_GAME;
			return (SUCCESS); // same as continue;
		}
	}
	if (keycode == XK_Escape)
		exit_game(d->mlx);
	if (keycode == XK_Left)
	{
		d->player_dir -= 4;
		if (d->player_dir < 0)
		d->player_dir += 360; // (pour rester entre 0 et 2 PI radians)
		d->ray->player_rad = get_radian(d->player_dir);
	}
	if (keycode == XK_Right)
	{
		d->player_dir += 4;
		if (d->player_dir > 360)
		d->player_dir = d->player_dir % 360;
		d->ray->player_rad = get_radian(d->player_dir);
	}

	if (avoid_collisions(keycode, d) == FAILURE)
		return (SUCCESS);
	
	// printf("Player position updated: (%.2f, %.2f)\n", d->player.x, d->player.y);
	
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
			if ((cursor_x >= g->button.x && cursor_x <= g->button.x + 200) &&
				(cursor_y >= g->button.y && cursor_y <= g->button.y + 50))
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
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask, &exit_game, mlx);
}
