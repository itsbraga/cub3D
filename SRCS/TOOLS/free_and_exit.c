/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:39:53 by u4s2e0r           #+#    #+#             */
/*   Updated: 2025/01/04 21:22:55 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	__free_mlx(t_mlx *mlx, bool full_clean)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free_and_set_null(&mlx->mlx_ptr);
	if (full_clean == true);
	// if (mlx->win_ptr != NULL)
		// free_and_set_null(&mlx->win_ptr; Doit être free ???
	
}

void	__free_data(t_data *data, bool full_clean)
{
	return ;
}

void	clean_exit(int exit_status)
{
	t_mlx   *mlx_ptr;
	t_data  *data_ptr;
	
	mlx_ptr = mlx_s();
	data_ptr = data_s(); // Il n'y a pas de singleton pour la struct data ?!
	if (mlx_ptr != NULL)
		__free_mlx(mlx_ptr, true);
	if (data_ptr != NULL)
		__free_data(data_ptr, true);
	// yama(CLEAN_ALL, NULL, 0);
	exit(exit_status);
}
