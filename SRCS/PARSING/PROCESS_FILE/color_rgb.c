/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:57:10 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/11 02:18:57 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**__rgb_to_convert(char *line, char **to_convert)
{
	while (ft_isdigit(*line) != 1)
		line++;
	to_convert = ft_split(line, ',');
	secure_malloc(to_convert, true);
	return (to_convert);
}

static uint32_t	__convert_rgb_to_uint(char *red, char *green, char *blue)
{
	int	result;
	int	r;
	int	g;
	int	b;

	result = 0;
	r = ft_atoi(red, &result);
	if (r < 0 || r > 255)
		(err_msg(NULL, ERR_RGB), clean_exit(FAILURE));
	g = ft_atoi(green, &result);
	if (g < 0 || g > 255)
		(err_msg(NULL, ERR_RGB), clean_exit(FAILURE));
	b = ft_atoi(blue, &result);
	if (b < 0 || b > 255)
		(err_msg(NULL, ERR_RGB), clean_exit(FAILURE));
	result = (r << 16);
	result = result | (g << 8);
	result = result | (b);
	return ((uint32_t)result);
}

void	process_color_lines(char *line)
{
	char	**rgb_array;

	rgb_array = NULL;
	if (line[0] == 'F')
	{
		rgb_array = __rgb_to_convert(line, rgb_array);
		s_data()->floor_color = __convert_rgb_to_uint(rgb_array[0],
				rgb_array[1], rgb_array[2]);
		s_data()->feature_filled++;
	}
	else
	{
		rgb_array = __rgb_to_convert(line, rgb_array);
		s_data()->ceiling_color = __convert_rgb_to_uint(rgb_array[0],
				rgb_array[1], rgb_array[2]);
		s_data()->feature_filled++;
	}
	free_array(rgb_array);
}
