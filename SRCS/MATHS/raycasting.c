/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:48:06 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/28 21:44:21 by pmateo           ###   ########.fr       */
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
// 		r->ray_inter.y = floor(data->player.y / m->T_HEIGHT) * m->T_HEIGHT - 0.0001;
// 		r->ray_inter.x =  data->player.x + (data->player.y - r->ray_inter.y) * inv_tan;
// 		r->offset.y = -m->T_HEIGHT;
// 		r->offset.x = -r->offset.y * inv_tan;
// 	}
// 	// LOOK DOWN
// 	if (ray_angle < PI)
// 	{
// 		r->ray_inter.y = floor(data->player.y / m->T_HEIGHT) * m->T_HEIGHT + m->T_HEIGHT;
// 		r->ray_inter.x = data->player.x + (data->player.y - r->ray_inter.y) * inv_tan;
// 		r->offset.y = m->T_HEIGHT;
// 		r->offset.x = -r->offset.y * inv_tan;
// 	}
// 	// LOOK LEFT OR RIGHT
// 	if (ray_angle == 0 || ray_angle == PI)
// 	{
// 		r->ray_inter.y = data->player.y;
// 		r->ray_inter.x = data->player.x;
// 	}
// }

static	void	__inter_hline(t_data *d, t_ray *r, t_map *m)
{
	float	inv_tan;
	
	inv_tan = -1 / tan(r->rad);
	if (r->rad > PI)
	{
		r->ray_inter.y = floor(d->player.y / m->T_HEIGHT) * m->T_HEIGHT - 0.0001;
		r->ray_inter.x =  d->player.x + (d->player.y - r->ray_inter.y) * inv_tan;
		r->offset.y = -m->T_HEIGHT;
		r->offset.x = -(r->offset.y) * inv_tan;
		printf("1\n");
	}
	else if (r->rad < PI)
	{
		r->ray_inter.y = floor(d->player.y / m->T_HEIGHT) * m->T_HEIGHT + m->T_HEIGHT;
		r->ray_inter.x = d->player.x + (d->player.y - r->ray_inter.y) * inv_tan;
		r->offset.y = m->T_HEIGHT;
		r->offset.x = -r->offset.y * inv_tan;
		printf("2\n");
	}
	else if (r->rad == PI || r->rad == 0)
	{
		r->ray_inter.x = d->player.x;
		r->ray_inter.y = d->player.y;
		printf("3\n");
	}
}

static	void	__inter_vline(t_data *d, t_ray *r, t_map *m)
{
	float	neg_tan;
	
	neg_tan = -tan(r->rad);
	if (r->rad > (PI / 2) && r->rad < (3 * PI / 2))
	{
		r->ray_inter.x = floor(d->player.x / m->T_WIDTH) * m->T_WIDTH - 0.0001;
		r->ray_inter.y = d->player.y + (d->player.x - r->ray_inter.x) * neg_tan;
		r->offset.x = -m->T_WIDTH;
		r->offset.y = -r->offset.x * neg_tan;
		printf("4\n");
	}
	else if (r->rad < (PI / 2) || r->rad > (3 * PI / 2))
	{
		r->ray_inter.x = floor(d->player.x / m->T_WIDTH) * m->T_WIDTH + m->T_WIDTH;
		r->ray_inter.y = d->player.y + (d->player.x - r->ray_inter.x) * neg_tan;
		r->offset.x = m->T_WIDTH;
		r->offset.y = -r->offset.x * neg_tan;
		printf("5\n");

	}
	else if (r->rad == PI || r->rad == 0)
	{
		r->ray_inter.x = d->player.x;
		r->ray_inter.y = d->player.y;
		printf("6\n");
	}
}

// Draw 3D rays
void	raycasting(t_data *data, t_map *m, t_ray *r)
{
	unsigned int	ray_drawed;
	// t_point			curr_tile;

	ray_drawed = 0;
	while (ray_drawed < r->ray_amount)
	{
		__inter_hline(data, r, m);
		__inter_vline(data, r, m);
		// while (true)
		// {
		// 	curr_tile.x = r->ray_inter.x / m->T_WIDTH;
		// 	curr_tile.y = r->ray_inter.y / m->T_HEIGHT;
		// 	printf("curr_tile X: %d   --   curr_tile Y: %d\n", (int)curr_tile.x, (int)curr_tile.y);
		// 	if (m->map2d[(int)curr_tile.y][(int)curr_tile.x] == '1') // check if ray has hit a wall
		// 	{
		// 		printf("HIT A WALL\n");
		// 		break;
		// 	}
		// 	else // go to the next ray_inter
		// 	{
		// 		printf("OFFSET ++\n");
		// 		printf("offset.x = %f | offset.y = %f\n", r->offset.x, r->offset.y);
		// 		r->ray_inter.x += r->offset.x;
		// 		r->ray_inter.y += r->offset.y;
		// 	}
		// }
		ray_drawed++;
		draw_line(data->mlx, data->player, r->ray_inter, HRED);	
	}
}
