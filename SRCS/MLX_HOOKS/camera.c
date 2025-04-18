/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:39:19 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 18:15:39 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_leftward(t_game *g)
{
	g->player->dir -= ROTATION_SPEED;
	if (g->player->dir < 0)
		g->player->dir += 360;
	g->ray->player_rad = degree_to_radian(g->player->dir);
}

void	rotate_rightward(t_game *g)
{
	g->player->dir += ROTATION_SPEED;
	if (g->player->dir > 360)
		g->player->dir = g->player->dir % 360;
	g->ray->player_rad = degree_to_radian(g->player->dir);
}
