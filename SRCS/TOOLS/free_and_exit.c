/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:39:53 by u4s2e0r           #+#    #+#             */
/*   Updated: 2025/02/19 21:52:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static void	__free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free_and_set_null(&mlx->mlx_ptr);
	// if (full_clean == true);
	// if (mlx->win_ptr != NULL)
		// free_and_set_null(&mlx->win_ptr; Doit être free ???	
}

void	free_tab(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i] != NULL)
	{
		free_and_set_null((void **)&tab[i]);
		i++;
	}
	free_and_set_null((void **)&tab);
}

static void	__free_data(t_data *data)
{
	if (data != NULL)
	{
		if (data->map_path != NULL)
			free_and_set_null((void **)&data->map_path);
		if (data->map != NULL)
			free_tab(data->map->map2d);
		// if (data->ray != NULL)
			// ?
	}
}

void	clean_exit(int exit_status)
{
	if (mlx_s() != NULL)
		__free_mlx(mlx_s());
	if (data_s() != NULL)
		__free_data(data_s());
	// yama(CLEAN_ALL, NULL, 0);
	exit(exit_status);
}
