/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:38:03 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/04 18:23:51 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	move_forward(t_game *game, t_data *data)
{
	game->move.x = cos(get_radian(data->player_dir)) * MOVE_SPEED;
	game->move.y = sin(get_radian(data->player_dir)) * MOVE_SPEED;
}

void	move_backward(t_game *game, t_data *data)
{
	game->move.x = -cos(get_radian(data->player_dir)) * MOVE_SPEED;
	game->move.y = -sin(get_radian(data->player_dir)) * MOVE_SPEED;
}

void	straf_leftward(t_game *game, t_data *data)
{
	game->move.x = sin(get_radian(data->player_dir)) * MOVE_SPEED;
	game->move.y = -cos(get_radian(data->player_dir)) * MOVE_SPEED;
}

void	straf_rightward(t_game *game, t_data *data)
{
	game->move.x = -sin(get_radian(data->player_dir)) * MOVE_SPEED;
	game->move.y = cos(get_radian(data->player_dir)) * MOVE_SPEED;
}
