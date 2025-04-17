/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tex_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:02:38 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/17 03:25:16 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*get_texture_path(char *line)
{
	char	*start;
	char	*path;
	size_t	len;

	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	start = ft_strchr(line, '.');
	if (start == NULL)
		return (NULL);
	len = ft_strlen_gnl(start, 0);
	if (start[len - 1] == '\n')
		len--;
	path = ft_substr(start, 0, len);
	secure_malloc(path, true);
	return (path);
}

int	fill_tex_paths(char *line, t_textures *tex)
{
	if (ft_strncmp(line, "NO", 2) == 0 && tex->path[NO] == NULL)
	{
		tex->path[NO] = get_texture_path(line);
		if (tex->path[NO] == NULL)
			return (err_msg(NULL, ERR_MISSING_TEX), FAILURE);
		printf(BOLD PB "NORTH: " RESET "[%s]\n", tex->path[NO]);
	}
	else if (ft_strncmp(line, "SO", 2) == 0 && tex->path[SO] == NULL)
	{
		tex->path[SO] = get_texture_path(line);
		if (tex->path[SO] == NULL)
			return (err_msg(NULL, ERR_MISSING_TEX), FAILURE);
		printf(BOLD PB "SOUTH: " RESET "[%s]\n", tex->path[SO]);
	}
	else if (ft_strncmp(line, "WE", 2) == 0 && tex->path[WE] == NULL)
	{
		tex->path[WE] = get_texture_path(line);
		if (tex->path[WE] == NULL)
			return (err_msg(NULL, ERR_MISSING_TEX), FAILURE);
		printf(BOLD PB "WEST: " RESET "[%s]\n", tex->path[WE]);
	}
	else if (ft_strncmp(line, "EA", 2) == 0 && tex->path[EA] == NULL)
	{
		tex->path[EA] = get_texture_path(line);
		if (tex->path[EA] == NULL)
			return (err_msg(NULL, ERR_MISSING_TEX), FAILURE);
		printf(BOLD PB "EAST: " RESET "[%s]\n", tex->path[EA]);
	}
	return (SUCCESS);
}

int	fill_bonus_tex_paths(char *line, t_textures *tex)
{
	if (line[0] == 'F' && tex->path[F] == NULL)
	{
		tex->path[F] = get_texture_path(line);
		if (tex->path[F] == NULL)
			return (err_msg(NULL, ERR_MISSING_TEX), FAILURE);
		printf(BOLD PG "FLOOR: " RESET "[%s]\n", tex->path[F]);
	}
	else if (line[0] == 'C' && tex->path[C] == NULL)
	{
		tex->path[C] = get_texture_path(line);
		if (tex->path[C] == NULL)
			return (err_msg(NULL, ERR_MISSING_TEX), FAILURE);
		printf(BOLD PG "CEILING: " RESET "[%s]\n", tex->path[C]);
	}
	else if (line[0] == 'D' && tex->path[D] == NULL)
	{
		tex->path[D] = get_texture_path(line);
		if (tex->path[D] == NULL)
			return (err_msg(NULL, ERR_MISSING_TEX), FAILURE);
		printf(BOLD PY "DOOR: " RESET "[%s]\n", tex->path[D]);
	}
	return (SUCCESS);
}
