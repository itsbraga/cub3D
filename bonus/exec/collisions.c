/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:36:16 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/04 02:12:53 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	handle_collisions(t_data *data, t_point *new_player_pos)
{
	t_point	cell;

	cell.x = 0;
	cell.y = 0;
	new_player_pos->x += data->move.x;
	new_player_pos->y += data->move.y;
	cell.x = (new_player_pos->x * data->map->width) / WIN_WIDTH;
	cell.y = (new_player_pos->y * data->map->height) / WIN_HEIGHT;
	if (data->map->map2d[(int)cell.y][(int)cell.x] == '1')
	{
		printf(BOLD RED "/!\\ WARNING /!\\\t--> Collision\n" RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}

// static void	__convert_safe_player_pos_into_map_cell(t_collision *col)
// {
// 	float	safe_pos_x;
// 	float	safe_pos_y;

// 	col->safety_radius = 0.4;
// 	safe_pos_x = col->next_player_pos.x + data_s()->move.x * col->safety_radius;
// 	safe_pos_y = col->next_player_pos.y + data_s()->move.y * col->safety_radius;
	
// 	col->next_cell.x = (safe_pos_x * data_s()->map->width) / WIN_WIDTH;
// 	col->next_cell.y = (safe_pos_y * data_s()->map->height) / WIN_HEIGHT;
// }

// int	handle_collisions(t_data *data, t_collision *col)
// {
// 	__convert_safe_player_pos_into_map_cell(col);
// 	if (data->map->map2d[(int)col->next_cell.y][(int)col->next_cell.x] == '1')
// 	{
// 		printf(BOLD RED "/!\\ WARNING /!\\\t--> Collision\n" RESET);
// 		if (data->move.y < 0) // Mur derriere
// 			data->move.y = 0;
// 		else if (data->move.y > 0) // Mur en face
// 			data->move.y = 0;
// 		if (data->move.x < 0) // Mur a gauche
// 			data->move.x = 0;
// 		else if (data->move.x > 0) // Mur a droite
// 			data->move.x = 0;
// 		return (FAILURE);
// 	}
// 	return (SUCCESS);
// }
