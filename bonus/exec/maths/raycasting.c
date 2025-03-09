/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:48:06 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/08 14:59:36 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	intersection_h_line(t_player *player, t_raycasting *r, float ray_rad)
{
	float	inv_tan;
	t_point	curr_tile;
	
	if (tan(ray_rad) != 0)
		inv_tan = -1 / tan(ray_rad);
	else
		inv_tan = 0;
	if (fabs(ray_rad - PI2) < EPS || fabs(ray_rad - PI3) < EPS)
	{
		r->h_ray_inter.x = player->pos.x;
		r->h_ray_inter.y = player->pos.y;
		return ;
	}
	else if (ray_rad > PI)
	{
		r->h_ray_inter.y = floor(player->pos.y / TILE_SIZE) * TILE_SIZE - 0.0001;
		r->h_ray_inter.x =  player->pos.x + (player->pos.y - r->h_ray_inter.y)
				* inv_tan;
		r->h_offset.y = -TILE_SIZE;
		r->h_offset.x = -(r->h_offset.y) * inv_tan;
		// printf("1\n");
	}
	else if (ray_rad < PI)
	{
		r->h_ray_inter.y = floor(player->pos.y / TILE_SIZE) * TILE_SIZE
				+ TILE_SIZE;
		r->h_ray_inter.x = player->pos.x + (player->pos.y - r->h_ray_inter.y)
				* inv_tan;
		r->h_offset.y = TILE_SIZE;
		r->h_offset.x = -r->h_offset.y * inv_tan;
		// printf("2\n");
	}
	while (true)
	{
		curr_tile.x = r->h_ray_inter.x / TILE_SIZE;
		curr_tile.y = r->h_ray_inter.y / TILE_SIZE;
		if ((int)curr_tile.x < 0 || (size_t)curr_tile.x >= data_s()->map->width
			|| (int)curr_tile.y < 0 || (size_t)curr_tile.y >= data_s()->map->height)
    	{
        	// printf(BOLD RED "Out of bounds: curr_tile.x = %d, curr_tile.y = %d\n" RESET, (int)curr_tile.x, (int)curr_tile.y);
        	break;
    	}
		else if (data_s()->map->map2d[(int)curr_tile.y][(int)curr_tile.x] == '1')
		{
			// printf("HIT A WALL !\n");
			break;
		}
		else
		{
			// printf("offset.x = %f | offset.y = %f\n", r->h_offset.x, r->h_offset.y);
			r->h_ray_inter.x += r->h_offset.x;
			r->h_ray_inter.y += r->h_offset.y;
		}
	}
}

void	intersection_v_line(t_player *player, t_raycasting *r, float ray_rad)
{
	float	neg_tan;
	t_point	curr_tile;
	
	// printf("%s\n", __func__);
	neg_tan = -tan(ray_rad);
	if (fabs(ray_rad - PI) < EPS || fabs(ray_rad) < EPS)
	{
		r->v_ray_inter.x = player->pos.x;
		r->v_ray_inter.y = player->pos.y;
		return ;
	}
	else if (ray_rad > PI2 && ray_rad < PI3)
	{
		r->v_ray_inter.x = floor(player->pos.x / TILE_SIZE) * TILE_SIZE - 0.0001;
		r->v_ray_inter.y = player->pos.y + (player->pos.x - r->v_ray_inter.x) 
				* neg_tan;
		r->v_offset.x = -TILE_SIZE;
		r->v_offset.y = -r->v_offset.x * neg_tan;
		// printf("4\n");
	}
	else if (ray_rad < PI2 || ray_rad > PI3)
	{
		r->v_ray_inter.x = floor(player->pos.x / TILE_SIZE) * TILE_SIZE
				+ TILE_SIZE;
		r->v_ray_inter.y = player->pos.y + (player->pos.x - r->v_ray_inter.x) 
				* neg_tan;
		r->v_offset.x = TILE_SIZE;
		r->v_offset.y = -r->v_offset.x * neg_tan;
		// printf("5\n");

	}
	while (true)
	{
		curr_tile.x = r->v_ray_inter.x / TILE_SIZE;
		curr_tile.y = r->v_ray_inter.y / TILE_SIZE;
		if ((int)curr_tile.x < 0 || (size_t)curr_tile.x >= data_s()->map->width
			|| (int)curr_tile.y < 0 || (size_t)curr_tile.y >= data_s()->map->height)
    	{
        	// printf(BOLD RED "Out of bounds: curr_tile.x = %d, curr_tile.y = %d\n" RESET, (int)curr_tile.x, (int)curr_tile.y);
        	break;
    	}
		else if (data_s()->map->map2d[(int)curr_tile.y][(int)curr_tile.x] == '1')
		{
			// printf("HIT A WALL\n");
			break;
		}
		else
		{
			// printf("offset.x = %f | offset.y = %f\n", r->v_offset.x, r->v_offset.y);
			r->v_ray_inter.x += r->v_offset.x;
			r->v_ray_inter.y += r->v_offset.y;
		}
	}
}

