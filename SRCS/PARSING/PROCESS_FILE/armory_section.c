/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   armory_section.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:10:48 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/11 06:22:11 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__process_single_weapon(int fd, t_data *d, char *trimmed_name)
{
	t_weapon	*weapon;
	char		*marker_line;

	weapon = new_weapon(trimmed_name);
	secure_malloc(weapon, true);
	marker_line = get_next_line(fd, false);
	if (marker_line == NULL)
	{
		yama(REMOVE, weapon, 0);
		return ;
	}
	if (marker_line[0] != '%')
	{
		free(marker_line);
		yama(REMOVE, weapon, 0);
		return ;
	}
	free(marker_line);
	if (process_weapon_sprites(fd, weapon, d) == FAILURE)
	{
		yama(REMOVE, weapon, 0);
		return ;
	}
}

void	process_armory_section(int fd, t_data *d)
{
	char	*line;
	char	*trimmed;

	line = get_next_line(fd, false);
	while (line != NULL)
	{
		if (ft_strncmp(line, "------------", 12) == 0)
			return (free(line));
		trimmed = skip_spaces(line);
		if (is_empty_line(trimmed) == false)
		{
			if (is_weapon_typename(trimmed))
				__process_single_weapon(fd, d, trimmed);
			else
				(free(line), clean_exit(FAILURE));
		}
		free(line);
		line = get_next_line(fd, false);
	}
	clean_exit(FAILURE);
}
