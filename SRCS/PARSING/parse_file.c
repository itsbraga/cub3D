/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:36 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/18 21:22:14 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__init_map(t_map *map, char *path_to_file, int fd, t_data *d)
{
	ft_bzero(map, sizeof(t_map));
	map->path_to_file = ft_strdup(path_to_file);
	secure_malloc(map->path_to_file, true);
	map->fd = fd;
	d->map = map;
}

static bool	__process_file(t_map *map, char *arg, int fd, t_data *d)
{
	__init_map(map, arg, fd, d);
	get_file_data(fd, d);
	close(fd);
	if (map->map2d == NULL || map->size.height == 0)
		return (false);
	return (true);
}

static void	__replace_by_normed_map(t_map *map)
{
	char	**normed_map;
	size_t	longest_line;

	longest_line = get_longest_line(map->map2d, map->size.height);
	normed_map = normalize_map(map->map2d, map->size.height,
			longest_line);
	secure_malloc(normed_map, true);
	free_array(map->map2d);
	map->map2d = normed_map;
	map->size.width = longest_line;
}

int	parse_file(char *arg, t_data *d, t_game *g)
{
	int		fd;
	t_map	*map;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	map = d->map;
	if (__process_file(map, arg, fd, d) == false)
		return (FAILURE);
	__replace_by_normed_map(map);
	if (check_map(map->map2d) == FAILURE)
		return (FAILURE);
	find_player_start_pos(map, g->player);
	g->data = d;
	return (SUCCESS);
}
