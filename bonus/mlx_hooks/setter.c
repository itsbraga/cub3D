/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:20:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/03 19:47:33 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	__set_keyrelease_flag(int keycode, t_data *d)
{
	if (keycode == W)
		d->keys->key_tab[W_KEY] = 0;
	if (keycode == S)
		d->keys->key_tab[S_KEY] = 0;
	if (keycode == A)
		d->keys->key_tab[A_KEY] = 0;
	if (keycode == D)
		d->keys->key_tab[D_KEY] = 0;
	if (keycode == XK_Left)
		d->keys->key_tab[LEFT_KEY] = 0;
	if (keycode == XK_Right)
		d->keys->key_tab[RIGHT_KEY] = 0;
	return (SUCCESS);
}

static int	__set_keypress_flag(int keycode, t_data *d)
{
	if (d->game_state == STATE_TITLE)
	{
		if (keycode == XK_Escape)
			exit_game(mlx_s(), d->title_screen.bg_img.img_ptr, SUCCESS); // segfault si fermeture par la croix
		else if (keycode == XK_Return)
			return (d->game_state = STATE_GAME, SUCCESS);
		else
			return (FAILURE);
	}
	if (keycode == XK_Escape)
		exit_game(mlx_s(), mlx_s()->img.img_ptr, SUCCESS); // segfault si fermeture par la croix
	if (keycode == W)
		d->keys->key_tab[W_KEY] = 1;
	if (keycode == S)
		d->keys->key_tab[S_KEY] = 1;
	if (keycode == A)
		d->keys->key_tab[A_KEY] = 1;
	if (keycode == D)
		d->keys->key_tab[D_KEY] = 1;
	if (keycode == XK_Left)
		d->keys->key_tab[LEFT_KEY] = 1;
	if (keycode == XK_Right)
		d->keys->key_tab[RIGHT_KEY] = 1;
	(update_player_move(d, d->keys), reset_var(d));
	return (SUCCESS);
}

void	set_hooks(t_mlx *mlx, t_data *data)
{
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &__set_keypress_flag, data);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &__set_keyrelease_flag,
			data);
	set_mouse_hooks(mlx, data);
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask, &exit_game, mlx); // clean function
}
