/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stunner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:08:32 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/18 19:41:39 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D_bonus.h"

static void	__handle_fire_frames(t_game *game, t_weapon *w)
{
	if (w->frame >= (FBS * 4 - 1) && w->frame < (FBS * 4))
		draw_weapon(5, w, game); //Fire1
	else if (w->frame >= (FBS * 4) && w->frame < (FBS * 4 + 1))
		draw_weapon(6, w, game); //Fire2
	else if (w->frame >= (FBS * 4 + 1) && w->frame < (FBS * 5 + 1))
		draw_weapon(7, w, game); //Fire3
	else if (w->frame >= (FBS * 5 + 1) && w->frame < (FBS * 6))
		draw_weapon(5, w, game); //Fire1
	else if (w->frame >= (FBS * 6) && w->frame < (FBS * 6 + 1))
		draw_weapon(3, w, game); //BefFire3
	else if (w->frame >= (FBS * 6 + 1) && w->frame < (FBS * 6 + 2))
	{
		draw_weapon(1, w, game); //BefFire1
		if (w->frame == (FBS * 6 + 1))
		{
			w->state = IDLE;
			w->frame = 0;
			w->frame_counter_started = false;
		}
	}
}

void	render_stunner(t_game *game, t_weapon *w)
{
	if (w->state == SHOOTING && w->frame == 0)
		w->frame_counter_started = true;
	if (w->frame >= 0 && w->frame < FBS)
		draw_weapon(IDLE, w, game);
	else if (w->frame >= FBS && w->frame < (FBS * 2 - 1))
		draw_weapon(1, w, game); //BefFire1
	else if (w->frame >= (FBS * 2 - 1) && w->frame < (FBS * 2 + 1))
		draw_weapon(2, w, game); //BefFire2
	else if (w->frame >= (FBS * 2 + 1) && w->frame < (FBS * 3))
		draw_weapon(3, w, game); //BefFire3
	else if (w->frame >= (FBS * 3) && w->frame < (FBS * 4 - 1))
		draw_weapon(4, w, game); //BefFire4
	else
		__handle_fire_frames(game, w);
	if (w->frame_counter_started == true)
		w->frame++;
}
