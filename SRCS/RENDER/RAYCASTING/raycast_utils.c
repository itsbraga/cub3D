/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:20:32 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/16 04:03:04 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__get_distances(float *dh, float *dv, t_player *p, t_raycasting *r)
{
	float	delta_xh;
	float	delta_yh;
	float	delta_xv;
	float	delta_yv;

	delta_xh = r->h_ray_inter.x - p->pos.x;
	delta_yh = r->h_ray_inter.y - p->pos.y;
	delta_xv = r->v_ray_inter.x - p->pos.x;
	delta_yv = r->v_ray_inter.y - p->pos.y;
	*dh = (delta_xh * delta_xh) + (delta_yh * delta_yh);
	*dv = (delta_xv * delta_xv) + (delta_yv * delta_yv);
}

static void	__find_closest_inter(float dist_h, float dist_v, t_raycasting *r)
{
	if (dist_h < dist_v)
	{
		r->closest_inter = r->h_ray_inter;
		r->dist_wall = sqrt(dist_h);
		r->tex_x = (int)r->closest_inter.x & (TILE_SIZE - 1);
		r->vertical_hit = false;
	}
	else
	{
		r->closest_inter = r->v_ray_inter;
		r->dist_wall = sqrt(dist_v);
		r->tex_x = (int)r->closest_inter.y & (TILE_SIZE - 1);
		r->vertical_hit = true;
	}
}

static void	__get_door_info(t_data *data, t_raycasting *r)
{
	if (r->curr_ray == (WIN_HEIGHT / 2))
	{
		r->door_ray.x = r->closest_inter.x;
		r->door_ray.y = r->closest_inter.y;
	}
	r->is_door = is_door(data, r->closest_inter);
	if (r->is_door == true)
	{
		r->door_tex_offset = data->doors[data->door_index].ratio * TILE_SIZE;
		r->tex_x = (r->tex_x + r->door_tex_offset) & (TILE_SIZE - 1);
	}
}

void	get_draw_info(t_data *data, t_player *player, t_raycasting *r)
{
	float	dist_h;
	float	dist_v;
		
	dist_h = 0.0f;
	dist_v = 0.0f;
	__get_distances(&dist_h, &dist_v, player, r);
	__find_closest_inter(dist_h, dist_v, r);
	__get_door_info(data, r);
}
