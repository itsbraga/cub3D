/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:38:03 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/04 15:28:50 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	move_forward(t_game *data)
{
	data->move.x = cos(get_radian(data->player_dir)) * MOVE_SPEED;
	data->move.y = sin(get_radian(data->player_dir)) * MOVE_SPEED;
}

void	move_backward(t_game *data)
{
	data->move.x = -cos(get_radian(data->player_dir)) * MOVE_SPEED;
	data->move.y = -sin(get_radian(data->player_dir)) * MOVE_SPEED;
}

void	straf_leftward(t_game *data)
{
	data->move.x = sin(get_radian(data->player_dir)) * MOVE_SPEED;
	data->move.y = -cos(get_radian(data->player_dir)) * MOVE_SPEED;
}

void	straf_rightward(t_game *data)
{
	data->move.x = -sin(get_radian(data->player_dir)) * MOVE_SPEED;
	data->move.y = cos(get_radian(data->player_dir)) * MOVE_SPEED;
}
