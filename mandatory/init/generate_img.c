/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:33:51 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/28 01:50:56 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	generate_img(char *path_to_file)
{
	t_img	img;

	img.img_ptr = mlx_xpm_file_to_image(mlx_s()->mlx_ptr, path_to_file,
			&img.width, &img.height);
	if (img.img_ptr == NULL)
	{
		err_msg("MLX", ERR_MLX, 0); // specifier erreur
		del_img(mlx_s()); // a verifier
	}
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp,
			&img.line_len, &img.endian);
	if (img.addr == NULL)
	{
		err_msg("MLX", ERR_MLX, 0); // specifier erreur
		exit_game(mlx_s(), FAILURE); // a verifier
	}
	return (img);
}