void	find_closest_intersection(t_player *player, t_raycasting *r,
t_point *closest_inter)
{
	float	delta_xh;
	float	delta_yh;
	float	delta_xv;
	float	delta_yv;
	float	dist_h;
	float	dist_v;

	delta_xh = r->h_ray_inter.x - player->pos.x;
	delta_yh = r->h_ray_inter.y - player->pos.y;
	delta_xv = r->v_ray_inter.x - player->pos.x;
	delta_yv = r->v_ray_inter.y - player->pos.y;
	dist_h = (delta_xh * delta_xh) + (delta_yh * delta_yh);
	dist_v = (delta_xv * delta_xv) + (delta_yv * delta_yv);
	if (dist_h < dist_v)
	{
		closest_inter->x = r->h_ray_inter.x;
		closest_inter->y = r->h_ray_inter.y;
		r->dist_wall = sqrt(dist_h);
	}
	else
	{
		closest_inter->x = r->v_ray_inter.x;
		closest_inter->y = r->v_ray_inter.y;
		r->dist_wall = sqrt(dist_v);
	}
}

void	draw_wall(t_raycasting *r, float ray_angle, unsigned int curr_x)
{
	float	wall_h;
	t_point	start;
	t_point	end;
	float	fixed_angle;

	// Correction du fisheye
	fixed_angle = r->player_rad - ray_angle;
	fixed_angle = norm_rad_angle(fixed_angle);
	r->dist_wall = r->dist_wall * cos(fixed_angle);
	// Calcul de la hauteur du mur
	wall_h = (TILE_SIZE * WIN_HEIGHT) / r->dist_wall;
	// printf(PG "\n--> dist_wall = %f\n--> wall_h = %f\n\n" RESET, ray->dist_wall, wall_h);
	if (wall_h > WIN_HEIGHT)
		wall_h = WIN_HEIGHT;
	start.x = (float)curr_x;
	start.y = (WIN_HEIGHT / 2) - (wall_h / 2);
	end.x = (float)curr_x;
	end.y = start.y + wall_h;
	draw_line(&mlx_s()->img, start, end, LAVENDER_PIX);
}

void	raycasting(t_game *game, t_raycasting *r)
{
	unsigned int	ray_drawed;
	t_point			closest_inter;
	float			ray_angle;

	ray_drawed = 0;
	ray_angle = norm_rad_angle(r->player_rad - (degree_to_radian(r->fov) / 2));
	while (ray_drawed < r->ray_amount)
	{
		// printf("ray_drawed rad = %d\n", ray_drawed);
		// printf("ray_angle rad = %f\n", ray_angle);
		// printf("player_pos dir = %f\n\n", r->player_rad);
		intersection_h_line(game->player, r, ray_angle);
		intersection_v_line(game->player, r, ray_angle);
		find_closest_intersection(game->player, r, &closest_inter);
		draw_wall(r, ray_angle, ray_drawed);
		ray_angle += (degree_to_radian(r->fov) / WIN_WIDTH);
		ray_angle = norm_rad_angle(ray_angle);
		ray_drawed++;
	}
}
