/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:09:30 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/03 20:15:05 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	free_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free_and_set_null((void **)&array[i]);
		i++;
	}
	free_and_set_null((void **)&array);
}

// void	free_title_screen(t_title_screen *screen)
// {
// 	if (screen->first_layer_img.img_ptr != NULL)
// 		del_img(mlx_s(), screen->first_layer_img.img_ptr);
// 	// if (screen->second_layer.img.img_ptr != NULL)
// 	// 	del_img(mlx_s(), screen->second_layer.img.img_ptr);
// 	if (screen->third_layer.img.img_ptr != NULL)
// 		del_img(mlx_s(), screen->third_layer.img.img_ptr);
// }
