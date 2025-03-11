/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:38:03 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/11 16:01:12 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_player *player)
{
	player->move.x = cos(degree_to_radian(player->dir)) * MOVE_SPEED;
	player->move.y = sin(degree_to_radian(player->dir)) * MOVE_SPEED;
}

void	move_backward(t_player *player)
{
	player->move.x = -cos(degree_to_radian(player->dir)) * MOVE_SPEED;
	player->move.y = -sin(degree_to_radian(player->dir)) * MOVE_SPEED;
}

void	straf_leftward(t_player *player)
{
	player->move.x = sin(degree_to_radian(player->dir)) * MOVE_SPEED;
	player->move.y = -cos(degree_to_radian(player->dir)) * MOVE_SPEED;
}

void	straf_rightward(t_player *player)
{
	player->move.x = -sin(degree_to_radian(player->dir)) * MOVE_SPEED;
	player->move.y = cos(degree_to_radian(player->dir)) * MOVE_SPEED;
}
