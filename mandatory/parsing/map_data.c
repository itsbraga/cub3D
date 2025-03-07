/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:53:59 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/06 18:59:25 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// recupere le fd du fichier cub, le traite, et le ferme

char	**get_all_xpm_paths(int fd)
{
	int		i;
	char	**array;
	char	*buffer;
	
	i = 0;
	array = malloc(4 * sizeof(char *)); // pourquoi pas yama(CREATE...) ?
	buffer = NULL;
	secure_malloc(array, true);
	while (i < 4)
	{
		buffer = get_next_line(fd, false);
		secure_malloc(array, true);
		array[i] = ft_substr(ft_strchr(buffer, '.'), 0, ft_strlen_gnl(buffer, 0) - 1);
		// check si ajout de ce malloc a yama
		// printf("pathtex_array[%d] = %s\n", array[i], );
		free(buffer);
		i++;
	}
	return (array);
}

// int	*get_textures(t_data *data)
// {
// 	char **xpm_path_array;
	
// 	xpm_path_array = get_all_xpm_paths(data->fd);
// 	data->texture = malloc(4 * sizeof(int *)); // pourquoi pas yama(CREATE...) ?
// 	secure_malloc(data->texture, true);
// }

void	get_ceiling_rgb(t_data *data)
{
	int		i;
	char 	*buffer;
	char	*ceiling_str;
	char	**rgb_array;

	i = 0;
	buffer = NULL;
	while (true)
	{
		buffer = get_next_line(data->map->fd, false);
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
	while (true)
	{
		buffer = get_next_line(data->map->fd, false);
		if (buffer[0] == 'F')
		{
			while (ft_isdigit(buffer[i]) == 1)
				i++;
			floor_str = buffer + i;
			free(buffer);
			break;
		}
		free(buffer);
	}
	rgb_array = ft_split(floor_str, ',');
	// check si ajout de ce malloc a yama
	data->floor_color = rgb_to_int(rgb_array[0], rgb_array[1], rgb_array[2]);
	free_array(rgb_array);
	return ;
}

size_t	get_size_map_array(t_data *data)
{
	size_t	i;
	char	*buffer;

	i = 0;
	buffer = NULL;
	while (true)
	{
		buffer = get_next_line(data->map->fd, false);
		if (buffer == NULL)
			break;
		else if (ft_strchr(buffer, '1') != NULL)
			i++; 
	}
	close(data->map->fd);
	return (i);
}

// void	get_map_array(t_data *data)
// {
// 	size_t	size_map_array;

// 	size_map_array = get_size_map_array(data);
// 	data->fd = open(data->cubfile_path, O_RDONLY);
// 	if (data->fd == -1)
// 	{
// 		perror(strerror(errno));
// 		mlx_exit(mlx_s(), FAILURE);
// 	}
// 	// while (ft_strchr(buffer))
// }

void    get_map_data(t_data *data, char **argv)
{
	data->map->file_path = argv[1];
	data->map->fd = open(data->map->file_path, O_RDONLY);
	if (data->map->fd == -1)
	{
		perror(strerror(errno));
		mlx_exit(mlx_s(), FAILURE);
	}
	// get_textures(data);
	get_floor_rgb(data);
	get_ceiling_rgb(data);
	// get_map_array(data);
	close(data->map->fd);
	return ;
}
