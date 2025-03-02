/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:09:30 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/02 23:28:20 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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

// void	free_title_screen(t_title_screen *screen)
// {
// 	if (screen->first_layer_img.img_ptr != NULL)
// 		del_img(mlx_s(), screen->first_layer_img.img_ptr);
// 	// if (screen->second_layer.img.img_ptr != NULL)
// 	// 	del_img(mlx_s(), screen->second_layer.img.img_ptr);
// 	if (screen->third_layer.img.img_ptr != NULL)
// 		del_img(mlx_s(), screen->third_layer.img.img_ptr);
// }
