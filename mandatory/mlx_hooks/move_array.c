/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:01:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/03 20:48:02 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	
	i = 0;
	if (game->state != GAME)
		return ;
	__init_move_array(functions);
	while (i < 6)
	{
		if (key->key_array[i] == 1)
			functions[i](game->player);
		i++;
	}
	game->player->pos.x = roundf(game->player->pos.x + game->player->move.x);
	game->player->pos.y = roundf(game->player->pos.y + game->player->move.y);
}

void	reset_var(t_game *game)
{
	game->player->move.x = 0;
	game->player->move.y = 0;
}
