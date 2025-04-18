/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 19:16:03 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_data	*data;
	t_game	*game;
	t_mlx	*mlx;

	if (argc != 2)
		return (err_msg(NULL, ERR_USAGE), FAILURE);
	fd = check_cub_file(argv[1]);
	if (fd < 0)
		return (FAILURE);
	close(fd);
	data = s_data();
	game = s_game();
	mlx = s_mlx();
	init_structs(data, game, mlx);
	if (parse_file(argv[1], data, game) == FAILURE)
		exit_game(mlx, FAILURE);
	init_doors(data);
	set_hooks(mlx, game);
	mlx_loop_hook(mlx->mlx_ptr, &render_frame, game);
	mlx_loop(mlx->mlx_ptr);
	return (SUCCESS);
}
