/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/07 20:23:10 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_game	*game;
	t_mlx	*mlx;

	if (argc != 2)
	{
		err_msg(NULL, strerror(EINVAL));
		exit(FAILURE);
	}
	data = data_s();
	game = game_s();
	mlx = mlx_s();
	init_structs(game, mlx);
	if (parsing(data, argv[1]) != SUCCESS)
	{
		ft_printf(STDERR_FILENO, ERR);
		clean_exit(FAILURE);
	}
	set_hooks(mlx, game);
	mlx_loop_hook(mlx->mlx_ptr, &render, game);
	mlx_loop(mlx->mlx_ptr);
}
