/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:35:26 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/24 18:34:51 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

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

void	clear_window(t_mlx *mlx, size_t size_x, size_t size_y, int color)
{
	t_point	pixel;

	if (mlx == NULL || mlx->img_buff == NULL)
		return ;
	pixel.y = 0;
	while (pixel.y < size_y)
	{
		pixel.x = 0;
		while (pixel.x < size_x)
		{
			my_pixel_put(mlx, color, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
	return ;
}
