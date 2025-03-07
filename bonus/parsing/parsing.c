/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:36 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/07 21:37:50 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

short	parsing(t_data *data, char *arg)
{
	int		fd;
	size_t	longest_line;
	char	**normed_map2d;

	fd = check_cub_file(arg);
	init_map(data->map, arg, fd, data);
	process_file_data(fd, data);
	close(fd);
	if (data->map->map2d == NULL || data->map->height == 0)
	{
		err_msg(NULL, ERR);
		clean_exit(FAILURE);
	}
	longest_line = get_longest_line(data->map->map2d, data->map->height);
	normed_map2d = normalize_map(data->map->map2d, data->map->height,
			longest_line);
	secure_malloc(normed_map2d, true);
	free(data->map->map2d);
	data->map->map2d = normed_map2d;
	data->map->width = longest_line;
	if (has_valid_map_borders(data->map->map2d, data->map->height,
			data->map->width) == false)
		return (FAILURE);
	find_player_position(data->map, game_s()->player);
	return (SUCCESS);
}
