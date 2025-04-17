/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/04/17 03:41:33 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

/*
	[1] Check top neighbor
	[2] Check bottom
	[3] Check left
	[4] Check right
*/
static bool	__is_invalid_neighbor(char **map, int i, int j)
{
	char	*valid_neighbors;

	if (BONUS)
		valid_neighbors = "0NSEW12";
	else
		valid_neighbors = "0NSEW1";
    if (ft_strlen(map[i - 1]) < (size_t)j
        || c_in_str(valid_neighbors, map[i - 1][j]) == false)
        return (err_msg(NULL, ERR_MAP_UNCLOSED), true);
    if (ft_strlen(map[i + 1]) < (size_t)j
        || c_in_str(valid_neighbors, map[i + 1][j]) == false)
        return (err_msg(NULL, ERR_MAP_UNCLOSED), true);
    if (j != 0 && c_in_str(valid_neighbors, map[i][j - 1]) == false)
        return (err_msg(NULL, ERR_MAP_UNCLOSED), true);
    if (c_in_str(valid_neighbors, map[i][j + 1]) == false)
        return (err_msg(NULL, ERR_MAP_UNCLOSED), true);
    return (false);
}

static int	__check_cell(char **map, int i, int j, int *player_count)
{
	char	*valid_inner;

	if (BONUS)
		valid_inner = "0NSEW2";
	else
		valid_inner = "0NSEW";
    if (c_in_str(valid_inner, map[i][j]) == true)
    {
        if (c_in_str("NSEW", map[i][j]) == true)
            (*player_count)++;
        if (__is_invalid_neighbor(map, i, j) == true)
            return (FAILURE);
    }
    else if (c_in_str(" 1", map[i][j]) == false)
        return (FAILURE);
    return (SUCCESS);
}

static int	__scan_map(char **map, int i, int j, int *player_count)
{
	while (map[i + 1] != NULL)
	{
		if (map[i][0] == '0')
			return (-1);
		j = 1;
		while (map[i][j] != '\0')
		{
			if (__check_cell(map, i, j, player_count) == FAILURE)
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

static int	__line_is_wall(char *line)
{
	int	j;

	j = 0;
	while (line != NULL && line[j] != '\0')
	{
		if (c_in_str(" 1", line[j]) == false)
			return (err_msg(NULL, ERR_MAP_UNCLOSED), FAILURE);
		j++;
	}
	return (SUCCESS);
}

int	check_map(char **map)
{
	int	i;
	int	player_count;

	i = 0;
	player_count = 0;
	if (__line_is_wall(map[0]) == FAILURE)
		return (FAILURE);
	i = __scan_map(map, i + 1, 0, &player_count);
	if (i == -1)
		return (FAILURE);
	if (player_count != 1)
		return (err_msg(NULL, ERR_NB_PLAYER), FAILURE);
	if (__line_is_wall(map[i]) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
