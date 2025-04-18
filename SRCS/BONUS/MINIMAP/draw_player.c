/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                          			:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:41:54 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/12 18:11:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*
	theta + PI2 -> +90 degrees
	theta - PI2 -> -90 degrees
*/
static void	__calculate_player_trigonometry(float theta, t_trigo *trig)
{
	trig->cos_theta = cos(theta);
	trig->sin_theta = sin(theta);
	trig->cos_theta_plus_pi2 = cos(theta + PI2);
	trig->sin_theta_plus_pi2 = sin(theta + PI2);
	trig->cos_theta_minus_pi2 = cos(theta - PI2);
	trig->sin_theta_minus_pi2 = sin(theta - PI2);
}

/*
	Draws the player as a directional triangle on the minimap
	
	The function:
	- Calculates triangle dimensions based on tile size
	- Computes triangle points using player's position and direction
	- Creates an isosceles triangle pointing in player's direction
	- Draws both outline and filled triangle in red
	Note: Triangle size is slightly smaller than tile size (60% of it)
*/
static void	__draw_player(t_minimap *mmap, t_player *p)
{
	const int		width = (int)(mmap->tile_size * 0.6);
	const float		height = width * 1.3;
	const float		offset_dist = width * 0.5;
	t_triangle		t;
	t_point			new_pos;

	ft_bzero(&t, sizeof(t_triangle));
	t.theta = degree_to_radian(p->dir);
	__calculate_player_trigonometry(t.theta, &t.trig);
	new_pos.x = p->pos.x - t.trig.cos_theta * offset_dist;
	new_pos.y = p->pos.y - t.trig.sin_theta * offset_dist;
	t.a.x = new_pos.x + t.trig.cos_theta * height;
	t.a.y = new_pos.y + t.trig.sin_theta * height;
	t.b.x = new_pos.x + t.trig.cos_theta_plus_pi2 * offset_dist;
	t.b.y = new_pos.y + t.trig.sin_theta_plus_pi2 * offset_dist;
	t.c.x = new_pos.x + t.trig.cos_theta_minus_pi2 * offset_dist;
	t.c.y = new_pos.y + t.trig.sin_theta_minus_pi2 * offset_dist;
	draw_line(&mmap->img, t.a, t.b, RED_PIX);
	draw_line(&mmap->img, t.b, t.c, RED_PIX);
	draw_line(&mmap->img, t.c, t.a, RED_PIX);
	fill_triangle(mmap, t.a, t.b, t.c);
}

void	draw_centered_player(t_game *g, t_minimap *mmap)
{
	t_player	player_copy;
	t_point		center;

	player_copy = *(g->player);
	center.x = mmap->width / 2;
	center.y = mmap->height / 2;
	player_copy.pos = center;
	__draw_player(mmap, &player_copy);
}
