/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/25 00:52:57 by pmateo           ###   ########.fr       */
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
	// mlx_loop_hook(mlx->mlx_ptr, &render_2d, data);
	mlx_loop_hook(mlx->mlx_ptr, &render_minimap, data);
	// mlx_loop_hook(mlx->mlx_ptr, &render, data);
	set_hooks(mlx, data);
	mlx_loop(mlx->mlx_ptr);
}
