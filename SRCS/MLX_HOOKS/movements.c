/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:38:03 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 18:15:44 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_game *g)
{
	float	player_angle;

	player_angle = degree_to_radian(g->player->dir);
	g->player->move.x = cos(player_angle) * MOVE_SPEED;
	g->player->move.y = sin(player_angle) * MOVE_SPEED;
}

void	move_backward(t_game *g)
{
	float	player_angle;

	player_angle = degree_to_radian(g->player->dir);
	g->player->move.x = -cos(player_angle) * MOVE_SPEED;
	g->player->move.y = -sin(player_angle) * MOVE_SPEED;
}

void	straf_leftward(t_game *g)
{
	float	player_angle;

	player_angle = degree_to_radian(g->player->dir);
	g->player->move.x = sin(player_angle) * MOVE_SPEED;
	g->player->move.y = -cos(player_angle) * MOVE_SPEED;
}

void	straf_rightward(t_game *g)
{
	float	player_angle;

	player_angle = degree_to_radian(g->player->dir);
	g->player->move.x = -sin(player_angle) * MOVE_SPEED;
	g->player->move.y = cos(player_angle) * MOVE_SPEED;
}
