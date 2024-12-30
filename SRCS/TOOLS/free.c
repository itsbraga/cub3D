/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:39:53 by u4s2e0r           #+#    #+#             */
/*   Updated: 2024/12/30 21:41:12 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void    __free_mlx(t_mlx *mlx)
{
    mlx_destroy_window(mlx->mlxptr, mlx->winptr);
    mlx_destroy_display(mlx->mlxptr);
	free_and_set_null(&mlx->mlxptr);
	// if (mlx->winptr != NULL)
		// free_and_set_null(&mlx->winptr; Doit être free ???
	
}

static void    __free_data(t_data *data)
{
    return ;
}

void	clean_exit(int exit_status)
{
    t_mlx   *mlx_ptr;
    t_data  *data_ptr;
    
    mlx_ptr = mlx_s();
    data_ptr = data_s();
	if (mlx_ptr != NULL)
		__free_mlx(mlx_ptr, true);
    if (data != NULL)
		__free_data(data_ptr, true);
	// yama(CLEAN_ALL, NULL, 0);
	exit(exit_status);
}