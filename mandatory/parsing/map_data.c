/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:53:59 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/04 12:03:07 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//recupere le fd du fichier cub, le traite, et le ferme

char **get_all_xpm_paths(int fd)
{
	int i;
	char **array;
	char *buffer;
	
	i = 0;
	array = malloc(4 * sizeof(char *));
	buffer = NULL;
	secure_malloc(array, true);
	while (i < 4)
	{
		buffer = get_next_line(fd, false);
		secure_malloc(array, true);
		array[i] = ft_substr(ft_strchr(buffer, '.'), 0, ft_strlen_gnl(buffer, 0) - 1);
		printf("pathtex_array[%d] = %s\n", array[i]);
		free(buffer);
		i++;
	}
	return (array);
}

int *get_textures(t_data *data)
{
	char **xpm_path_array;
	
	xpm_path_array = get_all_xpm_paths(data->fd);
	data->texture = malloc(4 * sizeof(int *));
	secure_malloc(data->texture, true);
}

void get_ceiling_rgb(t_data *data)
{
	int		i;
	char 	*buffer;
	char	*ceiling_str;
	char	**rgb_array;

	i = 0;
	buffer = NULL;
	while (1)
	{
		buffer = get_next_line(data->fd, false);
		if (buffer[0] == 'C')
		{
			while (buffer[i] < '0' && buffer[i] > '9')
				i++;
			ceiling_str = buffer + i;
			free(buffer);
			break;
		}
		free(buffer);
	}
	rgb_array = ft_split(ceiling_str, ',');
	data->ceiling_color = rgb_to_int(rgb_array[0], rgb_array[1], rgb_array[2]);
	free_array(rgb_array);
	return ;
}

void get_floor_rgb(t_data *data)
{
	int		i;
	char 	*buffer;
	char	*floor_str;
	char	**rgb_array;

	i = 0;
	buffer = NULL;
	while (1)
	{
		buffer = get_next_line(data->fd, false);
		if (buffer[0] == 'F')
		{
			while (buffer[i] < '0' && buffer[i] > '9')
				i++;
			floor_str = buffer + i;
			free(buffer);
			break;
		}
		free(buffer);
	}
	rgb_array = ft_split(floor_str, ',');
	data->floor_color = rgb_to_int(rgb_array[0], rgb_array[1], rgb_array[2]);
	free_array(rgb_array);
	return ;
}

int	rgb_to_int(char *red, char *green, char *blue)
{
	int	r;
	int	g;
	int	b;
	int	result;

	result = 0;
	r = ft_atoi(red, &result);
	g = ft_atoi(green, &result);
	b = ft_atoi(blue, &result);
	result = (r << 16);
	result = result | (g << 8);
	result = result | (b);
	return (result);
}

size_t	get_size_map_array(t_data *data)
{
	size_t	i;
	char *buffer;

	i = 0;
	buffer = NULL;
	while (1)
	{
		buffer = get_next_line(data->fd, false);
		if (buffer == NULL)
			break;
		else if (ft_strchr(buffer, '1') != NULL)
			i++; 
	}
	close(data->fd);
	return (i);
}

void	get_map_array(t_data *data)
{
	size_t	size_map_array;

	size_map_array = get_size_map_array(data);
	data->fd = open(data->cubfile_path, O_RDONLY);
	if (data->fd == -1)
	{
		perror(strerror(errno));
		exit_game(mlx_s(), FAILURE);
	}
	while (ft_strchr(buffer))
}

void    get_map_data(t_data *data, char **argv)
{
	data->cubfile_path = argv[1];
	data->fd = open(data->cubfile_path, O_RDONLY);
	if (data->fd == -1)
	{
		perror(strerror(errno));
		exit_game(mlx_s(), FAILURE);
	}
	get_textures(data);
	get_floor_rgb(data);
	get_ceiling_rgb(data);
	get_map_array(data);
	close(data->fd);
	return ;
}
