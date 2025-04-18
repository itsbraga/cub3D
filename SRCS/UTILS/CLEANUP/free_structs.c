/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:09:30 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/18 17:05:23 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_title_screen(t_title_screen *screen)
{
	const char	*bg = "title screen background";
	const char	*button = "title screen start button";

	if (screen == NULL)
		return ;
	if (screen->first_layer.img_ptr != NULL)
		delete_img(s_mlx(), screen->first_layer.img_ptr, bg);
	if (screen->second_layer.img.img_ptr != NULL)
		delete_img(s_mlx(), screen->second_layer.img.img_ptr, button);
}

void	free_map(t_map *map)
{
	if (map == NULL)
		return ;
	if (map->fd > 0)
		close(map->fd);
	if (map->map2d != NULL)
		free_array(map->map2d);
	if (map->path_to_file != NULL)
		free_and_set_null((void **)&map->path_to_file);
	free_and_set_null((void **)&map);
}

void	free_textures(t_textures *tex)
{
	int	i;

	if (tex == NULL)
		return ;
	i = 0;
	while (i < 4)
	{
		if (tex->imgs != NULL && tex->imgs[i].img_ptr != NULL)
		{
			ft_printf(STDERR_FILENO, BOLD PY DEL_IMG ": texture\n" RESET);
			mlx_destroy_image(s_mlx()->mlx_ptr, tex->imgs[i].img_ptr);
			tex->imgs[i].img_ptr = NULL;
		}
		if (tex->path != NULL && tex->path[i] != NULL)
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

	if (tex == NULL)
		return ;
	i = 0;
	while (i < 7)
	{
		if (tex->imgs != NULL && tex->imgs[i].img_ptr != NULL)
		{
			ft_printf(STDERR_FILENO, BOLD PY DEL_IMG ": texture\n" RESET);
			mlx_destroy_image(s_mlx()->mlx_ptr, tex->imgs[i].img_ptr);
			tex->imgs[i].img_ptr = NULL;
		}
		if (tex->path != NULL && tex->path[i] != NULL)
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

	if (w == NULL)
		return ;
	i = 0;
	while (i < w->xpm_count)
	{
		if (w->sprites.imgs != NULL && w->sprites.imgs[i].img_ptr != NULL)
		{
			ft_printf(STDERR_FILENO, BOLD PY DEL_IMG ": weapon sprite\n" RESET);
			mlx_destroy_image(s_mlx()->mlx_ptr, w->sprites.imgs[i].img_ptr);
			w->sprites.imgs[i].img_ptr = NULL;
		}
		if (w->sprites.path != NULL && w->sprites.path[i] != NULL)
			free_and_set_null((void **)&w->sprites.path[i]);
		i++;
	}
	free_and_set_null((void **)&w->sprites.path);
	free_and_set_null((void **)&w->sprites.imgs); // Libérer le tableau d'images
	free_and_set_null((void **)&w->name);
	free_and_set_null((void **)&w);
}
