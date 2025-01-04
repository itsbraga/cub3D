/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:20:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/04 20:32:28 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void __key_msg(int keycode)
{
	if (keycode == XK_Up || keycode == W)
		ft_printf(1, BOLD "UP Key:\t\tmoving ↑\n" RESET); // a voir si on garde
	else if (keycode == XK_Down || keycode == S)
		ft_printf(1, BOLD "DOWN Key:\tmoving ↓\n" RESET);
	else if (keycode == XK_Left || keycode == A)
		ft_printf(1, BOLD "LEFT Key:\tmoving ←\n" RESET);
	else if (keycode == XK_Right || keycode == D)
		ft_printf(1, BOLD "RIGHT Key:\tmoving →\n" RESET);
}

void	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
		data->mlx->win_ptr = NULL;
	}
	// else if (key == XK_Up || key == W)
	// 	//
	// else if (key == XK_Down || key == S)
	// 	//
	// else if (key == XK_Left || key == A)
	// 	//
	// else if (key == XK_Right || key == D)
	// 	//
}
