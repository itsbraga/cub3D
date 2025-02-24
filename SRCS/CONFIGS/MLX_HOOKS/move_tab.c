/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:01:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/24 21:05:49 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_movetab(move_tab *functions)
{
	functions[0] = move_forward;
	functions[1] = move_backward; 
	functions[2] = straf_leftward; 
	functions[3] = straf_rightward; 
	functions[4] = rotate_leftward;
	functions[5] = rotate_rightward;
	functions[6] = NULL;
}

void	handle_movement(t_data *data, t_keys *key)
{
	int			i;
	move_tab	functions[7];
	t_point		new_player;
	
	i = 0;
	init_movetab(functions);
	while (i < 6)
	{
		if (key->key_tab[i] == 1)
			functions[i](data);
		i++;
	}
	new_player.x = data->player.x;
	new_player.y = data->player.y;
	if (avoid_collisions(data, &new_player) == FAILURE)
		return ;
	// Mise a jour de la position du joueur
	data->player.x = roundf(new_player.x);
	data->player.y = roundf(new_player.y);
}

void	reset_var(t_data *data)
{
	data->move.x = 0;
	data->move.y = 0;
}
