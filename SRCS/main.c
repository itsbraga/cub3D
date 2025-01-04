/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/01/04 20:44:14 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render(t_data *data)
{
	// int	pixel;
	int		x;
	int		y;
	int		color;
	int		byteperline;
	
	x = 0;
	y = 0;
	byteperline = data->mlx->line_len / 4;
	color = MRED;
	// if (data->bpp != 32)
	// 	color = mlx_get_color_value(data->mlx_ptr, color);
	// while (y < 300)
	// {
	// 	++y;
	// 	while (x < 600)
	// 	{
	// 		++x;
	// 		pixel = (y * data->img_linelen) + (x * 4);
	// 		data->img_buff[pixel] = (color) & 0xFF;
	// 		data->img_buff[pixel + 1] = (color >> 8) & 0xFF;
	// 		data->img_buff[pixel + 2] = (color >> 16) & 0xFF;
	// 		data->img_buff[pixel + 3] = (color >> 24);
	// 	}
	// 	x = 0;
	// }
	while (y < (HEIGHT / 2) - 1)
	{
		++y;
		while (x < WIDTH - 1)
		{
			++x;
			data->mlx->img_buff[(y * byteperline) + x] = color;
		}
		x = 0;
	}
	color = MWHITE;
	while (y < HEIGHT)
	{
		++y;
		while (x < WIDTH - 1)
		{
			++x;
			data->mlx->img_buff[(y * byteperline) + x] = color;
		}
		x = 0;
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->img_ptr, 0, 0);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_data	data;

	(void)argv;
	(void)argc;
	if (argc != 2)
    {
        ft_printf(2, "%susage: ./cub3d < .cub map file >\n", ERR_ARGS);
        exit(FAILURE);
    }
	init_data(&data);
	init_mlx(&mlx, &data);
	mlx_loop_hook(mlx.mlx_ptr, &render, &data);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_display(mlx.mlx_ptr);
	clean_exit(SUCCESS);
}
