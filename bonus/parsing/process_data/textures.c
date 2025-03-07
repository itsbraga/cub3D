/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:47:23 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/07 21:58:44 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

// verifier si le fichier .xpm existe et est accessible (cf. check_arg)
// static void	__fill_nord_texture(char *line, t_data *data)
// {
// 	char	*path;
// 	size_t	len;

// 	len = ft_strlen_gnl(line, 0) - 1;
// 	path = ft_substr(ft_strchr(line, '.'), 0, len);
// 	secure_malloc(path, true);
// 	if (check_xpm_file(path) == FAILURE)
// 		clean_exit(FAILURE);
// 	printf(BOLD BLUE "texture path: %s\n" RESET, path);
// 	data->texture[NO] = xpm_to_mlx_img(path);
// 	data->feature_filled++;
// }

// static void	__fill_south_texture(char *line, t_data *data)
// {
// 	char	*path;
// 	size_t	len;

// 	len = ft_strlen_gnl(line, 0) - 1;
// 	path = ft_substr(ft_strchr(line, '.'), 0, len);
// 	secure_malloc(path, true);
// 	if (check_xpm_file(path) == FAILURE)
// 		clean_exit(FAILURE);
// 	printf(BOLD BLUE "texture path: %s\n" RESET, path);
// 	data->texture[SO] = xpm_to_mlx_img(path);
// 	data->feature_filled++;
// }

// static void	__fill_west_texture(char *line, t_data *data)
// {
// 	char	*path;
// 	size_t	len;

// 	len = ft_strlen_gnl(line, 0) - 1;
// 	path = ft_substr(ft_strchr(line, '.'), 0, len);
// 	secure_malloc(path, true);
// 	if (check_xpm_file(path) == FAILURE)
// 		clean_exit(FAILURE);
// 	printf(BOLD BLUE "texture path: %s\n" RESET, path);
// 	data->texture[WE] = xpm_to_mlx_img(path);
// 	data->feature_filled++;
// }

// static void	__fill_east_texture(char *line, t_data *data)
// {
// 	char	*path;
// 	size_t	len;

// 	len = ft_strlen_gnl(line, 0) - 1;
// 	path = ft_substr(ft_strchr(line, '.'), 0, len);
// 	secure_malloc(path, true);
// 	if (check_xpm_file(path) == FAILURE)
// 		clean_exit(FAILURE);
// 	printf(BOLD BLUE "texture path: %s\n" RESET, path);
// 	data->texture[EA] = xpm_to_mlx_img(path);
// 	data->feature_filled++;
// }

void	process_texture_line(char *line, t_data *data)
{
	char	*path;
	size_t	len;

	if (ft_strncmp(line, "NO", 2) == 0)
	{
		len = ft_strlen_gnl(line, 0) - 1;
		path = ft_substr(ft_strchr(line, '.'), 0, len);
		printf(BOLD BLUE "texture path: %s\n" RESET, path);
		secure_malloc(path, true);
		data->texture[NO] = xpm_to_mlx_img(path);
		data->feature_filled++;
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		len = ft_strlen_gnl(line, 0) - 1;
		path = ft_substr(ft_strchr(line, '.'), 0, len);
		printf(BOLD BLUE "texture path: %s\n" RESET, path);
		secure_malloc(path, true);
		data->texture[SO] = xpm_to_mlx_img(path);
		data->feature_filled++;
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		len = ft_strlen_gnl(line, 0) - 1;
		path = ft_substr(ft_strchr(line, '.'), 0, len);
		printf(BOLD BLUE "texture path: %s\n" RESET, path);
		secure_malloc(path, true);
		data->texture[WE] = xpm_to_mlx_img(path);
		data->feature_filled++;
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		len = ft_strlen_gnl(line, 0) - 1;
		path = ft_substr(ft_strchr(line, '.'), 0, len);
		printf(BOLD BLUE "texture path: %s\n" RESET, path);
		secure_malloc(path, true);
		data->texture[EA] = xpm_to_mlx_img(path);
		data->feature_filled++;
	}
	else
		return ;
}
