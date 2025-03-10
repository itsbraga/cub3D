/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:39:19 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/09 22:45:22 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_leftward(t_game *game)
{
	game->player->dir -= 4;
	// Check pour rester entre 0 et 360° (soit 0 et 2 M_PI radians)
	if (game->player->dir < 0)
		game->player->dir += 360;
	game->ray->player_rad = degree_to_radian(game->player->dir);
}

void	rotate_rightward(t_game *game)
{
	game->player->dir += 4;
	// Check pour rester entre 0 et 360° (soit 0 et 2 M_PI radians)
	if (game->player->dir > 360)
		game->player->dir = game->player->dir % 360;
	game->ray->player_rad = degree_to_radian(game->player->dir);
}
