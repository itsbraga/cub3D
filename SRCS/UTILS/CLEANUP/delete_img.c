/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:37:38 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/18 02:44:53 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	delete_img(t_mlx *mlx, void *img_ptr, const char *name)
{
	if (name != NULL)
		ft_printf(STDERR_FILENO, BOLD PY DEL_IMG ": %s\n" RESET, name);
	else
		ft_printf(STDERR_FILENO, BOLD PY DEL_IMG "\n" RESET);
	mlx_destroy_image(mlx->mlx_ptr, img_ptr);
	img_ptr = NULL;
}
