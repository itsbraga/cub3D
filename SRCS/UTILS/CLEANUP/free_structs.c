/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:09:30 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/10 15:21:55 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_title_screen(t_title_screen *screen)
{
	if (screen->first_layer.img_ptr != NULL)
		del_img(s_mlx(), screen->first_layer.img_ptr);
	if (screen->second_layer.img.img_ptr != NULL)
		del_img(s_mlx(), screen->second_layer.img.img_ptr);
}

void	free_map(t_map *map)
{
	if (map->map2d != NULL)
		free_array(map->map2d);
	if (map->path_to_file != NULL)
		my_free((void **)map->path_to_file);
}

void	free_weapons(t_weapon *w)
{
	int	i;

	i = 0;
	while (i < w->xpm_count)
   {
		free(w->sprites.path[i]);
		i++;
    }
    free(w->sprites.path);
    // free(w->sprites.imgs); // Libérer le tableau des images
    free(w->name);
    free(w);
}
