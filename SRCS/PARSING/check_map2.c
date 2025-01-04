/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:14:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/04 21:17:16 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	has_valid_chars(char **map, int rows)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			c = map[i][j];
			if (ft_strchr(VALID_MAP, c) == NULL)
				return (err_msg(c, ERR_CHAR, 1), false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	find_player_start(char **map, int rows, t_point *start_pos)
{
	bool	found_start;
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			c = map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (found_start == true)
					return (err_msg(NULL, ERR_MPLAYER, 0), false);
				found_start = true;
				start_pos->x = j;
				start_pos->y = i;
			}
			j++;
		}
		i++;
	}
	if (found_start == false)
		return (err_msg(NULL, ERR_START_P, 0), false);
	return (true);
}

bool    first_verification(char **map, int rows, t_point *start)
{
	if (has_valid_chars(map, rows) == false)
		return (false);
	if (find_player_start(map, rows, start) == false)
		return (false);
	return (true);
}
