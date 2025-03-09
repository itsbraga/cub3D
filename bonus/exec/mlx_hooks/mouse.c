/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:44:33 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/09 17:39:02 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	__handle_mouse(int x, int y, t_game *game)
{
	static int	last_x = -1;
	int			delta_x;

	(void)y;
	if (last_x == -1)
		last_x = x;
	delta_x = x - last_x;
	// Ajuste l'angle du joueur selon le deplacement horizontal
	game->player->dir += delta_x * MOUSE_SENSITIVITY_X;
	game->player->dir = norm_angle_h(game->player->dir);
	// MAJ de l'angle en radians pour le raycasting
	game->ray->player_rad = degree_to_radian(game->player->dir);
	last_x = x;
	return (SUCCESS);
}

static int	__title_screen_mouse(int button, int x, int y, t_game *game)
{
	t_layer	start_button;

	start_button = game->title_screen.second_layer;
	if (game->state == TITLE_SCREEN && button == Button1) // Clic gauche
	{
		if ((x >= start_button.pos.x && x <= start_button.pos.x
				+ start_button.width)
			&& (y >= start_button.pos.y && y <= start_button.pos.y
				+ start_button.height))
		{
			game->state = GAME;
		}
	}
	return (SUCCESS);
}

void	set_mouse_hooks(t_mlx *mlx, t_game *game)
{
	mlx_hook(mlx->win_ptr, MotionNotify, PointerMotionMask, &__handle_mouse,
			game);
	mlx_mouse_hook(mlx->win_ptr, &__title_screen_mouse, game);
}
