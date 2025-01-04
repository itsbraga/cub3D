/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/12/30 21:54:57 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3D.h"

void	init_mlx(t_mlx *mlx, t_data *data)
{
	mlx->mlxptr = mlx_init();
	if (mlx->mlxptr == NULL)
		(err_msg("MLX", ERR_MLX), clean_exit(FAILURE));
	mlx->winptr = mlx_new_window(mlx->mlxptr, WIDTH, HEIGHT, "kub");
	if (mlx->winptr == NULL)
		(err_msg("MLX", ERR_MLX), clean_exit(FAILURE));
	mlx->img = mlx_new_image(mlx->mlxptr, WIDTH, HEIGHT);
	if (mlx->img == NULL)
		(err_msg("MLX", ERR_MLX), clean_exit(FAILURE));
	mlx->imgbuf = mlx_get_data_addr(mlx->img, &mlx->img_bpp, &mlx->img_len, &mlx->img_endian);
	if (mlx->imgbuf == NULL)
		(err_msg("MLX", ERR_MLX), clean_exit(FAILURE));
	data->mlx = mlx;
}
void	init_data(t_data *data)
{
	data->map_path = NULL;
	data->map = NULL;
	ft_bzero(data->tex_path, 4);
	ft_bzero(data->f_rgb, 3);
	ft_bzero(data->c_rgb, 3);
	data->mlx = NULL;
}

int	handle_keypress(int keysm, t_data *data)
{
	if (keysm == XK_Escape)
	{
		mlx_destroy_window(data->mlx->mlxptr, data->mlx->winptr);
		data->mlx->winptr = NULL;
	}
	return (0);
}
 

int	render(t_data *data)
{
	// int	pixel;
	int		x;
	int		y;
	int		color;
	int		byteperline;
	
	x = 0;
	y = 0;
	byteperline = data->mlx->img_len / 4;
	color = RED;
	// if (data->img_bpp != 32)
	// 	color = mlx_get_color_value(data->mlx_ptr, color);
	// while (y < 300)
	// {
	// 	++y;
	// 	while (x < 600)
	// 	{
	// 		++x;
	// 		pixel = (y * data->img_linelen) + (x * 4);
	// 		data->img_buf[pixel] = (color) & 0xFF;
	// 		data->img_buf[pixel + 1] = (color >> 8) & 0xFF;
	// 		data->img_buf[pixel + 2] = (color >> 16) & 0xFF;
	// 		data->img_buf[pixel + 3] = (color >> 24);
	// 	}
	// 	x = 0;
	// }
	while (y < (HEIGHT / 2) - 1)
	{
		++y;
		while (x < WIDTH - 1)
		{
			++x;
			data->mlx->imgbuf[(y * byteperline) + x] = color;
		}
		x = 0;
	}
	color = WHITE;
	while (y < HEIGHT)
	{
		++y;
		while (x < WIDTH - 1)
		{
			++x;
			data->mlx->imgbuf[(y * byteperline) + x] = color;
		}
		x = 0;
	}
	mlx_put_image_to_window(data->mlx->mlxptr, data->mlx->winptr, data->mlx->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx mlx;
	t_data	data;

	(void)argv;
	(void)argc;
	if (argc != 2)
    {
        ft_printf(2, "%susage: ./cub3d < .cub map file >\n", ERR_BADARGS);
        exit(FAILURE);
    }
	init_data(&data);
	init_mlx(&mlx, &data);
	mlx_loop_hook(mlx.mlxptr, &render, &data);
	mlx_hook(mlx.winptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(mlx.mlxptr);
	mlx_destroy_display(mlx.mlxptr);
	clean_exit(SUCCESS);
}
