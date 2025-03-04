/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/04 19:36:38 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_mlx	*mlx;
	t_data	*data;

	(void)argv;
	if (argc != 2)
		exit(FAILURE);
	game = game_s();
	mlx = mlx_s();
	data = data_s();
	// parsing(argv);
	get_map_data(data, argv);
	init_structs(game, mlx);
	set_hooks(mlx, game);
	mlx_loop_hook(mlx->mlx_ptr, &render, game);
	mlx_loop(mlx->mlx_ptr);
}
