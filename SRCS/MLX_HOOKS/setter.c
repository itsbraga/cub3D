/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:20:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/16 13:45:20 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__set_title_screen_keys(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		exit_game(s_mlx(), SUCCESS);
	else if (keycode == XK_Return)
	{
		game->state = GAME;
		toggle_mouse_visibility(game->mlx, game->state);
	}
	return (SUCCESS);
}

static void	__weapon_selection(int keycode, t_data *data)
{
	if (keycode == EXCLAMATION_KEY)
		data->curr_weapon_idx = 0;
	else if (keycode == AT_KEY)
		data->curr_weapon_idx = 1;
	else if (keycode == HASH_KEY)
		data->curr_weapon_idx = 2;
}

static int	__set_keypress(int keycode, t_game *game)
{
	if (game->state == TITLE_SCREEN)
		return (__set_title_screen_keys(keycode, game));
	if (keycode == XK_Escape)
		exit_game(s_mlx(), SUCCESS);
	if (keycode == W_KEY)
		game->keys->key_array[_W] = 1;
	if (keycode == S_KEY)
		game->keys->key_array[_S] = 1;
	if (keycode == A_KEY)
		game->keys->key_array[_A] = 1;
	if (keycode == D_KEY)
		game->keys->key_array[_D] = 1;
	if (keycode == XK_Left)
		game->keys->key_array[_LEFT] = 1;
	if (keycode == XK_Right)
		game->keys->key_array[_RIGHT] = 1;
	if (keycode == SPACE_KEY)
		game->keys->key_array[_SPACE] = 1;
	if (BONUS)
	{
		if (keycode == E_KEY)
			trigger_door(game);	
		__weapon_selection(keycode, game->data);
	}
	return (SUCCESS);
}

static int	__set_keyrelease(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->keys->key_array[_W] = 0;
	if (keycode == S_KEY)
		game->keys->key_array[_S] = 0;
	if (keycode == A_KEY)
		game->keys->key_array[_A] = 0;
	if (keycode == D_KEY)
		game->keys->key_array[_D] = 0;
	if (keycode == XK_Left)
		game->keys->key_array[_LEFT] = 0;
	if (keycode == XK_Right)
		game->keys->key_array[_RIGHT] = 0;
	if (keycode == SPACE_KEY)
		game->keys->key_array[_SPACE] = 0;
	return (SUCCESS);
}

void	set_hooks(t_mlx *mlx, t_game *game)
{
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask, &exit_game, mlx);
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &__set_keypress, game);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &__set_keyrelease, game);
	if (BONUS)
	{
		toggle_mouse_visibility(mlx, game->state);
		set_mouse_hooks(mlx, game);
	}
}
