/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/06 18:50:39 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_game	*game;
	t_mlx	*mlx;

	(void)argv;
	if (argc != 2)
	{
		err_msg(NULL, strerror(EINVAL));
		exit(FAILURE);
	}
	data = data_s();
	game = game_s();
	mlx = mlx_s();
	// parsing(argv);
	get_map_data(data, argv);
	init_structs(data, game, mlx);
	set_hooks(mlx, game);
	mlx_loop_hook(mlx->mlx_ptr, &render, game);
	mlx_loop(mlx->mlx_ptr);
}
