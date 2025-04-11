/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_xpm_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:26:40 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/11 01:50:50 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_mandatory_tex_paths(t_textures *tex)
{
	if (check_xpm_file(tex->path[NO]) == FAILURE)
		return (FAILURE);
	if (check_xpm_file(tex->path[SO]) == FAILURE)
		return (FAILURE);
	if (check_xpm_file(tex->path[WE]) == FAILURE)
		return (FAILURE);
	if (check_xpm_file(tex->path[EA]) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	check_bonus_tex_paths(t_textures *tex)
{
	if (check_xpm_file(tex->path[F]) == FAILURE)
		return (FAILURE);
	if (check_xpm_file(tex->path[C]) == FAILURE)
		return (FAILURE);
	if (check_xpm_file(tex->path[D]) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	check_weapon_sprites_paths(t_weapon *w)
{
	int	i;

	i = 0;
	while (i < w->xpm_count)
	{
		if (check_xpm_file(w->sprites.path[i]) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
