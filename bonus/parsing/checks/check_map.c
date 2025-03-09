/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:14:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/10 00:43:55 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '\n' && ft_strchr(MAP_CHARS, line[i]) == NULL)
		{
			err_msg_quoted(&line[i], ERR_CHAR);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	__flood_fill(char **map, int x, int y, size_t height, size_t width)
{
	if (x < 0 || y < 0 || (size_t)x >= height || (size_t)y >= width)
	{
		err_msg(NULL, ERR_MAP_BORDERS);
		return (false);
	}
	if (map[x][y] == '1' || map[x][y] == 'F')
		return (true);
	map[x][y] = 'F';
	if (!__flood_fill(map, x - 1, y, height, width))
		return (false);
	if (!__flood_fill(map, x + 1, y, height, width))
		return (false);
	if (!__flood_fill(map, x, y - 1, height, width))
		return (false);
	if (!__flood_fill(map, x, y + 1, height, width))
		return (false);
	return (true);
}

static char	**__dup_map(char **map, size_t height)
{
	char	**dup;
	size_t	i;
	
	dup = malloc(sizeof(char *) * (height + 1));
	secure_malloc(dup, true); // ou false ?
	i = 0;
	while (i < height)
	{
		dup[i] = ft_strdup(map[i]);
		secure_malloc(dup[i], true);
		i++;
	}
	dup[height] = NULL;
	return (dup);
}

bool	map_fully_enclosed(char **map, size_t height, size_t width, t_point pos)
{
	char	**copy;
	bool	result;

	copy = __dup_map(map, height);
	secure_malloc(copy, true);
	result = __flood_fill(copy, (int)pos.x, (int)pos.y, height, width);
	free_array(copy);
	return (result);
}
