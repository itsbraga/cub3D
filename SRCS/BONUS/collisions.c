/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:36:16 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/19 23:28:33 by annabrag         ###   ########.fr       */
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

int	avoid_collisions(int keycode, t_data *d)
{
	float	move_x;
	float	move_y;
	float	next_player_x;
	float	next_player_y;
	float	buffer;
	int		collision_pos;
	int		collision_neg;

	move_x = 0;
	move_y = 0;
	next_player_x = 0;
	next_player_y = 0;
	buffer = 0.2;
	collision_pos = d->map->map2d[(int)(next_player_x + buffer)][(int)(next_player_y + buffer)];
	collision_neg = d->map->map2d[(int)(next_player_x - buffer)][(int)(next_player_y - buffer)];
	if (keycode == W)
	{
		move_x = cos(get_radian(d->player_dir)) * 5;
		move_y = sin(get_radian(d->player_dir)) * 5;
	}
	else if (keycode == A)
	{
		move_x = sin(get_radian(d->player_dir)) * 5;
		move_y = -cos(get_radian(d->player_dir)) * 5;
	}
	else if (keycode == S)
	{
		move_x = -cos(get_radian(d->player_dir)) * 5;
		move_y = -sin(get_radian(d->player_dir)) * 5;
	}
	else if (keycode == D)
	{
		move_x = -sin(get_radian(d->player_dir)) * 5;
		move_y = cos(get_radian(d->player_dir)) * 5;
	}
	
	next_player_x = d->player.x + move_x;
	next_player_y = d->player.y + move_y;
	printf("d->map->map2d[x: %d][y: %d]\n", (int)next_player_x, (int)next_player_y);
	if (next_player_x < 0 || next_player_x >= d->map->M_WIDTH ||
		next_player_y < 0 || next_player_y >= d->map->M_HEIGHT)
		return (SUCCESS);

	/*	Verif des collisions comprenant le joueur et sa zone de securite (buffer)
	
		obs: Sans buffer, la collision n'est effectuee qu'a la position exacte du joueur
			 donc il peut se retrouver trop pres des murs
	*/
	if (collision_pos == '1' || collision_neg == '1')
	{
		printf(BOLD RED "Collision!\n" RESET);
		return (SUCCESS);
	}

	// Mise a jour de la position du joueur
	d->player.x = next_player_x;
	d->player.y = next_player_y;
	return (SUCCESS);
}
