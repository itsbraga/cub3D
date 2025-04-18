/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:20:42 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/18 07:49:36 by annabrag         ###   ########.fr       */
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

bool	is_map_line(char *line, char *trimmed)
{
	int	i;

	i = 0;
	while (trimmed[i] != '\0')
	{
		if (trimmed[i] != '\n' && trimmed[i] != '\t'
			&& ft_strchr("NSEW 01", trimmed[i]) == NULL)
		{
			ft_printf(STDERR_FILENO, BOLD RED ERR RESET);
			free(line);
			get_next_line(s_data()->map->fd, true);
			exit_game(s_mlx(), FAILURE);
		}
		i++;
	}
	return (true);
}

bool	is_bonus_map_line(char *line, char *trimmed)
{
	int	i;

	i = 0;
	while (trimmed[i] != '\0')
	{
		if (trimmed[i] != '\n' && trimmed[i] != '\t'
			&& ft_strchr("NSEW 012", trimmed[i]) == NULL)
		{
			ft_printf(STDERR_FILENO, BOLD RED ERR RESET);
			free(line);
			get_next_line(s_data()->map->fd, true);
			exit_game(s_mlx(), FAILURE);
		}
		i++;
	}
	return (true);
}

bool	c_in_str(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}
