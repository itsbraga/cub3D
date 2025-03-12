/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:20:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/11 19:39:03 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__set_keyrelease(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->keys->key_array[W_KEY] = 0;
	if (keycode == XK_s)
		game->keys->key_array[S_KEY] = 0;
	if (keycode == XK_a)
		game->keys->key_array[A_KEY] = 0;
	if (keycode == XK_d)
		game->keys->key_array[D_KEY] = 0;
	if (keycode == XK_Left)
		game->keys->key_array[LEFT_KEY] = 0;
	if (keycode == XK_Right)
		game->keys->key_array[RIGHT_KEY] = 0;
	return (SUCCESS);
}

static int	__set_keypress(int keycode, t_game *game)
{
	if (game->state == TITLE_SCREEN)
	{
		if (keycode == XK_Escape)
			exit_game(mlx_s(), SUCCESS); // check si ok pour title_screen
		else if (keycode == XK_Return)
			return (game->state = GAME, SUCCESS);
		else
			return (FAILURE);
	}
	if (keycode == XK_Escape)
		exit_game(mlx_s(), SUCCESS);
	if (keycode == XK_w)
		game->keys->key_array[W_KEY] = 1;
	if (keycode == XK_s)
		game->keys->key_array[S_KEY] = 1;
	if (keycode == XK_a)
		game->keys->key_array[A_KEY] = 1;
	if (keycode == XK_d)
		game->keys->key_array[D_KEY] = 1;
	if (keycode == XK_Left)
		game->keys->key_array[LEFT_KEY] = 1;
	if (keycode == XK_Right)
		game->keys->key_array[RIGHT_KEY] = 1;
	(move_player(game, game->keys), reset_var(game));
	return (SUCCESS);
}

void	set_hooks(t_mlx *mlx, t_game *game)
{
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &__set_keypress, game);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &__set_keyrelease, game);
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask, &exit_game, game);
}
