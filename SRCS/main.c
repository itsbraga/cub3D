/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/14 21:48:33 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_data	*data;

	(void)argv;
	if (argc != 2)
    {
        ft_printf(2, "%susage: ./cub3d < .cub map file >\n", ERR_ARGS);
        exit(FAILURE);
    }
	mlx = mlx_s();
	data = data_s();
	init_data(data);
	init_mlx(mlx, data);
	init_map(data->map, data);
	init_ray(data, data->ray);
	// printf("%s\noffset.x = %f | offset.y = %f\n", __func__, ray.offset.x, ray.offset.y);
	mlx_loop_hook(mlx->mlx_ptr, &render, data);
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &set_keypress_flag, data);
	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	clean_exit(SUCCESS);
}
