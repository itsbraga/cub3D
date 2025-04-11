/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:58:18 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/11 04:28:38 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_weapon(int state, t_weapon *w, t_game *game)
{
	t_mlx	*mlx;

	mlx = game->mlx;
	my_put_img_to_window(&w->sprites.imgs[state], &mlx->img,
		w->pos.x, w->pos.y);
}

void	render_weapon(t_game *game, t_weapon *w)
{
	if (w->state == SHOOTING && w->frame == 0)
		w->frame_counter_started = true;
	if (w->frame >= 0 && w->frame < FBS)
		draw_weapon(IDLE, w, game);
	else if (w->frame >= FBS && w->frame < (FBS * 2))
		draw_weapon(PREFIRE, w, game);
	else if (w->frame >= (FBS * 2) && w->frame < (FBS * 3 + 2))
		draw_weapon(SHOOTING, w, game);
	else if (w->frame >= (FBS * 3 + 2) && w->frame < (FBS * 4 + 2))
	{
		draw_weapon(POSTFIRE, w, game);
		if (game->keys->key_array[_SPACE] == 0)
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