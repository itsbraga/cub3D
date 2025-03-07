/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_xpm_from_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/07 16:55:13 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	img_from_xpm(char *relative_path)
{
	t_img	img;

	ft_memset(&img, 0, sizeof(t_img));
	img.img_ptr = mlx_xpm_file_to_image(mlx_s()->mlx_ptr, relative_path,
			&img.width,
			&img.height);
	if (img.img_ptr == NULL)
	{
		err_msg("minilibX", ERR_XPM);
		return (img);
	}
	img.addr = mlx_get_data_addr(img.img_ptr,
			&img.bits_per_pixel,
			&img.size_line,
			&img.endian);
	if (img.addr == NULL)
	{
		err_msg("minilibX", ERR_ADDR);
		del_img(mlx_s(), img.img_ptr);
		ft_memset(&img, 0, sizeof(t_img));
	}
	return (img);
}
