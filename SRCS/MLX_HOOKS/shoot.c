/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 04:57:06 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/08 22:20:55 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	shoot(t_game *game)
{
	if (game->keys->key_array[_SPACE] == 1)
	{
		game->data->weapon->state = SHOOTING;
		// d->weapon->still_shooting = true;
	}
}

//FBS = 3
// J'appuie sur espace -> rendre deux sprites (recoil1 et fire)
// 4 frame avant d'afficher recoil1 et 4 frame pour fire
// Je relache espace -> rendre deux sprite (recoil2 et retour a idle)
// 4 frame avant d'afficher recoil2 et 4 frame pour revenir a idle
// quand retour a idle remettre frame_counter a 0
//IDLE(0) + 4 = 4
//RECOIL1(4) + 4 = 8
//FIRE(8) + 4 = 12
//RECOIL2(12) = 16