/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:38:03 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/07 00:54:09 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	move_forward(t_game *game, t_data *data)
{
	game->player->move.x = cos(degree_to_radian(data->player_dir)) * MOVE_SPEED;
	game->player->move.y = sin(degree_to_radian(data->player_dir)) * MOVE_SPEED;
}

void	move_backward(t_game *game, t_data *data)
{
	game->player->move.x = -cos(degree_to_radian(data->player_dir)) * MOVE_SPEED;
	game->player->move.y = -sin(degree_to_radian(data->player_dir)) * MOVE_SPEED;
}

void	straf_leftward(t_game *game, t_data *data)
{
	game->player->move.x = sin(degree_to_radian(data->player_dir)) * MOVE_SPEED;
	game->player->move.y = -cos(degree_to_radian(data->player_dir)) * MOVE_SPEED;
}

void	straf_rightward(t_game *game, t_data *data)
{
	game->player->move.x = -sin(degree_to_radian(data->player_dir)) * MOVE_SPEED;
	game->player->move.y = cos(degree_to_radian(data->player_dir)) * MOVE_SPEED;
}
