/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/07 14:11:56 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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
	init_structs(data, game, mlx);
	if (parsing(data, argv[1]) == FAILURE)
	{
		// free all structs (clean_exit)
		exit(FAILURE); // then remove this line
	}
	set_hooks(mlx, game, data);
	mlx_loop_hook(mlx->mlx_ptr, &render, game);
	mlx_loop(mlx->mlx_ptr);
}
