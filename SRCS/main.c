/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/01/14 17:23:38 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render(t_data *data)
{
	// t_point p0;
	// t_point p1;
	// p0.x = 600;
	// p0.y = 200;
	// p1.x = 1800; 
	// p1.y = 950;
	// draw_line(data->mlx, p0, p1, HRED);
	// my_pixel_put(data->mlx, HRED, WIDTH / 2, HEIGHT / 2);
	draw_player(data->mlx, data->player);
	printf("couuuuuucouuuuu\n");
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
