/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:57:10 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/17 18:43:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	__is_valid_number_str(char *str)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] != '\0' && ft_isspace((unsigned char)str[i]) == 1)
		i++;
	if (str[i] == '\0')
		return (false);
	len = ft_strlen(str) - 1;
	while (len >= i && ft_isspace((unsigned char)str[len]) == 1)
		len--;
	if (len < i)
		return (false);
	while (i <= len)
	{
		if (ft_isdigit(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

static char	**__rgb_to_convert(char *line)
{
	char	**rgb_array;
	char	*values_start;
	int		i;

	values_start = line;
	while (*values_start != '\0' && ft_isdigit(*values_start) == 0
		&& *values_start != ',')
		values_start++;
	if (*values_start == '\0' || *values_start == '\n' || *values_start == ',')
		return (NULL);
	rgb_array = ft_split(values_start, ',');
	secure_malloc(rgb_array, true);
	i = 0;
	while (rgb_array[i] != NULL)
	{
		if (i > 3 || __is_valid_number_str(rgb_array[i]) == false)
			return (free_array(rgb_array), NULL);
		i++;
	}
	if (i != 3)
		return (free_array(rgb_array), NULL);
	return (rgb_array);
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
		(err_msg(NULL, ERR_RGB_RANGE), exit_game(s_mlx(), FAILURE));
	g = ft_atoi(green, &result);
	if (g < 0 || g > 255)
		(err_msg(NULL, ERR_RGB_RANGE), exit_game(s_mlx(), FAILURE));
	b = ft_atoi(blue, &result);
	if (b < 0 || b > 255)
		(err_msg(NULL, ERR_RGB_RANGE), exit_game(s_mlx(), FAILURE));
	result = (r << 16);
	result = result | (g << 8);
	result = result | (b);
	return ((uint32_t)result);
}

void	process_color_lines(char *line)
{
	char		id;
	char		**rgb_array;
	uint32_t	color;

	id = line[0];
	rgb_array = __rgb_to_convert(line);
	if (rgb_array == NULL)
		(err_msg(NULL, ERR_RGB), exit_game(s_mlx(), FAILURE));
	color = __convert_rgb_to_uint(rgb_array[0], rgb_array[1], rgb_array[2]);
	if (id == 'F')
	{
		s_data()->floor_color = color;
		s_data()->features++;
	}
	else if (id == 'C')
	{
		s_data()->ceiling_color = color;
		s_data()->features++;
	}
	free_array(rgb_array);
}
