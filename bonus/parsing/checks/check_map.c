/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:14:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/07 21:55:31 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*  La description de la carte sera toujours en dernier
	dans le fichier, le reste des éléments peut être
	dans n’importe quel ordre
*/
bool	is_empty_line(char *line)
{
	while (*line != '\0')
	{
		if (ft_isspace(*line) == 0)
			return (false);
		line++;
	}
	return (true);
}

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

size_t	get_longest_line(char **map2d, size_t height)
{
	size_t	i;
	size_t	max;
	size_t	len;

	i = 0;
	max = 0;
	while (i < height)
	{
		len = ft_strlen(map2d[i]);
		if (len > max)
			max = len;
	}
	return (max);
}

bool	has_valid_map_borders(char **map2d, size_t height, size_t width)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < width)
	{
		if (map2d[0][j] != '1' || map2d[height - 1][j] != '1')
		{
			err_msg(NULL, ERR_MAP_BORDERS);
			return (false);
		}
		j++;
	}
	i = 0;
	while (i < height)
	{
		if (map2d[i][0] != '1' || map2d[i][width - 1] != '1')
		{
			err_msg(NULL, ERR_MAP_BORDERS);
			return (false);
		}
		i++;
	}
	return (true);
}

char	**normalize_map(char **map2d, size_t height, size_t width)
{
	char	**normed_map2d;
	size_t	i;
	size_t	j;
	size_t	line_len;

	normed_map2d = yama(CREATE, NULL, (sizeof(char *) * (height + 1)));
	secure_malloc(normed_map2d, true);
	i = 0;
	while (i < height)
	{
		normed_map2d[i] = yama(CREATE, NULL, (width + 1));
		secure_malloc(normed_map2d[i], true);
		line_len = ft_strlen(map2d[i]);
		j = 0;
		while (j < width)
		{
			if (j < line_len)
			{
				if (map2d[i][j] == ' ')
					normed_map2d[i][j] = '1';
				else
					normed_map2d[i][j] = map2d[i][j];
			}
			else
				normed_map2d[i][j] = '1';
			j++;
		}
		normed_map2d[i][width] = '\0';
		i++;
	}
	normed_map2d[height] = NULL;
	return (normed_map2d);
}
