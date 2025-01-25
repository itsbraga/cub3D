/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:48:06 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/25 20:08:40 by pmateo           ###   ########.fr       */
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

// Draw 3D rays
void	raycasting(t_data *data, t_map *m, t_ray *r)
{
	float			ray_angle;
	float			inv_tan;
	unsigned int	ray_amount;
	// t_point			curr_tile;

	ray_angle = get_radian(data->player_dir);
	inv_tan = -1 / tan(ray_angle);

	ray_amount = 0;
	while (ray_amount < 1)
	{
		// get_ray_info(data, m, r);
		// LOOK UP
		if (ray_angle > PI)
		{
			r->ray_inter.y = floor(data->player.y / m->T_HEIGHT) * m->T_HEIGHT - 0.0001;
			r->ray_inter.x =  data->player.x + (data->player.y - r->ray_inter.y) * inv_tan;
			if (ray_angle == 3 * PI / 2)
			{
				r->offset.x = 0;
				r->offset.y = -m->T_HEIGHT;
			}
			else
			{
				r->offset.y = -m->T_HEIGHT;
				r->offset.x = -r->offset.y * inv_tan;
				printf("ray_angle == 3 * PI / 2\n");
			}
		}
		// LOOK DOWN
		if (ray_angle < PI)
		{
			r->ray_inter.y = floor(data->player.y / m->T_HEIGHT) * m->T_HEIGHT + m->T_HEIGHT;
			r->ray_inter.x = data->player.x + (data->player.y - r->ray_inter.y) * inv_tan;
			if (ray_angle == PI / 2)
			{
				r->offset.x = 0;
				r->offset.y = m->T_HEIGHT;
				printf("ray_angle == PI / 2\n");
			}
			else
			{
				r->offset.y = m->T_HEIGHT;
				r->offset.x = -r->offset.y * inv_tan;
			}
		}
		// LOOK LEFT OR RIGHT
		if (ray_angle == 0 || ray_angle == PI)
		{
			r->ray_inter.y = data->player.y;
			r->ray_inter.x = data->player.x;
		}
		printf("KEEEEK\n");
		// while (true)
		// {
		// 	curr_tile.x = r->ray_inter.x / m->T_WIDTH;
		// 	curr_tile.y = r->ray_inter.y / m->T_HEIGHT;
		// 	printf("WTFFFF\n");
		// 	printf("curr_tile X: %d   --   curr_tile Y: %d\n", (int)curr_tile.x, (int)curr_tile.y);
		// 	if (m->map2d[(int)curr_tile.y][(int)curr_tile.x] == '1') // check if ray has hit a wall
		// 	{
		// 		printf("HIT A WALL\n");
		// 		break;
		// 	}
		// 	else // go to the next ray_inter
		// 	{
		// 		printf("OFFSET ++\n");
		// 		r->ray_inter.x += r->offset.x;
		// 		r->ray_inter.y += r->offset.y;
		// 	}
		// }
		ray_amount++;
		// printf("r->ray_inter.y = %f | r->ray_inter.x = %f\n", r->ray_inter.y, r->ray_inter.x);
		draw_line(data->mlx, data->player, r->ray_inter, HRED);	
	}
}
