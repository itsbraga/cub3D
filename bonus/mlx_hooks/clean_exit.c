/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:37:38 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 19:33:31 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	del_window(t_mlx *mlx)
{
	ft_printf(STDERR_FILENO, BOLD YELLOW DEL_WIN RESET);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	// free_and_set_null((void **)mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	mlx->mlx_ptr = NULL;
	exit(FAILURE);
}

void	del_img(t_mlx *mlx, void *img_ptr)
{
	ft_printf(STDERR_FILENO, BOLD YELLOW DEL_IMG RESET);
	mlx_destroy_image(mlx->mlx_ptr, img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	// free_and_set_null((void **)mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	mlx->mlx_ptr = NULL;
	exit(FAILURE);
}

// int	clean_exit(t_mlx *mlx, void *img_ptr, int err_status)
// {
// 	ft_printf(STDERR_FILENO, BOLD YELLOW EXIT_PROG RESET);
// 	if (img_ptr != NULL)
// 		mlx_destroy_image(mlx->mlx_ptr, img_ptr);
// 	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
// 	mlx_destroy_display(mlx->mlx_ptr);
// 	// free_and_set_null((void **)mlx->mlx_ptr);
// 	free(mlx->mlx_ptr);
// 	mlx->mlx_ptr = NULL;
// 	// free_singletons(err_status);
// 	exit(err_status);
// }
	
int	clean_exit(t_mlx *mlx, int err_status)
{
	ft_printf(STDERR_FILENO, BOLD YELLOW EXIT_PROG RESET);
	if (mlx->img.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	// free_and_set_null((void **)mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	mlx->mlx_ptr = NULL;
	// free_singletons(err_status);
	exit(err_status);
}
