/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:53:53 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/17 18:34:38 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_game(t_mlx *mlx, int exit_code)
{
	printf("%s\n", __func__);
	free_title_screen(&s_game()->title_screen);
	printf("5\n");
	if (s_data() != NULL)
		free_data(s_data());
	printf("1\n");
	if (s_game() != NULL)
		free_game(s_game());
	printf("2\n");
	// yama(CLEAN_ALL, NULL, 0);
	printf("3\n");
	free_mlx(mlx);
	printf("4\n");
	exit(exit_code);
}

// void	clean_exit(int exit_code)
// {
// 	free_title_screen(&s_game()->title_screen);
// 	if (s_data() != NULL)
// 		free_data(s_data());
// 	if (s_game() != NULL)
// 		free_game(s_game());
// 	yama(CLEAN_ALL, NULL, 0);
// 	free_mlx(s_mlx());
// 	exit(exit_code);
// }
