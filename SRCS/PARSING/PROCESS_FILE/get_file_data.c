/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:55 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/18 17:54:03 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__process_file_content(char *line, char *trimmed, t_data *d)
{
	if (is_wall_tex_line(trimmed) == true)
		process_wall_tex_lines(line, trimmed, d->decor_tex);
	else if (trimmed[0] == 'F' || trimmed[0] == 'C' || trimmed[0] == 'D')
	{
		if (!BONUS)
			process_color_lines(line, trimmed);
		else
			process_bonus_tex_lines(line, trimmed, d->decor_tex);
	}
	else if ((!BONUS && d->features < 6 && is_map_line(line, trimmed))
		|| (BONUS && d->features < 7 && is_bonus_map_line(line, trimmed)))
	{
		err_msg(NULL, ERR_CONFIG);
		free(line);
		get_next_line(d->map->fd, true);
		exit_game(s_mlx(), FAILURE);
	}
	else if ((!BONUS && d->features == 6 && is_map_line(line, trimmed))
		|| (BONUS && d->features == 7 && is_bonus_map_line(line, trimmed)))
		fill_map2d_array(d->map, line);
}

static char	*__handle_line(int fd, t_data *d, bool *armory_done, char *line)
{
	char	*trimmed;

	trimmed = skip_spaces(line);
	if (is_empty_line(trimmed) == false)
	{
		if (*armory_done == false && ft_strncmp(trimmed, ARMORY, 12) == 0)
		{
			free(line);
			process_armory_section(fd, d);
			*armory_done = true;
			return (get_next_line(fd, false));
		}
		__process_file_content(line, trimmed, d);
	}
	free(line);
	return (get_next_line(fd, false));
}

void	get_file_data(int fd, t_data *d)
{
	char	*line;
	bool	armory_done;

	armory_done = false;
	line = get_next_line(fd, false);
	while (line != NULL)
		line = __handle_line(fd, d, &armory_done, line);
	get_next_line(fd, true);
}
