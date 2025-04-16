/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glock21.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 02:07:53 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/16 03:12:20 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	__handle_recoil_frames(t_game *game, t_weapon *w)
{
	if (w->frame >= (FBS * 2 + 1) && w->frame < (FBS * 3))
		draw_weapon(2, w, game); // Recoil1
	else if (w->frame >= (FBS * 3) && w->frame < (FBS * 4 - 1))
		draw_weapon(3, w, game); // Recoil2
	else if (w->frame >= (FBS * 4 - 1) && w->frame < (FBS * 5 - 2))
		draw_weapon(4, w, game); // Recoil3
	else if (w->frame >= (FBS * 5 - 2) && w->frame < (FBS * 5))
	{
		draw_weapon(3, w, game); // Recoil2
		if (w->frame == (FBS * 5 - 1))
		{
			w->state = IDLE;
			w->frame = 0;
			w->frame_counter_started = false;
		}
	}
}

void	render_glock21(t_game *game, t_weapon *w)
{
	if (w->state == SHOOTING && w->frame == 0)
		w->frame_counter_started = true;
	if (w->frame >= 0 && w->frame < FBS)
		draw_weapon(IDLE, w, game);
	else if (w->frame >= FBS && w->frame < (FBS * 2 + 1))
		draw_weapon(1, w, game); // Fire
	else
		__handle_recoil_frames(game, w);
	if (w->frame_counter_started == true)
		w->frame++;
}
