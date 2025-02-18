/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:36:16 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/18 19:36:40 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// si le mur est devant le joueur, bloquer la touche W
// mais pas les autres (reculer, tourner a gauche ou a droite)
// ainsi de suite (derriere, a gauche, a droite du joueur)
// if (keycode == W)
// 	// block
// if (keycode == A)
// 	// block
// if (keycode == S)
// 	// block
// if (keycode == D)
	// block

// int	avoid_collisions(int keycode, t_data *data)
// {
// 	float	move_x;
// 	float	move_y;
// 	float	next_player_x;
// 	float	next_player_y;

// 	move_x = 0;
// 	move_y = 0;
// 	if (keycode == W)
// 	{
// 		move_x = cos(get_radian(data->player_dir)) * 3;
// 		move_y = sin(get_radian(data->player_dir)) * 3;
// 	}
// 	if (keycode == A)
// 	{
// 		// 	move_x = sin(get_radian(data->player_dir)) * 3;
// 		// 	move_y = -cos(get_radian(data->player_dir)) * 3;
// 	}
// 	if (keycode == S)
// 	{
// 		move_x = -cos(get_radian(data->player_dir)) * 3;
// 		move_y = -sin(get_radian(data->player_dir)) * 3;
// 	}
// 	if (keycode == D)
// 	{
// 		// move_x = -sin(get_radian(data->player_dir)) * 3;
// 		// move_y = cos(get_radian(data->player_dir)) * 3;
// 	}
// 	next_player_x = roundf(data->player.x + move_x);
// 	next_player_y = roundf(data->player.y + move_y);
// 	if (data->map->map2d[(int)next_player_x][(int)next_player_y] == '1')
// 	{
// 		printf(BOLD RED "Collision!\n" RESET);
// 		return (FAILURE);
// 	}
// 	data->player.x = next_player_x;
// 	data->player.y = next_player_y;
// 	return (SUCCESS);
// }
