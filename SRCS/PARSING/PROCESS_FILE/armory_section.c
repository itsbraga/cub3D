/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   armory_section.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:10:48 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 07:40:35 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__process_single_weapon(char *name, int fd, t_data *d, char *line)
{
	t_weapon	*weapon;
	char		*marker_line;
	char		*trimmed_marker;

	weapon = new_weapon(name);
	secure_malloc(weapon, true);
	marker_line = get_next_line(fd, false);
	if (marker_line == NULL)
		exit_game(s_mlx(), FAILURE);
	trimmed_marker = skip_spaces(marker_line);
	if (trimmed_marker[0] != '%'
		|| (trimmed_marker[1] != '\0' && trimmed_marker[1] != '\n'))
	{
		err_msg(NULL, ERR_MISSING_MARK);
		(free(marker_line), free(line), free_weapon(weapon));
		get_next_line(fd, true);
		exit_game(s_mlx(), FAILURE);
	}
	free(marker_line);
	if (process_weapon_sprites(fd, weapon, d) == FAILURE)
	{
		(free(line), free_weapon(weapon));
		get_next_line(fd, true);
		exit_game(s_mlx(), FAILURE);
	}
}

void	process_armory_section(int fd, t_data *d)
{
	char	*line;
	char	*trimmed;
	bool	section_closed;

	section_closed = false;
	line = get_next_line(fd, false);
	while (line != NULL)
	{
		if (ft_strncmp(line, "------------", 12) == 0)
			return (section_closed = true, free(line));
		trimmed = skip_spaces(line);
		if (is_empty_line(trimmed) == false)
		{
			if (is_weapon_typename(trimmed) == true)
				__process_single_weapon(trimmed, fd, d, line);
			else
				(err_msg(NULL, ERR_WPN_NAME), free(line),
					get_next_line(fd, true), exit_game(s_mlx(), 1));
		}
		free(line);
		line = get_next_line(fd, false);
	}
	get_next_line(fd, true);
	if (section_closed == false)
		(free(line), exit_game(s_mlx(), FAILURE));
}
