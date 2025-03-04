/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:20:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/03 20:15:05 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__set_keyrelease_flag(int keycode, t_data *d)
{
	if (keycode == W)
		d->keys->key_array[W_KEY] = 0;
	if (keycode == S)
		d->keys->key_array[S_KEY] = 0;
	if (keycode == A)
		d->keys->key_array[A_KEY] = 0;
	if (keycode == D)
		d->keys->key_array[D_KEY] = 0;
	if (keycode == XK_Left)
		d->keys->key_array[LEFT_KEY] = 0;
	if (keycode == XK_Right)
		d->keys->key_array[RIGHT_KEY] = 0;
	return (SUCCESS);
}

static int	__set_keypress_flag(int keycode, t_data *d)
{
	if (keycode == XK_Escape)
		exit_game(mlx_s(), SUCCESS);
	if (keycode == W)
		d->keys->key_array[W_KEY] = 1;
	if (keycode == S)
		d->keys->key_array[S_KEY] = 1;
	if (keycode == A)
		d->keys->key_array[A_KEY] = 1;
	if (keycode == D)
		d->keys->key_array[D_KEY] = 1;
	if (keycode == XK_Left)
		d->keys->key_array[LEFT_KEY] = 1;
	if (keycode == XK_Right)
		d->keys->key_array[RIGHT_KEY] = 1;
	update_player_move(d, d->keys);
	reset_var(d);
	return (SUCCESS);
}

void	set_hooks(t_mlx *mlx, t_data *data)
{
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &__set_keypress_flag, data);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &__set_keyrelease_flag,
		data);
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask, &exit_game, mlx);
}
