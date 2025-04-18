/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp40.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:58:18 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/18 18:14:37 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	render_mp40(t_game *g, t_weapon *w)
{
	if (w->state == SHOOTING && w->frame == 0)
		w->frame_counter_started = true;
	if (w->frame >= 0 && w->frame < FBS)
		draw_weapon(IDLE, w, g);
	else if (w->frame >= FBS && w->frame < (FBS * 2))
		draw_weapon(PREFIRE, w, g);
	else if (w->frame >= (FBS * 2) && w->frame < (FBS * 3 + 2))
		draw_weapon(SHOOTING, w, g);
	else if (w->frame >= (FBS * 3 + 2) && w->frame < (FBS * 4 + 2))
	{
		draw_weapon(POSTFIRE, w, g);
		if (g->keys->key_array[_SPACE] == 0 && g->keys->mouse_btn[0] == 0)
			w->state = IDLE;
		if (w->state == IDLE && w->frame == (FBS * 4 + 1))
		{
			w->frame = 0;
			w->frame_counter_started = false;
		}
		else if (w->state == SHOOTING && w->frame == (FBS * 4 + 1))
			w->frame = (FBS * 2 - 1);
	}
	if (w->frame_counter_started == true)
		w->frame++;
}

/*
	FBS = 3
	J'appuie sur espace -> rendre deux sprites (recoil1 et fire)
	4 frame avant d'afficher recoil1 et 4 frame pour fire
	Je relache espace -> rendre deux sprites (recoil2 et retour a idle)
	4 frame avant d'afficher recoil2 et 4 frame pour revenir a idle
	Quand retour a idle remettre frame_counter a 0

	IDLE(0) + 4 = 4
	RECOIL1(4) + 4 = 8
	FIRE(8) + 4 = 12
	RECOIL2(12) = 16
*/