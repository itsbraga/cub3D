/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:48:06 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/07 22:49:36 by pmateo           ###   ########.fr       */
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

void	found_closest_inter(t_data *d, t_point *closest_inter)
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
		closest_inter->x = d->ray->h_ray_inter.x;
		closest_inter->y = d->ray->h_ray_inter.y;
	}
	else
	{
		closest_inter->x = d->ray->v_ray_inter.x;
		closest_inter->y = d->ray->v_ray_inter.y;
	}
}

static	void	__inter_hline(t_data *d, t_ray *r, float ray_rad)
{
	float	inv_tan;
	t_point	curr_tile;

	
	if (tan(ray_rad) != 0)
		inv_tan = -1 / tan(ray_rad);
	else
		inv_tan = 0;
	if (fabs(ray_rad - PI2) < EPS || fabs(ray_rad - PI3) < EPS)
	{
		r->h_ray_inter.x = d->player.x;
		r->h_ray_inter.y = d->player.y;
		return;
	}
	else if (ray_rad > PI)
	{
		r->h_ray_inter.y = floor(d->player.y / TILE_SIZE) * TILE_SIZE - 0.0001;
		r->h_ray_inter.x =  d->player.x + (d->player.y - r->h_ray_inter.y) * inv_tan;
		r->h_offset.y = -TILE_SIZE;
		r->h_offset.x = -(r->h_offset.y) * inv_tan;
		printf("1\n");
	}
	else if (ray_rad < PI)
	{
		r->h_ray_inter.y = floor(d->player.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		r->h_ray_inter.x = d->player.x + (d->player.y - r->h_ray_inter.y) * inv_tan;
		r->h_offset.y = TILE_SIZE;
		r->h_offset.x = -r->h_offset.y * inv_tan;
		printf("2\n");
	}
	while (1)
	{
		curr_tile.x = r->h_ray_inter.x / TILE_SIZE;
		curr_tile.y = r->h_ray_inter.y / TILE_SIZE;
		if ((int)curr_tile.x < 0 || (size_t)curr_tile.x >= d->map->M_WIDTH ||
        (int)curr_tile.y < 0 || (size_t)curr_tile.y >= d->map->M_HEIGHT)
    	{
        	printf("Out of bounds: curr_tile.x = %d, curr_tile.y = %d\n", (int)curr_tile.x, (int)curr_tile.y);
        	break;
    	}
		if (d->map->map2d[(int)curr_tile.y][(int)curr_tile.x] == '1')
		{
			printf("HIT A WALL !");
			break;
		}
		else
		{
			// printf("OFFSET ++\n");
			// printf("offset.x = %f | offset.y = %f\n", r->h_offset.x, r->h_offset.y);
			r->h_ray_inter.x += r->h_offset.x;
			r->h_ray_inter.y += r->h_offset.y;
		}
	}
	
}

static	void	__inter_vline(t_data *d, t_ray *r, float ray_rad)
{
	float	neg_tan;
	t_point	curr_tile;
	
	printf("%s\n", __func__);
	neg_tan = -tan(ray_rad);
	if (fabs(ray_rad - PI) < EPS || fabs(ray_rad) < EPS)
	{
		r->v_ray_inter.x = d->player.x;
		r->v_ray_inter.y = d->player.y;
		return;
	}
	else if (ray_rad > PI2 && ray_rad < PI3)
	{
		r->v_ray_inter.x = floor(d->player.x / TILE_SIZE) * TILE_SIZE - 0.0001;
		r->v_ray_inter.y = d->player.y + (d->player.x - r->v_ray_inter.x) * neg_tan;
		r->v_offset.x = -TILE_SIZE;
		r->v_offset.y = -r->v_offset.x * neg_tan;
		printf("4\n");
	}
	else if (ray_rad < PI2 || ray_rad > PI3)
	{
		r->v_ray_inter.x = floor(d->player.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		r->v_ray_inter.y = d->player.y + (d->player.x - r->v_ray_inter.x) * neg_tan;
		r->v_offset.x = TILE_SIZE;
		r->v_offset.y = -r->v_offset.x * neg_tan;
		printf("5\n");

	}
	while (1)
	{
		curr_tile.x = r->v_ray_inter.x / TILE_SIZE;
		curr_tile.y = r->v_ray_inter.y / TILE_SIZE;
		if ((int)curr_tile.x < 0 || (size_t)curr_tile.x >= d->map->M_WIDTH ||
        (int)curr_tile.y < 0 || (size_t)curr_tile.y >= d->map->M_HEIGHT)
    	{
        	printf("Out of bounds: curr_tile.x = %d, curr_tile.y = %d\n", (int)curr_tile.x, (int)curr_tile.y);
        	break;
    	}
		if (d->map->map2d[(int)curr_tile.y][(int)curr_tile.x] == '1')
		{
			printf("HIT A WALL\n");
			break;
		}
		else
		{
			// printf("OFFSET ++\n");
			// printf("offset.x = %f | offset.y = %f\n", r->v_offset.x, r->v_offset.y);
			r->v_ray_inter.x += r->v_offset.x;
			r->v_ray_inter.y += r->v_offset.y;
		}
	}
}

void	raycasting(t_data *data, t_ray *r)
{
	unsigned int	ray_drawed;
	t_point			closest_inter;
	float			ray_angle;

	ray_drawed = 0;
	ray_angle = normalize_rad(r->player_rad - (get_radian(r->fov) / 2));
	while (ray_drawed < r->ray_amount)
	{
		printf("ray rad = %d\n", ray_drawed);
		printf("ray rad = %f\n", ray_angle);
		printf("player dir = %f\n", r->player_rad);
		__inter_hline(data, r, ray_angle);
		__inter_vline(data, r, ray_angle);
		found_closest_inter(data, &closest_inter);
		draw_line(data->mlx, data->player, closest_inter, HRED);
		ray_drawed++;
		ray_angle += (get_radian(r->fov) / W_WIDTH);
		ray_angle = normalize_rad(ray_angle);
	}
}
