/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:01:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/16 15:37:46 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__init_move_array(t_move_array *functions)
{
	functions[0] = move_forward;
	functions[1] = move_backward;
	functions[2] = straf_leftward;
	functions[3] = straf_rightward;
	functions[4] = rotate_leftward;
	functions[5] = rotate_rightward;
	functions[6] = shoot;
	functions[7] = NULL;
}

void	mandatory_player_moves(t_data *data, t_player *player)
{
	t_point	new_ppos;
	t_map	*map;

	map = data->map;
	new_ppos.x = roundf(player->pos.x + player->move.x);
	new_ppos.y = roundf(player->pos.y + player->move.y);
	if (new_ppos.x < 0 || new_ppos.x >= map->size.width * TILE_SIZE
		|| new_ppos.y < 0 || new_ppos.y >= map->size.height * TILE_SIZE)
		return ;
	player->pos.x = new_ppos.x;
	player->pos.y = new_ppos.y;
}

void	bonus_player_moves(t_data *data, t_player *player)
{
	t_point	check_pos_x;
	t_point	check_pos_y;

	check_pos_x.x = player->pos.x + player->move.x;
	check_pos_x.y = player->pos.y;
	if (is_position_colliding(data, check_pos_x) == false)
		player->pos.x = roundf(check_pos_x.x);
	check_pos_y.x = player->pos.x;
	check_pos_y.y = player->pos.y + player->move.y;
	if (is_position_colliding(data, check_pos_y) == false)
		player->pos.y = roundf(check_pos_y.y);
}

void	move_player(t_game *game, t_keys *key)
{
	int				i;
	t_move_array	functions[8];
	t_player		*player;

	player = game->player;
	__init_move_array(functions);
	i = 0;
	while (i < 7)
	{
		if (key->key_array[i] == 1)
			functions[i](game);
		i++;
	}
	if (!BONUS)
		mandatory_player_moves(game->data, player);
	else
	{
		bonus_player_moves(game->data, player);
		if (key->mouse_btn[0] == 1)
			shoot(game);
	}
}

void	reset_move(t_player *player)
{
	player->move.x = 0;
	player->move.y = 0;
}
