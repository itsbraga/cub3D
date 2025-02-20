/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:36:16 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/20 18:15:49 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	avoid_collisions(int keycode, t_data *d)
{
	float	move_x;
	float	move_y;
	t_point	new_player;
	t_point	cell;
	
	move_x = 0;
	move_y = 0;
	new_player.x = d->player.x;
	new_player.y = d->player.y;
	cell.x = 0;
	cell.y = 0;
	if (keycode == W) // d->keys->key_tab[0]
	{
		move_x = cos(get_radian(d->player_dir)) * MOVE_SPEED;
		move_y = sin(get_radian(d->player_dir)) * MOVE_SPEED;
	}
	else if (keycode == A) // d->keys->key_tab[2]
	{
		move_x = sin(get_radian(d->player_dir)) * MOVE_SPEED;
		move_y = -cos(get_radian(d->player_dir)) * MOVE_SPEED;
	}
	else if (keycode == S) // d->keys->key_tab[1]
	{
		move_x = -cos(get_radian(d->player_dir)) * MOVE_SPEED;
		move_y = -sin(get_radian(d->player_dir)) * MOVE_SPEED;
	}
	else if (keycode == D) // d->keys->key_tab[3]
	{
		move_x = -sin(get_radian(d->player_dir)) * MOVE_SPEED;
		move_y = cos(get_radian(d->player_dir)) * MOVE_SPEED;
	}
	// printf(BOLD RED "Move: (%.2f, %.2f)\n" RESET, move_x, move_y);
	
	new_player.x += move_x;
	new_player.y += move_y;
	
	// printf("New player pos: (%.2f, %.2f)\n", new_player.x, new_player.y);
	// printf("Map size: (%zu, %zu)\n", d->map->M_WIDTH, d->map->M_HEIGHT);
	
	cell.x = new_player.x * d->map->M_WIDTH / W_WIDTH;
	cell.y = new_player.y * d->map->M_HEIGHT / W_HEIGHT;
	
	// printf("Cell value: %c\n", d->map->map2d[(int)cell.y][(int)cell.x]);
	// Si la cellule ciblee est un mur, on bloque le deplacement
	if (d->map->map2d[(int)cell.y][(int)cell.x] == '1')
	{
		printf(BOLD RED "Collision!\n" RESET);
		return (SUCCESS);
	}
	
	// Mise a jour de la position du joueur
	d->player.x = roundf(new_player.x);
	d->player.y = roundf(new_player.y);
	
	return (SUCCESS);
}
