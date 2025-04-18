/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:01:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 18:22:09 by annabrag         ###   ########.fr       */
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

void	mandatory_player_moves(t_data *d, t_player *p)
{
	t_point	new_ppos;
	t_map	*map;

	map = d->map;
	new_ppos.x = roundf(p->pos.x + p->move.x);
	new_ppos.y = roundf(p->pos.y + p->move.y);
	if (new_ppos.x < 0 || new_ppos.x >= map->size.width * TILE_SIZE
		|| new_ppos.y < 0 || new_ppos.y >= map->size.height * TILE_SIZE)
		return ;
	p->pos.x = new_ppos.x;
	p->pos.y = new_ppos.y;
}

void	bonus_player_moves(t_data *d, t_player *p)
{
	t_point	check_pos_x;
	t_point	check_pos_y;

	check_pos_x.x = p->pos.x + p->move.x;
	check_pos_x.y = p->pos.y;
	if (is_position_colliding(d, check_pos_x) == false)
		p->pos.x = roundf(check_pos_x.x);
	check_pos_y.x = p->pos.x;
	check_pos_y.y = p->pos.y + p->move.y;
	if (is_position_colliding(d, check_pos_y) == false)
		p->pos.y = roundf(check_pos_y.y);
}

void	move_player(t_game *g, t_keys *key)
{
	int				i;
	t_move_array	functions[8];
	t_player		*player;

	player = g->player;
	__init_move_array(functions);
	i = 0;
	while (i < 7)
	{
		if (key->key_array[i] == 1)
			functions[i](g);
		i++;
	}
	if (!BONUS)
		mandatory_player_moves(g->data, player);
	else
	{
		bonus_player_moves(g->data, player);
		if (key->mouse_btn[0] == 1)
			shoot(g);
	}
}

void	reset_move(t_player *p)
{
	p->move.x = 0;
	p->move.y = 0;
}
