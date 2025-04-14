/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:53:53 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/15 00:32:55 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_game(t_mlx *mlx, int exit_code)
{
	free_mlx(mlx);
	exit(exit_code);
}

void	clean_exit(int exit_code)
{
	free_title_screen(&s_game()->title_screen);
	// if (s_data() != NULL)
	// 	free_data(s_data());
	if (s_game() != NULL)
		free_game(s_game());
	yama(CLEAN_ALL, NULL, 0);
	exit_game(s_mlx(), exit_code);
}
