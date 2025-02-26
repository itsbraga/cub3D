/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:38:03 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/26 20:35:24 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	move_forward(t_data *data)
{
	data->move.x = cos(get_radian(data->player_dir)) * MOVE_SPEED;
	data->move.y = sin(get_radian(data->player_dir)) * MOVE_SPEED;
}

void	move_backward(t_data *data)
{
	data->move.x = -cos(get_radian(data->player_dir)) * MOVE_SPEED;
	data->move.y = -sin(get_radian(data->player_dir)) * MOVE_SPEED;
}

void	straf_leftward(t_data *data)
{
	data->move.x = sin(get_radian(data->player_dir)) * MOVE_SPEED;
	data->move.y = -cos(get_radian(data->player_dir)) * MOVE_SPEED;
}

void	straf_rightward(t_data *data)
{
	data->move.x = -sin(get_radian(data->player_dir)) * MOVE_SPEED;
	data->move.y = cos(get_radian(data->player_dir)) * MOVE_SPEED;
}
