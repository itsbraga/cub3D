/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:36:16 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/04 18:28:12 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	handle_collisions(t_game *game, t_point *new_player_pos)
{
	t_point	cell;

	cell.x = 0;
	cell.y = 0;
	new_player_pos->x += game->move.x;
	new_player_pos->y += game->move.y;
	cell.x = (new_player_pos->x * game->map->width) / WIN_WIDTH;
	cell.y = (new_player_pos->y * game->map->height) / WIN_HEIGHT;
	if (game->map->map2d[(int)cell.y][(int)cell.x] == '1')
	{
		printf(BOLD RED "/!\\ WARNING /!\\\t--> Collision\n" RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}
