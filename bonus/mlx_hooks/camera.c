/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:39:19 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/04 18:18:06 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	rotate_leftward(t_game *game, t_data *data)
{
	data->player_dir -= 4;
	// Check pour rester entre 0 et 360° (soit 0 et 2 PI radians)
	if (data->player_dir < 0)
		data->player_dir += 360;
	game->ray->player_rad = get_radian(data->player_dir);
}

void	rotate_rightward(t_game *game, t_data *data)
{
	data->player_dir += 4;
	// Check pour rester entre 0 et 360° (soit 0 et 2 PI radians)
	if (data->player_dir > 360)
		data->player_dir = data->player_dir % 360;
	game->ray->player_rad = get_radian(data->player_dir);
}
