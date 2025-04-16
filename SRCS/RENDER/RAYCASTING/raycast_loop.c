/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:48:06 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/16 18:35:59 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__init_wall_limits(int wall_limits[][2])
{
	int	i;

	i = 0;
	while (i < WIN_WIDTH)
	{
		wall_limits[i][0] = 0;
		wall_limits[i][1] = 0;
		i++;
	}
}

static void	__set_wall_limits(int wall_limits[][2], t_raycasting *r)
{
	wall_limits[r->curr_ray][0] = r->wall_start_y;
	wall_limits[r->curr_ray][1] = r->wall_end_y;
}

// With ray_rad, we start with the leftmost ray (one ray per x)
void	raycasting(t_data *d, t_player *p, t_raycasting *r)
{
	float	ray_rad;
	int		wall_limits[WIN_WIDTH][2];

	ray_rad = 0.0f;
	__init_wall_limits(wall_limits);
	r->curr_ray = 0;
	r->player_rad = degree_to_radian(p->dir);
	printf("player_rad = %f\n", r->player_rad);
	ray_rad = norm_rad_angle(r->player_rad - (degree_to_radian(r->fov) / 2));
	while (r->curr_ray < WIN_WIDTH)
	{
		(inter_hline(d, p, r, ray_rad), inter_vline(d, p, r, ray_rad));
		get_draw_info(d, p, r);
		draw_wall_tex(r, ray_rad);
		__set_wall_limits(wall_limits, r);
		if (!BONUS)
			(draw_floor_color(r, d), draw_ceil_color(r, d));
		ray_rad += (degree_to_radian(r->fov) / WIN_WIDTH);
		ray_rad = norm_rad_angle(ray_rad);
		r->curr_ray++;
	}
	if (BONUS)
		(draw_floor_tex(r, wall_limits, p), draw_ceil_tex(r, wall_limits, p));
}
