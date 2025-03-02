/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img_by_xpm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/02 18:16:39 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"
#include "cub3D.h"

t_img	generate_img(char *relative_path)
{
	t_img	img;

	ft_memset(&img, 0, sizeof(t_img));
	img.img_ptr = mlx_xpm_file_to_image(mlx_s()->mlx_ptr, relative_path,
			&img.width,
			&img.height);
	if (img.img_ptr == NULL)
	{
		err_msg("MinilibX", ERR_XPM, 0);
		return (img);
	}
	img.addr = mlx_get_data_addr(img.img_ptr,
			&img.bits_per_pixel,
			&img.line_len,
			&img.endian);
	if (img.addr == NULL)
	{
		err_msg("MinilibX", ERR_ADDR, 0);
		del_img(mlx_s());
		ft_memset(&img, 0, sizeof(t_img));
	}
	return (img);
}
