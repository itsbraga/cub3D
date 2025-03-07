/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:57:10 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/07 21:56:35 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	process_color_line(char *line, t_data *data)
{
	char	**rgb_array;

	rgb_array = NULL;
	if (line[0] == 'F')
	{
		while (ft_isdigit(*line) != 1)
			line++;
		rgb_array = ft_split(line, ',');
		secure_malloc(rgb_array, true);
		data->floor_color = convert_rgb_into_int(rgb_array[0], rgb_array[1],
				rgb_array[2]);
		data->feature_filled++;
	}
	else
	{
		while (ft_isdigit(*line) != 1)
			line++;
		rgb_array = ft_split(line, ',');
		secure_malloc(rgb_array, true);
		data->ceiling_color = convert_rgb_into_int(rgb_array[0], rgb_array[1],
				rgb_array[2]);
		data->feature_filled++;
	}
	free_array(rgb_array);
}
