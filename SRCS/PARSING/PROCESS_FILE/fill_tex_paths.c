/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tex_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:02:38 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/18 08:07:51 by annabrag         ###   ########.fr       */
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

int	fill_wall_tex_paths(char *line, t_textures *tex)
{
	int	id;

	id = get_wall_id(line);
	if (id >= 0)
	{
		if (tex->path[id] != NULL)
			return (err_msg(NULL, ERR_PATH), FAILURE);
		tex->path[id] = get_texture_path(line);
		if (tex->path[id] == NULL)
			return (err_msg(NULL, ERR_MISSING_TEX), FAILURE);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	fill_bonus_tex_paths(char *line, t_textures *tex)
{
	int	id;

	id = get_other_id(line);
	if (id >= 0)
	{
		if (tex->path[id] != NULL)
			return (err_msg(NULL, ERR_PATH), FAILURE);
		tex->path[id] = get_texture_path(line);
		if (tex->path[id] == NULL)
			return (err_msg(NULL, ERR_MISSING_TEX), FAILURE);
		return (SUCCESS);
	}
	return (FAILURE);
}
