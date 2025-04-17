/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:09:30 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/17 18:57:31 by pmateo           ###   ########.fr       */
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
		free_and_set_null((void **)&map->path_to_file);
	free_and_set_null((void **)&map);
}

void	free_textures(t_textures *tex)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tex->imgs[i].img_ptr != NULL)
			mlx_destroy_image(s_mlx()->mlx_ptr, tex->imgs[i].img_ptr);
		if (tex->path[i] != NULL)
			free_and_set_null((void **)&tex->path[i]);
		i++;
	}
	free_and_set_null((void **)&tex->imgs);
	free_and_set_null((void **)&tex->path);
	free_and_set_null((void **)&tex);
}

void	free_bonus_textures(t_textures *tex)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (tex->imgs[i].img_ptr != NULL)
			mlx_destroy_image(s_mlx()->mlx_ptr, tex->imgs[i].img_ptr);
		if (tex->path[i] != NULL)
			free_and_set_null((void **)&tex->path[i]);
		i++;
	}
	free_and_set_null((void **)&tex->imgs);
	free_and_set_null((void **)&tex->path);
	free_and_set_null((void **)&tex);
}

void	free_weapon(t_weapon *w)
{
	int	i;

	i = 0;
	while (i < w->xpm_count)
   {
		free_and_set_null((void **)&w->sprites.path[i]);
		mlx_destroy_image(s_mlx()->mlx_ptr, w->sprites.imgs[i].img_ptr);
		i++;
    }
    free_and_set_null((void **)&w->sprites.path);
    free(w->sprites.imgs); // Libérer le tableau des images
    free_and_set_null((void **)&w->name);
    free_and_set_null((void **)&w);
}
