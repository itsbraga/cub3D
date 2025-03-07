/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:15 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/07 20:57:02 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	add_map_lines(t_map *map, char *line)
{
	char	**tmp;
	size_t	i;

	tmp = yama(CREATE, NULL, (sizeof(char *) * (map->height + 2)));
	secure_malloc(tmp, true);
	i = 0;
	while (i < map->height)
	{
		tmp[i] = map->map2d[i];
		i++;
	}
	tmp[map->height] = ft_strdup(line);
	secure_malloc(tmp[map->height], true);
	tmp[map->height + 1] = NULL;
	free(map->map2d);
	map->map2d = tmp;
	map->height++;
}

void	process_file_data(int fd, t_data *data)
{
	char	*line;

	while (true)
	{
		line = get_next_line(fd, false);
		if (line != NULL)
		{
			if (is_empty_line(line) == true)
			{
				free(line);
				continue;
			}
			if (ft_strncmp(line, "NO", 2) == 0
				|| ft_strncmp(line, "SO", 2) == 0
				|| ft_strncmp(line, "WE", 2) == 0
				|| ft_strncmp(line, "EA", 2) == 0)
				process_texture_line(line, data);
			else if (line[0] == 'F' || line[0] == 'C')
				process_color_line(line, data);
			else if (data->feature_filled == 6 && is_map_line(line) == true)
				add_map_lines(data->map, line);
			else
				(err_msg(NULL, ERR_CONFIG), exit(FAILURE));
			free(line);
		}
	}
}
