/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 04:57:06 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/16 15:38:44 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	shoot(t_game *game)
{
	t_data		*data;
	t_weapon	*curr_weapon;

	data = game->data;
	if (data->weapon_count == 0)
		return ;
	curr_weapon = data->weapons[data->curr_weapon_idx];
	if (game->keys->key_array[_SPACE] == 1 || game->keys->mouse_btn[0] == 1)
		curr_weapon->state = SHOOTING;
}
