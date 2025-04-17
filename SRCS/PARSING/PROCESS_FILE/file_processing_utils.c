/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processing_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:50:46 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/16 20:52:49 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*skip_spaces(char *line)
{
	while (*line != '\0' && (*line == ' ' || *line == '\t'))
		line++;
	return (line);
}

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

bool	is_wall_tex_line(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
		return (true);
	return (false);
}

bool	is_weapon_typename(char *line)
{
	return (set_weapon_id(line) != -1);
}

bool	is_sprite_line(char *line)
{
	char	*trimmed;

	if (line == NULL || is_empty_line(line) == true || line[0] == '%')
		return (false);
	trimmed = skip_spaces(line);
	if (ft_strncmp(trimmed, "./", 2) == 0)
		return (true);
	return (false);
}
