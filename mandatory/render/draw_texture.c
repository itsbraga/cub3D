/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:24:45 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/09 21:50:08 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void	draw_vline_texture(int x, int start_y, int end_y, int *tex_buffer)
{
	int curr_y;
	int color;
	t_img	*img;

	curr_y = start_y;
	color = 0;
	img = &mlx_s()->img;
	while (curr_y <= end_y)
	{
		color = tex_buffer[start_y * TILE_SIZE + x];
		my_pixel_put_to_img(img, color, x, curr_y);
		curr_y++;
	}
	return ; 
}