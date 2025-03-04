/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:01:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/04 02:17:22 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	__init_move_array(move_array *functions)
{
	functions[0] = move_forward;
	functions[1] = move_backward; 
	functions[2] = straf_leftward; 
	functions[3] = straf_rightward; 
	functions[4] = rotate_leftward;
	functions[5] = rotate_rightward;
	functions[6] = NULL;
}

void	update_player_move(t_data *data, t_keys *key)
{
	int			i;
	move_array	functions[7];
	t_point		new_player_pos;
	
	i = 0;
	__init_move_array(functions);
	if (data->game_state != STATE_GAME)
		return ;
	while (i < 6)
	{
		if (key->key_array[i] == 1)
			functions[i](data);
		i++;
	}
	new_player_pos.x = data->player_pos.x;
	new_player_pos.y = data->player_pos.y;
	// data->collision.next_player_pos.x = data->player_pos.x;
	// data->collision.next_player_pos.y = data->player_pos.y;
	if (handle_collisions(data, &new_player_pos) == FAILURE)
		return ;
	// Mise a jour de la position du joueur si pas de collision trouvée
	data->player_pos.x = roundf(new_player_pos.x);
	data->player_pos.y = roundf(new_player_pos.y);
	// data->player_pos.x += data->move.x;
	// data->player_pos.y += data->move.y;
}

void	reset_var(t_data *data)
{
	data->move.x = 0;
	data->move.y = 0;
}
