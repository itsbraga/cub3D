/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:37:38 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/17 03:37:13 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	del_img(t_mlx *mlx, void *img_ptr)
{
	ft_printf(STDERR_FILENO, BOLD PY DEL_IMG RESET);
	mlx_destroy_image(mlx->mlx_ptr, img_ptr);
	img_ptr = NULL;
}
