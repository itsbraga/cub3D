/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:48:06 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/24 20:55:44 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Draw 3D rays
void	raycasting(t_data *data, t_map *m, t_ray *r)
{
	float	ray_angle;
	float	inv_tan;

	ray_angle = get_radian(data->player_dir);
	inv_tan = -1 / tan(ray_angle);
	
	// LOOK UP
	if (ray_angle > PI)
	{
		r->ray_inter.y = floor(data->player.y / m->T_HEIGHT) * m->T_HEIGHT - 0.0001;
		r->ray_inter.x =  data->player.x + (data->player.y - r->ray_inter.y) * inv_tan;
		r->offset.y = -m->T_HEIGHT;
		r->offset.x = -r->offset.y * inv_tan;
	}
	// LOOK DOWN
	if (ray_angle < PI)
	{
		r->ray_inter.y = floor(data->player.y / m->T_HEIGHT) * m->T_HEIGHT + m->T_HEIGHT;
		r->ray_inter.x = data->player.x + (data->player.y - r->ray_inter.y) * inv_tan;
		r->offset.y = m->T_HEIGHT;
		r->offset.x = -r->offset.y * inv_tan;
	}
	// LOOK LEFT OR RIGHT
	if (ray_angle == 0 || ray_angle == PI)
	{
		r->ray_inter.y = data->player.y;
		r->ray_inter.x = data->player.x;
	}
	
	// printf("r->ray_inter.y = %f | r->ray_inter.x = %f\n", r->ray_inter.y, r->ray_inter.x);
	draw_line(data->mlx, data->player, r->ray_inter, HRED);
}
