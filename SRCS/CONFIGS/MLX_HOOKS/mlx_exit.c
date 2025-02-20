/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:37:38 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/20 14:31:08 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	del_win(t_mlx *mlx)
{
	ft_printf(1, BOLD YELLOW DEL_WIN RESET);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->mlx_ptr);
	mlx->mlx_ptr = NULL;
	exit(FAILURE);
}

void	del_img(t_mlx *mlx)
{
	ft_printf(1, BOLD YELLOW DEL_IMG RESET);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->mlx_ptr);
	mlx->mlx_ptr = NULL;
	exit(FAILURE);
}

int	exit_game(t_mlx *mlx)
{
	ft_printf(1, BOLD YELLOW EXIT_PROG RESET);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	mlx->mlx_ptr = NULL;
	exit(SUCCESS);
}
