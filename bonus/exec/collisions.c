/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:36:16 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/09 23:57:13 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

short	handle_collisions(t_player *player, t_point *new_player_pos)
{
	t_point	cell;

	cell.x = 0;
	cell.y = 0;
	new_player_pos->x += player->move.x;
	new_player_pos->y += player->move.y;
	cell.x = (new_player_pos->x * data_s()->map->width) / WIN_WIDTH;
	cell.y = (new_player_pos->y * data_s()->map->height) / WIN_HEIGHT;
	if (data_s()->map->map2d[(int)cell.y][(int)cell.x] == '1')
	{
		printf(BOLD RED "/!\\ WARNING /!\\\t--> Collision\n" RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}
