/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:36 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/07 14:22:29 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

short	parsing(t_data *data, char *arg)
{
	int		fd;
	size_t	longest_line;
	char	**normed_map2d;

	fd = check_file(arg);
	init_map(data->map, arg, fd);
	// fonction avec gnl qui assigne les valeurs a NO,SO,WE,EA + F,C + map2d
	close(fd);
	if (data->map->map2d == NULL || data->map->height == 0)
		(err_msg(NULL, ERR_MAP), exit(FAILURE)); // free t_map & t_data
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
