/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:48:06 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/31 04:56:57 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	get_ray_info(t_data *data, t_map *m, t_ray *r)
// {
// 	float	ray_angle;
// 	float	inv_tan;

// 	ray_angle = get_radian(data->player_dir);
// 	inv_tan = -1 / tan(ray_angle);

// 	// LOOK UP
// 	if (ray_angle > PI)
// 	{
// 		r->ray_inter.y = floor(data->player.y / TILE_SIZE) * TILE_SIZE - 0.0001;
// 		r->ray_inter.x =  data->player.x + (data->player.y - r->ray_inter.y) * inv_tan;
// 		r->offset.y = -TILE_SIZE;
// 		r->offset.x = -r->offset.y * inv_tan;
// 	}
// 	// LOOK DOWN
// 	if (ray_angle < PI)
// 	{
// 		r->ray_inter.y = floor(data->player.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
// 		r->ray_inter.x = data->player.x + (data->player.y - r->ray_inter.y) * inv_tan;
// 		r->offset.y = TILE_SIZE;
// 		r->offset.x = -r->offset.y * inv_tan;
// 	}
// 	// LOOK LEFT OR RIGHT
// 	if (ray_angle == 0 || ray_angle == PI)
// 	{
// 		r->ray_inter.y = data->player.y;
// 		r->ray_inter.x = data->player.x;
// 	}
// }

void	found_closest_inter(t_data *d, t_point *to_set_inter, t_point *to_set_offset)
{
	float	delta_xh;
	float	delta_yh;
	float	delta_xv;
	float	delta_yv;
	float	dist_h;
	float	dist_v;

	delta_xh = d->ray->h_ray_inter.x - d->player.x;
	delta_yh = d->ray->h_ray_inter.y - d->player.y;
	delta_xv = d->ray->v_ray_inter.x - d->player.x;
	delta_yv = d->ray->v_ray_inter.y - d->player.y;
	dist_h = (delta_xh * delta_xh) + (delta_yh * delta_yh);
	dist_v = (delta_xv * delta_xv) + (delta_yv * delta_yv);
	if (dist_h < dist_v)
	{
		to_set_inter->x = d->ray->h_ray_inter.x;
		to_set_inter->y = d->ray->h_ray_inter.y;
		to_set_offset->x = d->ray->h_offset.x;
		to_set_offset->y = d->ray->h_offset.y;
	}
	else
	{
		to_set_inter->x = d->ray->v_ray_inter.x;
		to_set_inter->y = d->ray->v_ray_inter.y;
		to_set_offset->x = d->ray->v_offset.x;
		to_set_offset->y = d->ray->v_offset.y;
	}

}

static	void	__inter_hline(t_data *d, t_ray *r)
{
	float	inv_tan;
	
	inv_tan = -1 / tan(r->rad);
	if (r->rad > PI)
	{
		r->h_ray_inter.y = floor(d->player.y / TILE_SIZE) * TILE_SIZE - 0.0001;
		r->h_ray_inter.x =  d->player.x + (d->player.y - r->h_ray_inter.y) * inv_tan;
		r->h_offset.y = -TILE_SIZE;
		r->h_offset.x = -(r->h_offset.y) * inv_tan;
		printf("1\n");
	}
	else if (r->rad < PI)
	{
		r->h_ray_inter.y = floor(d->player.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		r->h_ray_inter.x = d->player.x + (d->player.y - r->h_ray_inter.y) * inv_tan;
		r->h_offset.y = TILE_SIZE;
		r->h_offset.x = -r->h_offset.y * inv_tan;
		printf("2\n");
	}
	else if (r->rad == PI || r->rad == 0)
	{
		r->h_ray_inter.x = d->player.x;
		r->h_ray_inter.y = d->player.y;
		printf("3\n");
	}
}

static	void	__inter_vline(t_data *d, t_ray *r)
{
	float	neg_tan;
	
	neg_tan = -tan(r->rad);
	if (r->rad > (PI / 2) && r->rad < (3 * PI / 2))
	{
		r->v_ray_inter.x = floor(d->player.x / TILE_SIZE) * TILE_SIZE - 0.0001;
		r->v_ray_inter.y = d->player.y + (d->player.x - r->v_ray_inter.x) * neg_tan;
		r->v_offset.x = -TILE_SIZE;
		r->v_offset.y = -r->v_offset.x * neg_tan;
		printf("4\n");
	}
	else if (r->rad < (PI / 2) || r->rad > (3 * PI / 2))
	{
		r->v_ray_inter.x = floor(d->player.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		r->v_ray_inter.y = d->player.y + (d->player.x - r->v_ray_inter.x) * neg_tan;
		r->v_offset.x = TILE_SIZE;
		r->v_offset.y = -r->v_offset.x * neg_tan;
		printf("5\n");

	}
	else if (r->rad == PI || r->rad == 0)
	{
		r->v_ray_inter.x = d->player.x;
		r->v_ray_inter.y = d->player.y;
		printf("6\n");
	}
}

// Draw 3D rays
void	raycasting(t_data *data, t_map *m, t_ray *r)
{
	unsigned int	ray_drawed;
	t_point			curr_tile;
	t_point			closest_inter;
	t_point			next_offset;

	ray_drawed = 0;
	while (ray_drawed < r->ray_amount)
	{
		printf("ray rad = %f\n", r->rad);
		__inter_hline(data, r);
		printf("## AFTER HLINE ##\n inter.x = %f | inter.y = %f\n", closest_inter.x, closest_inter.y);
		printf("offset.x = %f | offset.y = %f\n\n", next_offset.x, next_offset.y);
		__inter_vline(data, r);
		found_closest_inter(data, &closest_inter, &next_offset);
		printf("## AFTER VLINE ##\n inter.x = %f | inter.y = %f\n", closest_inter.x, closest_inter.y);
		printf("offset.x = %f | offset.y = %f\n\n", next_offset.x, next_offset.y);
		while (true)
		{
			curr_tile.x = closest_inter.x / TILE_SIZE;
			curr_tile.y = closest_inter.y / TILE_SIZE;
			printf("curr_tile X: %d   --   curr_tile Y: %d\n", (int)curr_tile.x, (int)curr_tile.y);
			if (m->map2d[(int)curr_tile.y][(int)curr_tile.x] == '1') // check if ray has hit a wall
			{
				printf("HIT A WALL\n");
				break;
			}
			else // go to the next ray_inter
			{
				printf("OFFSET ++\n");
				printf("offset.x = %f | offset.y = %f\n", next_offset.x, next_offset.y);
				closest_inter.x += next_offset.x;
				closest_inter.y += next_offset.y;
			}
		}
		ray_drawed++;
		draw_line(data->mlx, data->player, closest_inter, HRED);	
	}
}
