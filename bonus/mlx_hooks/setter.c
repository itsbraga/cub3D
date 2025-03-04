/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:20:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 19:25:13 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	__set_keyrelease_flag(int keycode, t_game *game)
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
	return (SUCCESS);
}

static int	__set_keypress_flag(int keycode, t_game *game)
{
	if (game->game_state == STATE_TITLE)
	{
		if (keycode == XK_Escape)
			clean_exit(mlx_s(), SUCCESS); // check si ok pour title_screen
		else if (keycode == XK_Return)
			return (game->game_state = STATE_GAME, SUCCESS);
		else
			return (FAILURE);
	}
	if (keycode == XK_Escape)
		clean_exit(mlx_s(), SUCCESS);
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
	(update_player_move(game, game->keys), reset_var(game));
	return (SUCCESS);
}

void	set_hooks(t_mlx *mlx, t_game *game, t_data *data)
{
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &__set_keypress_flag, game);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &__set_keyrelease_flag,
			game);
	set_mouse_hooks(mlx, data, game);
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask, &clean_exit,
			mlx);
}
