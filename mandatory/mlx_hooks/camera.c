/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:39:19 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/11 16:05:44 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_leftward(t_player *player)
{
	player->dir -= 4;
	// Check pour rester entre 0 et 360° (soit 0 et 2 M_PI radians)
	if (player->dir < 0)
		player->dir += 360;
	game_s()->ray->player_rad = degree_to_radian(player->dir);
}

void	rotate_rightward(t_player *player)
{
	player->dir += 4;
	// Check pour rester entre 0 et 360° (soit 0 et 2 M_PI radians)
	if (player->dir > 360)
		player->dir = player->dir % 360;
	game_s()->ray->player_rad = degree_to_radian(player->dir);
}
