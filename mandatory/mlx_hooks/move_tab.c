/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:01:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/27 20:12:24 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_movetab(move_tab *functions)
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
	move_tab	functions[7];
	
	i = 0;
	init_movetab(functions);
	while (i < 6)
	{
		if (key->key_tab[i] == 1)
			functions[i](data);
		i++;
	}
	data->player.x = roundf(data->player.x + data->move.x);
	data->player.y = roundf(data->player.y + data->move.y);
}

void	reset_var(t_data *data)
{
	data->move.x = 0;
	data->move.y = 0;
}
