/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u4s2e0r <u4s2e0r@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:39:53 by u4s2e0r           #+#    #+#             */
/*   Updated: 2024/12/18 17:10:35 by u4s2e0r          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void    __free_mlx(t_mlx *mlx_ptr)
{
    
}

static void    __free_data(t_data *data_ptr)
{
    
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
}