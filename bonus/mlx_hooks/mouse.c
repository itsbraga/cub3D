/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:44:33 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 02:21:52 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	__handle_mouse(int x, int y, t_data *data)
{
	static int	last_x = -1;
	int			delta_x;

	(void)y;
	if (last_x == -1) // Initialisation du premier appel
		last_x = x;
	delta_x = x - last_x;
	// Ajuste l'angle du joueur selon le deplacement horizontal
	data->player_dir += delta_x * MOUSE_SENSITIVITY;
	// Check pour rester entre 0 et 360° (soit 0 et 2 PI radians)
	if (data->player_dir < 0)
		data->player_dir += 360;
	else if (data->player_dir > 360)
		data->player_dir = data->player_dir % 360;
	// MAJ de la valeur de last_x pour la prochaine frame
	last_x = x;
	// MAJ de l'angle en radians pour le raycasting
	data->ray->player_rad = get_radian(data->player_dir);
	return (SUCCESS);
}

static int	__handle_title_screen_mouse(int button, int x, int y, t_data *data)
{
	t_layer	start_button;

	start_button = data->title_screen.start_button;
	if (data->game_state == STATE_TITLE && button == Button1) // Clic gauche
	{
		if ((x >= start_button.pos.x && x <= start_button.pos.x
				+ start_button.width)
			&& (y >= start_button.pos.y && y <= start_button.pos.y
				+ start_button.height))
		{
			data->game_state = STATE_GAME;
		}
	}
	return (SUCCESS);
}

void	set_mouse_hooks(t_mlx *mlx, t_data *data)
{
	mlx_hook(mlx->win_ptr, MotionNotify, PointerMotionMask, &__handle_mouse,
			data);
	mlx_mouse_hook(mlx->win_ptr, &__handle_title_screen_mouse, data);
}
