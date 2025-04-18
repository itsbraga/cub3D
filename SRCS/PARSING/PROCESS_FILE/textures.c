/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:47:23 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 08:09:14 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	__has_all_textures(t_textures *tex)
{
	return (tex->path[NO] && tex->path[SO] && tex->path[WE] && tex->path[EA]);
}

void	process_wall_tex_lines(char *line, char *trimmed, t_textures *tex)
{
	int	id;

	id = get_wall_id(trimmed);
	if (id < 0)
		return ;
	if (fill_wall_tex_paths(trimmed, tex) == FAILURE)
	{
		free(line);
		get_next_line(s_data()->map->fd, true);
		exit_game(s_mlx(), FAILURE);
	}
	if (__has_all_textures(tex) && check_wall_tex_paths(tex) == FAILURE)
	{
		free(line);
		get_next_line(s_data()->map->fd, true);
		exit_game(s_mlx(), FAILURE);
	}
	if (tex->imgs[id].img_ptr == NULL)
	{
		tex->imgs[id] = xpm_to_img(tex->path[id]);
		s_data()->features++;
	}
}

static bool	__has_all_bonus_textures(t_textures *tex)
{
	return (tex->path[F] && tex->path[C] && tex->path[D]);
}

void	process_bonus_tex_lines(char *line, char *trimmed, t_textures *tex)
{
	int	id;

	id = get_other_id(trimmed);
	if (id < 0)
		return ;
	if (fill_bonus_tex_paths(trimmed, tex) == FAILURE)
	{
		free(line);
		get_next_line(s_data()->map->fd, true);
		exit_game(s_mlx(), FAILURE);
	}
	if (__has_all_bonus_textures(tex) && check_bonus_tex_paths(tex) == FAILURE)
	{
		free(line);
		get_next_line(s_data()->map->fd, true);
		exit_game(s_mlx(), FAILURE);
	}
	if (tex->imgs[id].img_ptr == NULL)
	{
		tex->imgs[id] = xpm_to_img(tex->path[id]);
		s_data()->features++;
	}
}
