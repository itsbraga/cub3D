/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:01:03 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/04 21:21:56 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool    check_borders(char **map, int rows, int cols)
{
	int i;

	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	is_fully_enclosed(char **map, int rows, int cols, int x, int y)
{
	bool	left;
	bool	right;
	bool	up;
	bool	down;

	if (x < 0 || y < 0 || x >= cols || y >= rows || map[y][x] == ' ')
		return (false);
	if (map[y][x] == '1' || map[y][x] == '2')
		return (true);
	map[y][x] = '2'; // on marque comme deja vu
	right = is_fully_enclosed(map, rows, cols, x + 1, y);
	left = is_fully_enclosed(map, rows, cols, x - 1, y);
	down = is_fully_enclosed(map, rows, cols, x, y + 1);
	up = is_fully_enclosed(map, rows, cols, x, y - 1);
	if (right == true && left == true && down == true && up == true)
		return (true);
	return (false);
}
