/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:24:27 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/07 13:09:03 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

// verifier si le fichier existe + permission apres avoir verifier l'extension
// si cub file est ok a 100% donner le fd du fichier ouvert dans data

static bool	__is_valid_extension(char *filename)
{
	char	*dot;

	if (filename == NULL)
		return (false);
	dot = ft_strrchr(filename, '.');
	if (dot == NULL)
		return (false);
	if (ft_strcmp(dot, ".cub") == 0)
		return (true);
	return (false);
}

static int	__is_not_directory(const char *path)
{
	int	fd;
	
	fd = open(path, __O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (FAILURE);
	}
	if (errno == EACCES)
		return (FAILURE);
	if (errno == ENOTDIR)
		return (SUCCESS);
	return (-1);
}

static void	__check_open_error(const char *arg)
{
	if (__is_not_directory(arg) != SUCCESS)
		err_msg(NULL, strerror(EISDIR));
	else if (errno == EACCES)
		err_msg(NULL, strerror(EACCES));
	else if (errno == ENOENT)
		err_msg(NULL, strerror(ENOENT));
	else
		err_msg(NULL, strerror(errno));
	exit(FAILURE);
}

int	check_file(char *arg)
{
	int	fd;

	if (__is_valid_extension(arg) == false)
	{
		err_msg(NULL, ERR_EXT);
		exit(FAILURE);
	}
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		__check_open_error(arg);
	return (fd);
}
