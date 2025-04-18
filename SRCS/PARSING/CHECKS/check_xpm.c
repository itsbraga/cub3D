/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:26:18 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 07:06:08 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	__is_valid_extension(char *filename)
{
	size_t	len;

	if (filename == NULL)
		return (false);
	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	if (ft_strncmp(filename + (len - 4), ".xpm", 4) != 0)
		return (false);
	return (true);
}

static int	__check_xpm_file(char *arg)
{
	int	fd;

	if (__is_valid_extension(arg) == false)
	{
		err_msg(NULL, ERR_XPM_EXT);
		return (FAILURE);
	}
	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		err_msg(NULL, strerror(errno));
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

int	check_wall_tex_paths(t_textures *tex)
{
	if (__check_xpm_file(tex->path[NO]) == FAILURE)
		return (FAILURE);
	if (__check_xpm_file(tex->path[SO]) == FAILURE)
		return (FAILURE);
	if (__check_xpm_file(tex->path[WE]) == FAILURE)
		return (FAILURE);
	if (__check_xpm_file(tex->path[EA]) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	check_bonus_tex_paths(t_textures *tex)
{
	if (__check_xpm_file(tex->path[F]) == FAILURE)
		return (FAILURE);
	if (__check_xpm_file(tex->path[C]) == FAILURE)
		return (FAILURE);
	if (__check_xpm_file(tex->path[D]) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	check_weapon_sprites_paths(t_weapon *w)
{
	int	i;

	i = 0;
	while (i < w->xpm_count)
	{
		if (__check_xpm_file(w->sprites.path[i]) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
