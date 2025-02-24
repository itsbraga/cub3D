/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:38:03 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/24 20:45:42 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
