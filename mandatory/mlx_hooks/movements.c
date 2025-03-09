/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:38:03 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/09 22:43:44 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_game *game)
{
	game->player->move.x = cos(degree_to_radian(game->player->dir)) * MOVE_SPEED;
	game->player->move.y = sin(degree_to_radian(game->player->dir)) * MOVE_SPEED;
}

void	move_backward(t_game *game)
{
	game->player->move.x = -cos(degree_to_radian(game->player->dir)) * MOVE_SPEED;
	game->player->move.y = -sin(degree_to_radian(game->player->dir)) * MOVE_SPEED;
}

void	straf_leftward(t_game *game )
{
	game->player->move.x = sin(degree_to_radian(game->player->dir)) * MOVE_SPEED;
	game->player->move.y = -cos(degree_to_radian(game->player->dir)) * MOVE_SPEED;
}

void	straf_rightward(t_game *game)
{
	game->player->move.x = -sin(degree_to_radian(game->player->dir)) * MOVE_SPEED;
	game->player->move.y = cos(degree_to_radian(game->player->dir)) * MOVE_SPEED;
}
