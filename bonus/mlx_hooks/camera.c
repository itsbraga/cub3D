/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:39:19 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/07 00:40:38 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	rotate_leftward(t_game *game, t_data *data)
{
	// changer player_dir par angle.x
	data->player_dir -= 4;
	// Check pour rester entre 0 et 360° (soit 0 et 2 M_PI radians)
	if (data->player_dir < 0)
		data->player_dir += 360;
	game->ray->player_rad = degree_to_radian(data->player_dir);
}

void	rotate_rightward(t_game *game, t_data *data)
{
	// changer player_dir par angle.x
	data->player_dir += 4;
	// Check pour rester entre 0 et 360° (soit 0 et 2 M_PI radians)
	if (data->player_dir > 360)
		data->player_dir = data->player_dir % 360;
	game->ray->player_rad = degree_to_radian(data->player_dir);
}
