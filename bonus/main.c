/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/01 18:06:45 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_mlx	*mlx;

	(void)argv;
	if (argc != 2)
		exit(FAILURE);
	data = data_s();
	mlx = mlx_s();
	init_structs(data, mlx);
	set_hooks(mlx, data);
	mlx_loop_hook(mlx->mlx_ptr, &render, data);
	mlx_loop(mlx->mlx_ptr);
}
