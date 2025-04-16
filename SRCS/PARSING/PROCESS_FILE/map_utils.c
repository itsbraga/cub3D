/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:20:42 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/16 14:55:04 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	get_longest_line(char **map2d, size_t height)
{
	size_t	i;
	size_t	max;
	size_t	len;

	i = 0;
	max = 0;
	len = 0;
	while (i < height)
	{
		len = ft_strlen(map2d[i]) - 1;
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '\n' && line[i] != '\t'
			&& ft_strchr(VALID_MAP, line[i]) == NULL)
		{
			err_msg_quoted(&line[i], ERR_CHAR);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	is_bonus_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '\n' && line[i] != '\t'
			&& ft_strchr(VALID_BONUS_MAP, line[i]) == NULL)
		{
			err_msg_quoted(&line[i], ERR_CHAR);
			return (false);
		}
		i++;
	}
	return (true);
}
