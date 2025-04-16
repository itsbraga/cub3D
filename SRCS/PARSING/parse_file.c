/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:36 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/16 15:04:03 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__init_map(t_map *map, char *path_to_file, int fd, t_data *data)
{
	ft_bzero(map, sizeof(t_map));
	map->path_to_file = yama(ADD, ft_strdup(path_to_file), 0);
	secure_malloc(map->path_to_file, true);
	map->fd = fd;
	data->map = map;
}

static bool	__process_map_data(t_map *map, t_data *data, char *arg, int fd)
{
	__init_map(map, arg, fd, data);
	get_file_data(fd, data);
	close(fd);
	if (map->map2d == NULL || map->size.height == 0)
		return (false);
	return (true);
}

static bool	__validate_map(char **flood_map, t_size size, t_player *player)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)(player->pos.x / TILE_SIZE);
	pos_y = (int)(player->pos.y / TILE_SIZE);
	if (flood_fill(flood_map, pos_y, pos_x, size) == false)
	{
		free_array(flood_map);
		return (false);
	}
	free_array(flood_map);
	return (true);
}

static void	__replace_by_final_map(t_data *data, size_t longest_line)
{
	char	**final_map;

	final_map = normalize_final_map(data->map->map2d, data->map->size.height,
			longest_line);
	secure_malloc(final_map, true);
	free_array(data->map->map2d);
	data->map->map2d = final_map;
	data->map->size.width = longest_line;
}

int	parse_file(char *arg, t_data *data, t_game *game)
{
	int		fd;
	t_map	*map;
	size_t	longest_line;
	char	**flood_map;
	t_size	size;

	fd = check_cub_file(arg);
	map = data->map;
	if (__process_map_data(map, data, arg, fd) == false)
		return (FAILURE);
	longest_line = get_longest_line(map->map2d, map->size.height);
	size = (t_size){longest_line, map->size.height};
	flood_map = normalize_map_for_flood(map->map2d, size);
	secure_malloc(flood_map, true);
	if (__validate_map(flood_map, size, game->player) == false)
		return (FAILURE);
	__replace_by_final_map(data, longest_line);
	get_player_direction(map, game->player);
	game->data = data;
	return (SUCCESS);
}
