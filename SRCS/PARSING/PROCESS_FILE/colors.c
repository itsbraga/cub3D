/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:57:10 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 07:06:25 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	__is_valid_number_str(char *str)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] != '\0' && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '\0')
		return (false);
	len = ft_strlen(str) - 1;
	while (len >= i && ft_isspace(str[len]) == 1)
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
	char	*vstart;
	int		i;

	vstart = line;
	while (*vstart != '\0' && ft_isdigit(*vstart) == 0 && *vstart != ',')
		vstart++;
	if (*vstart == '\0' || *vstart == '\n' || *vstart == ',')
		return (NULL);
	rgb_array = ft_split(vstart, ',');
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

static uint32_t	__convert_rgb_to_uint(char *line, char **rgb_array)
{
	int	result;
	int	r;
	int	g;
	int	b;

	result = 0;
	r = ft_atoi(rgb_array[0], &result);
	g = ft_atoi(rgb_array[1], &result);
	b = ft_atoi(rgb_array[2], &result);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
	{
		err_msg(NULL, ERR_RGB_RANGE);
		free_array(rgb_array);
		free(line);
		get_next_line(s_data()->map->fd, true);
		exit_game(s_mlx(), FAILURE);
	}
	result = (r << 16);
	result = result | (g << 8);
	result = result | (b);
	return ((uint32_t)result);
}

void	process_color_lines(char *line, char *trimmed)
{
	int			id;
	char		**rgb_array;
	uint32_t	color;

	id = get_other_id(trimmed);
	rgb_array = __rgb_to_convert(trimmed);
	if (rgb_array == NULL)
	{
		err_msg(NULL, ERR_RGB);
		(free_array(rgb_array), free(line));
		get_next_line(s_data()->map->fd, true);
		exit_game(s_mlx(), FAILURE);
	}
	color = __convert_rgb_to_uint(line, rgb_array);
	if (id == F)
	{
		s_data()->floor_color = color;
		s_data()->features++;
	}
	else if (id == C)
	{
		s_data()->ceiling_color = color;
		s_data()->features++;
	}
	free_array(rgb_array);
}
