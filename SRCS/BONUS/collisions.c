/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:36:16 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/24 20:45:42 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	avoid_collisions(t_data *data, t_point *new_player)
{
	t_point	cell;

	cell.x = 0;
	cell.y = 0;
	new_player->x += data->move.x;
	new_player->y += data->move.y;
	// printf("New player pos: (%.2f, %.2f)\n", new_player->x, new_player->y);
	cell.x = new_player->x * data->map->M_WIDTH / W_WIDTH;
	cell.y = new_player->y * data->map->M_HEIGHT / W_HEIGHT;
	// printf("Cell value: %c\n", data->map->map2d[(int)cell.y][(int)cell.x]);
	if (data->map->map2d[(int)cell.y][(int)cell.x] == '1')
	{
		printf(BOLD RED "Collision!\n" RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}
