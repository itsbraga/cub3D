/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:56:25 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/11 18:57:00 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D"

static void	__clear_window(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			my_pixel_put(mlx, HBLACK, x, y);
			x++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	// t_point p0;
	// t_point p1;
	// p0.x = 600;
	// p0.y = 200;
	// p1.x = 1800; 
	// p1.y = 950;
	// draw_line(data->mlx, p0, p1, HRED);
	// my_pixel_put(data->mlx, HRED, W_WIDTH / 2, W_HEIGHT / 2);
	__clear_window(data->mlx);
	draw_map2d(data, data->map);
	draw_grid(data);
	draw_player(data, data->mlx, data->player);
	raycasting(data, data->ray);
	printf("play.pos.x = %f | play.pos.y = %f\n", data->player.x, data->player.y);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->img_ptr, 0, 0);
	return (SUCCESS);
}