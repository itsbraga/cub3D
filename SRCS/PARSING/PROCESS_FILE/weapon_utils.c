/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 02:12:03 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/16 03:13:46 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Read sprite paths until '%'
int	read_sprite_paths(int fd, char **tmp_paths, int max_sprites)
{
	char	*line;
	char	*path;
	char	*trimmed;
	int		count;

	count = 0;
	line = get_next_line(fd, false);
	while (line != NULL)
	{
		trimmed = skip_spaces(line);
		if (trimmed[0] == '%' && (trimmed[1] == '\0' || trimmed[1] == '\n'))
			return (free(line), count);
		if (trimmed[0] == '%')
			return (free(line), -1);
		if (is_sprite_line(line))
		{
			if (count >= max_sprites)
				return (free(line), -1);
			path = get_texture_path(line);
			tmp_paths[count++] = path;
		}
		free(line);
		line = get_next_line(fd, false);
	}
	return (-1);
}

bool	allocate_and_copy_paths(t_weapon *w, char **tmp_paths, int count)
{
	int	i;

	w->xpm_count = count;
	w->sprites.path = yama(CREATE, NULL, sizeof(char *) * count);
	secure_malloc(w->sprites.path, true);
	w->sprites.imgs = yama(CREATE, NULL, sizeof(t_img) * count);
	secure_malloc(w->sprites.imgs, true);
	ft_bzero(w->sprites.imgs, sizeof(t_img) * count);
	i = 0;
	while (i < count)
	{
		w->sprites.path[i] = tmp_paths[i];
		tmp_paths[i] = NULL;
		i++;
	}
	return (true);
}

static void	__reallocate_weapons_array(t_data *d)
{
	t_weapon	**new_array;
	int			new_capacity;
	int			i;

	new_capacity = d->weapon_capacity + 1;
	new_array = yama(CREATE, NULL, sizeof(t_weapon *) * new_capacity);
	secure_malloc(new_array, true);
	i = 0;
	while (i < d->weapon_count)
	{
		new_array[i] = d->weapons[i];
		i++;
	}
	yama(REMOVE, d->weapons, 0);
	d->weapons = new_array;
	d->weapon_capacity = new_capacity;
}

void	expand_weapons_array(t_data *d)
{
	t_weapon	**new_array;
	int			initial_capacity;

	if (d->weapons == NULL)
	{
		initial_capacity = 1;
		new_array = yama(CREATE, NULL, sizeof(t_weapon *) * initial_capacity);
		secure_malloc(new_array, true);
		d->weapons = new_array;
		d->weapon_capacity = initial_capacity;
	}
	else if (d->weapon_count == d->weapon_capacity)
		__reallocate_weapons_array(d);
}

void	load_and_resize_sprites(t_weapon *w)
{
	int		i;
	float	scale_factor;
	t_img	original_img;

	i = 0;
	while (i < w->xpm_count)
	{
		original_img = xpm_to_img(w->sprites.path[i]);
		scale_factor = (WIN_HEIGHT * 0.35) / original_img.height;
		w->sprites.imgs[i] = resize_img(scale_factor, &original_img);
		i++;
	}
	if (w->id == 0)
		w->pos.x = (int)WIN_WIDTH / 3;
	else if (w->id == 1)
		w->pos.x = (int)WIN_WIDTH / 2 + 40;
	w->pos.y = (int)WIN_HEIGHT / 1.50;
}
