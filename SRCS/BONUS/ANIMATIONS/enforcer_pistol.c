/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enforcer_pistol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:21:19 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/15 22:38:41 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__handle_recoil_frames(t_game *game, t_weapon *w)
{
	if (w->frame >= (FBS * 3 + 3) && w->frame < (FBS * 4 + 4))
		draw_weapon(3, w, game); // Recoil1
	else if (w->frame >= (FBS * 4 + 4) && w->frame < (FBS * 5 + 5))
		draw_weapon(4, w, game); // Recoil2
	else if (w->frame >= (FBS * 5 + 5) && w->frame < (FBS * 6 + 6))
		draw_weapon(5, w, game); // Recoil3
	else if (w->frame >= (FBS * 6 + 6) && w->frame < (FBS * 7 + 7))
	{
		draw_weapon(6, w, game); // Recoil4
		if (w->frame == (FBS * 7 + 6))
		{
			w->state = IDLE;
			w->frame = 0;
			w->frame_counter_started = false;
		}
	}
}

void	render_enforcer_pistol(t_game *game, t_weapon *w)
{
	if (w->state == SHOOTING && w->frame == 0)
		w->frame_counter_started = true;
	if (w->frame >= 0 && w->frame < FBS)
		draw_weapon(IDLE, w, game);
	else if (w->frame >= FBS && w->frame < (FBS * 2 + 1))
		draw_weapon(1, w, game); // Fire1
	else if (w->frame >= (FBS * 2 + 1) && w->frame < (FBS * 3 + 3))
		draw_weapon(2, w, game); // Fire2
	else
		__handle_recoil_frames(game, w);
	if (w->frame_counter_started == true)
		w->frame++;
}
