/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:53:53 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/19 03:09:41 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_game(t_mlx *mlx, int exit_code)
{
	t_game	*game;
	t_data	*data;

	game = s_game();
	data = s_data();
	free_title_screen(&game->title_screen);
	if (data != NULL)
		free_data(data);
	if (game != NULL)
		free_game(game);
	if (mlx != NULL)
		free_mlx(mlx);
	exit(exit_code);
}
