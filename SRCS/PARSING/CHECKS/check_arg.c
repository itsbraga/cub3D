/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:24:27 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/19 02:55:40 by annabrag         ###   ########.fr       */
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
	if (ft_strncmp(filename + (len - 4), ".cub", 4) != 0)
		return (false);
	return (true);
}

int	check_cub_file(char *arg)
{
	int	fd;

	if (__is_valid_extension(arg) == false)
	{
		err_msg(NULL, ERR_CUB_EXT);
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
