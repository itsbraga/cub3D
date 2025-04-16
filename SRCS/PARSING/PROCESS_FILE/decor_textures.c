/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:47:23 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/09 13:43:34 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	__has_all_textures(t_textures *tex)
{
	return (tex->path[NO] && tex->path[SO] && tex->path[WE] && tex->path[EA]);
}

void	process_mandatory_tex_lines(char *line, t_textures *tex)
{
	if (fill_tex_paths(line, tex) == FAILURE)
		return ;
	if (__has_all_textures(tex) && check_mandatory_tex_paths(tex) == FAILURE)
		clean_exit(FAILURE);
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		tex->imgs[NO] = xpm_to_img(tex->path[NO]);
		s_data()->feature_filled++;
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		tex->imgs[SO] = xpm_to_img(tex->path[SO]);
		s_data()->feature_filled++;
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		tex->imgs[WE] = xpm_to_img(tex->path[WE]);
		s_data()->feature_filled++;
	}
	else
	{
		tex->imgs[EA] = xpm_to_img(tex->path[EA]);
		s_data()->feature_filled++;
	}
}

static bool	__has_all_bonus_textures(t_textures *tex)
{
	return (tex->path[F] && tex->path[C] && tex->path[D]);
}

void	process_bonus_tex_lines(char *line, t_textures *tex)
{
	if (fill_bonus_tex_paths(line, tex) == FAILURE)
		return ;
	if (__has_all_bonus_textures(tex) && check_bonus_tex_paths(tex) == FAILURE)
		clean_exit(FAILURE);
	if (line[0] == 'F')
	{
		tex->imgs[F] = xpm_to_img(tex->path[F]);
		s_data()->feature_filled++;
	}
	else if (line[0] == 'C')
	{
		tex->imgs[C] = xpm_to_img(tex->path[C]);
		s_data()->feature_filled++;
	}
	else if (line[0] == 'D')
	{
		tex->imgs[D] = xpm_to_img(tex->path[D]);
		s_data()->feature_filled++;
	}
}
