/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_inter_v.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:27:28 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/16 13:46:37 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	__ray_is_horizontal(float ray_rad, t_player *p, t_raycasting *r)
{
	if (fabs(ray_rad - PI) < EPS || fabs(ray_rad) < EPS)
	{
		r->v_ray_inter.x = p->pos.x;
		r->v_ray_inter.y = p->pos.y;
		return (true);
	}
	else
		return (false);
}

static void	__define_v_offset(float ray_rad, float neg_tan, t_raycasting *r)
{
	if (ray_rad > PI2 && ray_rad < PI3)
		r->v_offset.x = -TILE_SIZE;
	else if (ray_rad < PI2 || ray_rad > PI3)
		r->v_offset.x = TILE_SIZE;
	r->v_offset.y = -r->v_offset.x * neg_tan;
}

static void	__ray_travel_loop(t_raycasting *r, t_data *d)
{
	t_point	curr_tile;

	curr_tile = (t_point){0.0f, 0.0f};
	while (true)
	{
		curr_tile.x = r->v_ray_inter.x / TILE_SIZE;
		curr_tile.y = r->v_ray_inter.y / TILE_SIZE;
		if ((int)curr_tile.x < 0
			|| (size_t)curr_tile.x >= d->map->size.width
			|| (int)curr_tile.y < 0
			|| (size_t)curr_tile.y >= d->map->size.height)
			break ;
		else if (d->map->map2d[(int)curr_tile.y][(int)curr_tile.x] == '1')
			break ;
		else
		{
			if (d->map->map2d[(int)curr_tile.y][(int)curr_tile.x] == '2')
			{
				if (can_vray_pass_door(r->v_ray_inter, d) == false)
					break ;
			}
			r->v_ray_inter.x += r->v_offset.x;
			r->v_ray_inter.y += r->v_offset.y;
		}
	}
}

void	inter_vline(t_data *d, t_player *p, t_raycasting *r, float ray_rad)
{
	float	neg_tan;

	neg_tan = -tan(ray_rad);
	if (__ray_is_horizontal(ray_rad, p, r) == true)
		return ;
	else if (ray_rad > PI2 && ray_rad < PI3)
	{
		r->v_ray_inter.x = floor(p->pos.x / TILE_SIZE) * TILE_SIZE - 0.0001;
		r->v_ray_inter.y = p->pos.y + (p->pos.x - r->v_ray_inter.x) * neg_tan;
		__define_v_offset(ray_rad, neg_tan, r);
	}
	else if (ray_rad < PI2 || ray_rad > PI3)
	{
		r->v_ray_inter.x = floor(p->pos.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		r->v_ray_inter.y = p->pos.y + (p->pos.x - r->v_ray_inter.x) * neg_tan;
		__define_v_offset(ray_rad, neg_tan, r);
	}
	__ray_travel_loop(r, d);
}
