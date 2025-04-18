/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:44:33 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/18 19:10:31 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

// void	toggle_mouse_visibility(t_mlx *mlx, t_game_state state)
// {
// 	if (state == TITLE_SCREEN)
// 		mlx_mouse_show(mlx->mlx_ptr, mlx->win_ptr);
// 	else
// 		mlx_mouse_hide(mlx->mlx_ptr, mlx->win_ptr);
// }

static int	__manage_mouse_wrapping(int x, int *prev_x, t_mlx *mlx)
{
	int	center_x;
	int	center_y;

	center_x = WIN_WIDTH / 2;
	center_y = WIN_HEIGHT / 2;
	if (x < WIN_WIDTH / 10 || x > WIN_WIDTH * 9 / 10)
	{
		mlx_mouse_move(mlx->mlx_ptr, mlx->win_ptr, center_x, center_y);
		*prev_x = center_x;
		return (1);
	}
	return (0);
}

int	mouse_motion(int x, int y, t_game *g)
{
	static int	prev_x = -1;
	static bool	recentered = false;
	int			delta_x;

	(void)y;
	if (prev_x == -1)
		prev_x = x;
	if (__manage_mouse_wrapping(x, &prev_x, g->mlx) == 1)
		return (recentered = true, SUCCESS);
	if (recentered)
	{
		recentered = false;
		prev_x = x;
	}
	delta_x = x - prev_x;
	if (delta_x != 0)
	{
		g->player->dir += delta_x * MOUSE_SENSITIVITY_X;
		g->player->dir = norm_h_angle(g->player->dir);
		g->ray->player_rad = degree_to_radian(g->player->dir);
	}
	prev_x = x;
	return (SUCCESS);
}
