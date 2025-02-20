/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:38:03 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/20 18:38:25 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_data *data)
{
	data->move_x = cos(get_radian(data->player_dir)) * 5;
	data->move_y = sin(get_radian(data->player_dir)) * 5;
}

void	move_backward(t_data *data)
{
	data->move_x = -cos(get_radian(data->player_dir)) * 5;
	data->move_y = -sin(get_radian(data->player_dir)) * 5;
}

void	straf_leftward(t_data *data)
{
	data->move_x = sin(get_radian(data->player_dir)) * 5;
	data->move_y = -cos(get_radian(data->player_dir)) * 5;
}

void	straf_rightward(t_data *data)
{
	data->move_x = -sin(get_radian(data->player_dir)) * 5;
	data->move_y = cos(get_radian(data->player_dir)) * 5;
}
