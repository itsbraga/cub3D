/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:31:17 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/15 19:24:12 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__init_weapon_array(t_weapon_array *functions)
{
	functions[0] = render_mp40;
	functions[1] = render_enforcer_pistol;
	functions[2] = NULL;
}

void	render_curr_weapon(t_game *game)
{
	t_weapon_array	functions[3];
	t_data			*data;
	int				curr_weapon;

	data = game->data;
	if (data->weapon_count == 0)
		return ;
	curr_weapon = data->curr_weapon_idx;
	__init_weapon_array(functions);
	functions[curr_weapon](game, data->weapons[curr_weapon]);
}
