/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:09:30 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 19:13:06 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
// 	if (screen->second_layer.img.img_ptr != NULL)
// 		del_img(mlx_s(), screen->second_layer.img.img_ptr);
// }
