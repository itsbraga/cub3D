/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:11:33 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/13 09:15:20 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D"

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