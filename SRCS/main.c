/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/20 12:22:14 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_mlx	*mlx;

	(void)argv;
	if (argc != 2)
	{
		ft_printf(2, "%susage: ./cub3d < .cub map file >\n", ERR_ARGS);
		exit(FAILURE);
	}
	data = data_s();
	mlx = mlx_s();
	init_structs(data, mlx);
	// printf("%s\noffset.x = %f | offset.y = %f\n", __func__, ray.offset.x, ray.offset.y);
	// mlx_loop_hook(mlx->mlx_ptr, &render, data);
	mlx_loop_hook(mlx->mlx_ptr, &render_2d, data);
	// mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &set_keypress_flag, data);
	// mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &set_keyrelease_flag, data);
	set_hooks(mlx, data);
	mlx_loop(mlx->mlx_ptr);
}
