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

void	move_player(t_game *game, t_keys *key)
{
	int			i;
	move_array	functions[7];
	t_point		new_player_pos;
	
	i = 0;
	if (game->game_state != STATE_GAME)
		return ;
	__init_move_array(functions);
	while (i < 6)
	{
		if (key->key_array[i] == 1)
			functions[i](game, data_s());
		i++;
	}
	new_player_pos.x = game->player_pos.x;
	new_player_pos.y = game->player_pos.y;
	if (handle_collisions(game, &new_player_pos) == FAILURE)
		return ;
	// Mise a jour de la position du joueur si pas de collision trouvée
	game->player_pos.x = roundf(new_player_pos.x);
	game->player_pos.y = roundf(new_player_pos.y);
}

void	reset_var(t_game *game)
{
	game->player->move.x = 0;
	game->player->move.y = 0;
}
