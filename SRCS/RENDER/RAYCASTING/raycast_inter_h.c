/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_inter_h.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:20:43 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/18 18:22:42 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	__ray_is_vertical(float ray_rad, t_player *p, t_raycasting *r)
{
	if (fabs(ray_rad - PI2) < EPS || fabs(ray_rad - PI3) < EPS)
	{
		r->h_ray_inter.x = p->pos.x;
		r->h_ray_inter.y = p->pos.y;
		return (true);
	}
	return (false);
}

static void	__define_h_offset(float ray_rad, float inv_tan, t_raycasting *r)
{
	if (ray_rad > PI)
		r->h_offset.y = -TILE_SIZE;
	else if (ray_rad < PI)
		r->h_offset.y = TILE_SIZE;
	r->h_offset.x = -r->h_offset.y * inv_tan;
}

static void	__ray_travel_loop(t_raycasting *r, t_data *d)
{
	t_point	curr_tile;

	curr_tile = (t_point){0.0f, 0.0f};
	while (true)
	{
		curr_tile.x = r->h_ray_inter.x / TILE_SIZE;
		curr_tile.y = r->h_ray_inter.y / TILE_SIZE;
		if ((int)curr_tile.x < 0 || (size_t)curr_tile.x >= d->map->size.width
			|| (int)curr_tile.y < 0
			|| (size_t)curr_tile.y >= d->map->size.height)
			break ;
		else if (d->map->map2d[(int)curr_tile.y][(int)curr_tile.x] == '1')
			break ;
		else
		{
			if (d->map->map2d[(int)curr_tile.y][(int)curr_tile.x] == '2')
			{
				if (can_hray_pass_door(r->h_ray_inter, d) == false)
					break ;
			}
			r->h_ray_inter.x += r->h_offset.x;
			r->h_ray_inter.y += r->h_offset.y;
		}
	}
}

void	inter_hline(t_data *d, t_player *p, t_raycasting *r, float ray_rad)
{
	float	inv_tan;

	inv_tan = 0.0f;
	if (tan(ray_rad) != 0)
		inv_tan = -1 / tan(ray_rad);
	else
		inv_tan = 0;
	if (__ray_is_vertical(ray_rad, p, r) == true)
		return ;
	else if (ray_rad > PI)
	{
		r->h_ray_inter.y = floor(p->pos.y / TILE_SIZE) * TILE_SIZE - 0.0001;
		r->h_ray_inter.x = p->pos.x + (p->pos.y - r->h_ray_inter.y) * inv_tan;
		__define_h_offset(ray_rad, inv_tan, r);
	}
	else if (ray_rad < PI)
	{
		r->h_ray_inter.y = floor(p->pos.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		r->h_ray_inter.x = p->pos.x + (p->pos.y - r->h_ray_inter.y) * inv_tan;
		__define_h_offset(ray_rad, inv_tan, r);
	}
	__ray_travel_loop(r, d);
}
