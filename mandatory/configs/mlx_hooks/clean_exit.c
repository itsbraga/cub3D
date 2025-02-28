/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:37:38 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/27 21:38:16 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	del_win(t_mlx *mlx)
{
	ft_printf(STDERR_FILENO, BOLD YELLOW DEL_WIN RESET);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	// free_and_set_null((void **)mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	mlx->mlx_ptr = NULL;
	exit(FAILURE);
}

void	del_img(t_mlx *mlx)
{
	ft_printf(STDERR_FILENO, BOLD YELLOW DEL_IMG RESET);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	// free_and_set_null((void **)mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	mlx->mlx_ptr = NULL;
	exit(FAILURE);
}

int	exit_game(t_mlx *mlx, int err_status)
{
	ft_printf(STDERR_FILENO, BOLD YELLOW EXIT_PROG RESET);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	// free_and_set_null((void **)mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	mlx->mlx_ptr = NULL;
	// clean_structs(err_status);
	exit(err_status);
}
