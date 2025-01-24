/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:20:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/24 20:26:03 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void __key_msg(int keycode)
// {
// 	if (keycode == XK_Up || keycode == W)
// 		ft_printf(1, BOLD "UP Key:\t\tmoving ↑\n" RESET); // a voir si on garde
// 	else if (keycode == XK_Down || keycode == S)
// 		ft_printf(1, BOLD "DOWN Key:\tmoving ↓\n" RESET);
// 	else if (keycode == XK_Left || keycode == A)
// 		ft_printf(1, BOLD "LEFT Key:\tmoving ←\n" RESET);
// 	else if (keycode == XK_Right || keycode == D)
// 		ft_printf(1, BOLD "RIGHT Key:\tmoving →\n" RESET);
// }

int	handle_keypress(int key, t_data *data)
{
	float	move_x = 0;
	float	move_y = 0;
	
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
		data->mlx->win_ptr = NULL;
	}
	else if (key == XK_Left)
	{
		data->player_dir -= 4;
		if (data->player_dir < 0)
			data->player_dir += 360; // (pour rester entre 0 et 2 PI radians)
	}
	else if (key == XK_Right)
	{
		data->player_dir += 4;
		if (data->player_dir > 360)
			data->player_dir = data->player_dir % 360;
	}
	else if (key == W)
	{
		// cos = deplacement horizontal ; sin = deplacement vertical
		move_x = cos(get_radian(data->player_dir)) * 3;
		move_y = sin(get_radian(data->player_dir)) * 3;
	}
	else if (key == A)
	{
		// on utilise sin et cos car nous sommes perpendiculaire a la dir initiale
		// rotation de 90
		move_x = sin(get_radian(data->player_dir)) * 3;
		move_y = -cos(get_radian(data->player_dir)) * 3;
	}
	else if (key == S)
	{
		move_x = -cos(get_radian(data->player_dir)) * 3;
		move_y = -sin(get_radian(data->player_dir)) * 3;
	}
	else if (key == D)
	{
		move_x = -sin(get_radian(data->player_dir)) * 3;
		move_y = cos(get_radian(data->player_dir)) * 3;
	}
	data->player.x = roundf(data->player.x + move_x);
	data->player.y = roundf(data->player.y + move_y);
	return (SUCCESS);
}
