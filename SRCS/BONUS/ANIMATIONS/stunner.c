/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stunner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:08:32 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/18 21:20:00 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	__handle_fire_frames(t_game *g, t_weapon *w)
{
	if (w->frame >= (FBS * 4 - 1) && w->frame < (FBS * 4))
		draw_weapon(5, w, g);
	else if (w->frame >= (FBS * 4) && w->frame < (FBS * 4 + 1))
		draw_weapon(6, w, g);
	else if (w->frame >= (FBS * 4 + 1) && w->frame < (FBS * 5 + 1))
		draw_weapon(7, w, g);
	else if (w->frame >= (FBS * 5 + 1) && w->frame < (FBS * 6))
		draw_weapon(5, w, g);
	else if (w->frame >= (FBS * 6) && w->frame < (FBS * 6 + 1))
		draw_weapon(3, w, g);
	else if (w->frame >= (FBS * 6 + 1) && w->frame < (FBS * 6 + 2))
	{
		draw_weapon(1, w, g);
		if (w->frame == (FBS * 6 + 1))
		{
			w->state = IDLE;
			w->frame = 0;
			w->frame_counter_started = false;
		}
	}
}

void	render_stunner(t_game *g, t_weapon *w)
{
	if (w->state == SHOOTING && w->frame == 0)
		w->frame_counter_started = true;
	if (w->frame >= 0 && w->frame < FBS)
		draw_weapon(IDLE, w, g);
	else if (w->frame >= FBS && w->frame < (FBS * 2 - 1))
		draw_weapon(1, w, g);
	else if (w->frame >= (FBS * 2 - 1) && w->frame < (FBS * 2 + 1))
		draw_weapon(2, w, g);
	else if (w->frame >= (FBS * 2 + 1) && w->frame < (FBS * 3))
		draw_weapon(3, w, g);
	else if (w->frame >= (FBS * 3) && w->frame < (FBS * 4 - 1))
		draw_weapon(4, w, g);
	else
		__handle_fire_frames(g, w);
	if (w->frame_counter_started == true)
		w->frame++;
}
