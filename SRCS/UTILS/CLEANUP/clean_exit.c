/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:53:53 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 07:04:17 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_game(t_mlx *mlx, int exit_code)
{
	free_title_screen(&s_game()->title_screen);
	if (s_data() != NULL)
		free_data(s_data());
	if (s_game() != NULL)
		free_game(s_game());
	if (s_mlx() != NULL)
		free_mlx(mlx);
	exit(exit_code);
}

