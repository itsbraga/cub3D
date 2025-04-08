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

#include "cub3D.h"

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
static void	__draw_player(t_minimap *mmap, t_player *player)
{
	const int		width = (int)(mmap->tile_size * 0.6);
	const float		height = width * 1.3;
	const float		offset_dist = width * 0.5;
	t_triangle		triangle;
	t_point			new_pos;

	ft_bzero(&triangle, sizeof(t_triangle));
	triangle.theta = degree_to_radian(player->dir);
	__calculate_player_trigonometry(triangle.theta, &triangle.trig);
	new_pos.x = player->pos.x - triangle.trig.cos_theta * offset_dist;
	new_pos.y = player->pos.y - triangle.trig.sin_theta * offset_dist;
	triangle.a.x = new_pos.x + triangle.trig.cos_theta * height;
	triangle.a.y = new_pos.y + triangle.trig.sin_theta * height;
	triangle.b.x = new_pos.x + triangle.trig.cos_theta_plus_pi2 * offset_dist;
	triangle.b.y = new_pos.y + triangle.trig.sin_theta_plus_pi2 * offset_dist;
	triangle.c.x = new_pos.x + triangle.trig.cos_theta_minus_pi2 * offset_dist;
	triangle.c.y = new_pos.y + triangle.trig.sin_theta_minus_pi2 * offset_dist;
	draw_line(&mmap->img, triangle.a, triangle.b, RED_PIX);
	draw_line(&mmap->img, triangle.b, triangle.c, RED_PIX);
	draw_line(&mmap->img, triangle.c, triangle.a, RED_PIX);
	fill_triangle(mmap, triangle.a, triangle.b, triangle.c);
}

void	draw_centered_player(t_game *game, t_minimap *mmap)
{
	t_player	player_copy;
	t_point		center;

	player_copy = *(game->player);
	center.x = mmap->width / 2;
	center.y = mmap->height / 2;
	player_copy.pos = center;
	__draw_player(mmap, &player_copy);
}
