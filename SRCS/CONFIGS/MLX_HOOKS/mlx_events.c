/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:20:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/20 18:43:11 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// NE PAS OUBLIER DE RESET LE TAB DE BOOLEAN

// void	init_movetab(move_tab *functions)
// {
// 	functions[0] = move_forward;
// 	functions[1] = move_backward; 
// 	functions[2] = straf_leftward; 
// 	functions[3] = straf_rightward; 
// 	functions[4] = rotate_leftward;
// 	functions[5] = rotate_rightward;
// 	functions[6] = NULL;
// }

// void	handle_movement(t_data *data, t_keys *key)
// {
// 	int			i;
// 	move_tab	functions[7];
	
// 	i = 0;
// 	init_movetab(functions);
// 	data->player.x = roundf(data->player.x + data->move_x);
// 	data->player.y = roundf(data->player.y + data->move_y);
// 	while (i != 6)
// 	{
// 		if (key->key_tab[i] == 1)
// 			functions[i](data);
// 		i++;
// 	}
// 	data->player.x = roundf(data->player.x + data->move_x);
// 	data->player.y = roundf(data->player.y + data->move_y);
// }

// void	reset_var(t_data *data)
// {
// 	data->move_x = 0;
// 	data->move_y = 0;
// }

// int	set_keyrelease_flag(int keycode, t_data *d)
// {
// 	if (keycode == W)
// 		d->keys->key_tab[W_KEY] = 0;
// 	if (keycode == S)
// 		d->keys->key_tab[S_KEY] = 0;
// 	if (keycode == D)
// 		d->keys->key_tab[D_KEY] = 0;
// 	if (keycode == A)
// 		d->keys->key_tab[A_KEY] = 0;
// 	if (keycode == XK_Left)
// 		d->keys->key_tab[LEFT_KEY] = 0;
// 	if (keycode == XK_Right)
// 		d->keys->key_tab[RIGHT_KEY] = 0;
// 	return (SUCCESS);
// }

// int	set_keypress_flag(int keycode, t_data *d)
// {
// 	if (keycode == XK_Escape)
// 		exit_game(mlx_s());
// 	if (keycode == W)
// 		d->keys->key_tab[W_KEY] = 1;
// 	if (keycode == S)
// 		d->keys->key_tab[S_KEY] = 1;
// 	if (keycode == D)
// 		d->keys->key_tab[D_KEY] = 1;
// 	if (keycode == A)
// 		d->keys->key_tab[A_KEY] = 1;
// 	if (keycode == XK_Left)
// 		d->keys->key_tab[LEFT_KEY] = 1;
// 	if (keycode == XK_Right)
// 		d->keys->key_tab[RIGHT_KEY] = 1;
// 	handle_movement(d, d->keys);
// 	reset_var(d);
// 	return (SUCCESS);
// }

// void	set_hooks(t_mlx *mlx, t_data *data)
// {
// 	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &set_keypress_flag, data);
// 	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &set_keyrelease_flag, data);
// 	// mlx_mouse_hook(mlx->win_ptr, &mouse_handler, data);
// 	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask, &exit_game, mlx);
// }
