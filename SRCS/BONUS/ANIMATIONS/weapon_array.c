/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:31:17 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 18:17:08 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	__init_weapon_array(t_weapon_array *functions)
{
	functions[0] = render_mp40;
	functions[1] = render_glock21;
	functions[2] = NULL;
}

void	render_curr_weapon(t_game *g)
{
	t_weapon_array	functions[3];
	t_data			*d;
	int				curr_weapon;

	d = g->data;
	if (d->weapon_count == 0)
		return ;
	curr_weapon = d->curr_weapon_idx;
	__init_weapon_array(functions);
	functions[curr_weapon](g, d->weapons[curr_weapon]);
}
