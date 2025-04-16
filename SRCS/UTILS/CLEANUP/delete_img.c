/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:37:38 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/16 01:34:30 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	del_img(t_mlx *mlx, void *img_ptr)
{
	ft_printf(STDERR_FILENO, BOLD PY DEL_IMG RESET);
	mlx_destroy_image(mlx->mlx_ptr, img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free_and_set_null((void **)&mlx->mlx_ptr);
	// free(mlx->mlx_ptr);
	// mlx->mlx_ptr = NULL;
	exit(SUCCESS);
}
