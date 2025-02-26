/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:39:19 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/20 18:40:00 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_leftward(t_data *data)
{
	data->player_dir -= 4;
	if (data->player_dir < 0)
		data->player_dir += 360; // (pour rester entre 0 et 2 PI radians)
	data->ray->player_rad = get_radian(data->player_dir);
}

void	rotate_rightward(t_data *data)
{
	data->player_dir += 4;
	if (data->player_dir > 360)
		data->player_dir = data->player_dir % 360;
	data->ray->player_rad = get_radian(data->player_dir);
}
