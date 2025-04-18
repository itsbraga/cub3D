/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 04:57:06 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/18 18:17:07 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	shoot(t_game *g)
{
	t_data		*d;
	t_weapon	*curr_weapon;

	d = g->data;
	if (d->weapon_count == 0)
		return ;
	curr_weapon = d->weapons[d->curr_weapon_idx];
	if (g->keys->key_array[_SPACE] == 1 || g->keys->mouse_btn[0] == 1)
		curr_weapon->state = SHOOTING;
}
