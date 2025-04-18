/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 07:07:53 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 21:09:52 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_wall_id(char *line)
{
	const char	*ids[] = {"NO", "SO", "WE", "EA"};
	int			i;
	size_t		len;

	i = 0;
	while (i < 4)
	{
		len = ft_strlen(ids[i]);
		if (ft_strncmp(line, ids[i], len) == 0
			&& (line[len] == ' ' || line[len] == '\t'))
			return (i);
		i++;
	}
	err_msg(NULL, ERR_BAD_TEX_NAME);
	return (-1);
}

int	get_other_id(char *line)
{
	const char	*ids[] = {"F", "C", "D"};
	int			i;

	i = 0;
	while (i < 3)
	{
		if (ft_strncmp(line, ids[i], 1) == 0
			&& (line[1] == ' ' || line[1] == '\t'))
			return (i + F);
		i++;
	}
	err_msg(NULL, ERR_BAD_TEX_NAME);
	return (-1);
}
