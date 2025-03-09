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

void	move_player(t_player *player, t_keys *key)
{
	int			i;
	move_array	functions[7];
	t_point		new_player_pos;
	
	i = 0;
	if (game_s()->state != GAME)
		return ;
	__init_move_array(functions);
	while (i < 6)
	{
		if (key->key_array[i] == 1)
			functions[i](player);
		i++;
	}
	new_player_pos.x = player->pos.x;
	new_player_pos.y = player->pos.y;
	if (handle_collisions(player, &new_player_pos) == FAILURE)
		return ;
	// Mise a jour de la position du joueur si pas de collision trouvée
	player->pos.x = roundf(new_player_pos.x);
	player->pos.y = roundf(new_player_pos.y);
}

void	reset_var(t_player *player)
{
	player->move.x = 0;
	player->move.y = 0;
}
