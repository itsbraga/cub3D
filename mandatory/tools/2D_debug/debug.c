/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:12:11 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/26 22:05:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static void	__draw_tile(t_data *data, t_point tile)
{
	t_point	pixel;
	size_t	x_end;
	size_t	y_end;

	pixel.x = tile.x * TILE_SIZE;
	pixel.y = tile.y * TILE_SIZE;
	x_end = pixel.x + TILE_SIZE;
	y_end = pixel.y + TILE_SIZE;
	while (pixel.y < y_end)
	{
		pixel.x = tile.x * TILE_SIZE;
		while (pixel.x < x_end)
		{
			my_pixel_put(data->mlx, WHITE_PIX, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

static void	__draw_map2d(t_data *data, t_map *m)
{
	t_point	tile;
	
	get_map_info(m);
	tile.y = 0;
	while (tile.y < m->M_HEIGHT)
	{
		tile.x = 0;
		while (tile.x < m->M_WIDTH)
		{
			if (m->map2d[(int)tile.y][(int)tile.x] == '1')
				__draw_tile(data, tile);
			tile.x++;
		}
		tile.y++;
	}
}

static void	__raycasting_2d(t_data *data, t_ray *r)
{
	unsigned int	ray_drawed;
	t_point			closest_inter;
	float			ray_angle;

	ray_drawed = 0;
	ray_angle = norm_angle(r->player_rad - (get_radian(r->fov) / 2));
	while (ray_drawed < r->ray_amount)
	{
		intersection_horizontal_line(data, r, ray_angle);
		intersection_vertical_line(data, r, ray_angle);
		find_closest_intersection(data, r, &closest_inter);
		draw_line_2d(mlx_s(), data->player, closest_inter, RED_PIX);
		ray_angle += (get_radian(r->fov) / WIN_WIDTH);
		ray_angle = norm_angle(ray_angle);
		ray_drawed++;
	}
}

int	render_2d(t_data *data)
{
	t_mlx	*mlx;
	
	mlx = mlx_s();
	clear_window(mlx, WIN_WIDTH, WIN_HEIGHT, RUSS_PURPLE_PIX);
	__draw_map2d(data, data->map);
	draw_grid(mlx);
	draw_player(mlx, data, data->player);
	__raycasting_2d(data, data->ray);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr,
		0, 0);
	return (SUCCESS);
}
