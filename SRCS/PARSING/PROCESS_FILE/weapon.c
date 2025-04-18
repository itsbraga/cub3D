/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 05:42:28 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/18 08:09:07 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**__init_tmp_paths(int max_sprites)
{
	char	**tmp_paths;

	tmp_paths = malloc(sizeof(char *) * max_sprites);
	secure_malloc(tmp_paths, true);
	ft_bzero(tmp_paths, sizeof(char *) * max_sprites);
	return (tmp_paths);
}

static int	__validate_and_load_sprites(t_weapon *w)
{
	if (check_weapon_sprites_paths(w) == FAILURE)
		return (FAILURE);
	load_and_resize_sprites(w);
	return (SUCCESS);
}

static void	__add_weapon_to_data(t_data *d, t_weapon *w)
{
	expand_weapons_array(d);
	d->weapons[d->weapon_count] = w;
	d->weapon_count++;
}

static void	__clean_failed_weapon(t_weapon *w)
{
	int	i;

	i = 0;
	if (w->sprites.path != NULL)
	{
		while (i < w->xpm_count)
		{
			if (w->sprites.path[i] != NULL)
				free_and_set_null((void **)&w->sprites.path[i]);
			i++;
		}
		free_and_set_null((void **)&w->sprites.path);
	}
	if (w->sprites.imgs != NULL)
		free_and_set_null((void **)&w->sprites.imgs);
}

int	process_weapon_sprites(int fd, t_weapon *w, t_data *d)
{
	char	**tmp_paths;
	int		sprite_count;
	bool	allocated;

	allocated = false;
	tmp_paths = __init_tmp_paths(MAX_SPRITES);
	secure_malloc(tmp_paths, true);
	sprite_count = read_sprite_paths(fd, tmp_paths, MAX_SPRITES);
	if (sprite_count <= 0)
	{
		(free_array(tmp_paths), get_next_line(fd, true));
		return (FAILURE);
	}
	if (allocate_and_copy_paths(w, tmp_paths, sprite_count) == true)
		allocated = true;
	free_array(tmp_paths);
	if (allocated == false)
		return (FAILURE);
	if (__validate_and_load_sprites(w) == FAILURE)
	{
		__clean_failed_weapon(w);
		return (FAILURE);
	}
	__add_weapon_to_data(d, w);
	return (SUCCESS);
}
