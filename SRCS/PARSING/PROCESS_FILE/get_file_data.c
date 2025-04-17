/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:55 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/17 03:32:21 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__process_line(char *line, char *trimmed, t_data *data)
{
	if (is_wall_tex_line(trimmed) == true)
		process_mandatory_tex_lines(trimmed, data->decor_tex);
	else if (trimmed[0] == 'F' || trimmed[0] == 'C' || trimmed[0] == 'D')
	{
		if (!BONUS)
			process_color_lines(trimmed);
		else
			process_bonus_tex_lines(trimmed, data->decor_tex);
	}
	else if ((!BONUS && data->features < 6 && is_map_line(trimmed))
		|| (BONUS && data->features < 7 && is_bonus_map_line(trimmed)))
	{
		err_msg(NULL, ERR_MAP_NOT_LAST);
		clean_exit(FAILURE);
	}
	else if ((!BONUS && data->features == 6 && is_map_line(trimmed))
		|| (BONUS && data->features == 7 && is_bonus_map_line(trimmed)))
		fill_map2d_array(data->map, line);
}

void	get_file_data(int fd, t_data *data)
{
	char	*line;
	char	*trimmed;
	bool	armory_done;

	armory_done = false;
	line = get_next_line(fd, false);
	while (line != NULL)
	{
		trimmed = skip_spaces(line);
		if (is_empty_line(trimmed) == false)
		{
			if (armory_done == false && ft_strncmp(trimmed, ARMORY, 12) == 0)
			{
				free(line);
				process_armory_section(fd, data);
				armory_done = true;
				line = get_next_line(fd, false);
				continue ;
			}
			else
				__process_line(line, trimmed, data);
		}
		free(line);
		line = get_next_line(fd, false);
	}
}
