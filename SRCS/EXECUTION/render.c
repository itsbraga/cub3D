/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:09:28 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/19 22:54:42 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_pixel_put(t_mlx *mlx, int color, int x, int y)
{
	int	pixel;

	pixel = (y * mlx->line_len) + (x * 4);
	if (mlx->endian == 0)
	{
		mlx->img_buff[pixel] = (color) & 0xFF;
		mlx->img_buff[pixel + 1] = (color >> 8) & 0xFF;
		mlx->img_buff[pixel + 2] = (color >> 16) & 0xFF;
		mlx->img_buff[pixel + 3] = (color >> 24) & 0xFF;
	}
	else if (mlx->endian == 1)
	{
		mlx->img_buff[pixel] = (color >> 24);
		mlx->img_buff[pixel + 1] = (color >> 16) & 0xFF;
		mlx->img_buff[pixel + 2] = (color >> 8) & 0xFF;
		mlx->img_buff[pixel + 3] = (color) & 0xFF;
	}
}

void	clear_window(t_mlx *mlx)
{
	t_point	pixel;

	if (mlx == NULL|| mlx->img_buff == NULL)
		return ;
	pixel.y = 0;
	while (pixel.y < W_HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < W_WIDTH)
		{
			my_pixel_put(mlx, HBRUSSIAN, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
	return ;
}

int	render(t_data *data)
{
	t_mlx	*mlx;
	
	mlx = mlx_s();
	printf("Game state: %d\n", data->game->game_state);
	// t_point p0;
	// t_point p1;
	// p0.x = 600;
	// p0.y = 200;
	// p1.x = 1800; 
	// p1.y = 950;
	// draw_line(mlx, p0, p1, HRED);
	// my_pixel_put(mlx, HRED, W_WIDTH / 2, W_HEIGHT / 2);

	// if (data->game != NULL && data->game->game_state == STATE_TITLE)
	// 	draw_start_screen(mlx, data->game);
	// else
	// {
		clear_window(mlx);
		get_map_info(data->map);
		raycasting(data, data->ray);
		printf("play.pos.x = %f | play.pos.y = %f\n", data->player.x, data->player.y);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img_ptr, 0, 0);
	// }
	return (SUCCESS);
}
