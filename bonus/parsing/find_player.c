/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:43:21 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/07 13:43:32 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	find_player_position(t_map *map, t_player *player)
{
	size_t	i;
	size_t	j;
	size_t	line_len;
	int		player_count;

	i = 0;
	player_count = 0;
	while (i < map->height)
	{
		line_len = ft_strlen(map->map2d[i]);
		j = 0;
		while (j < line_len)
		{
			if (ft_strchr(PLAYER_DIR, map->map2d[i][j]) != NULL)
			{
				player->pos.x = (float)j;
				player->pos.y = (float)i;
				player->dir = map->map2d[i][j];
				player_count++;
			}
			j++;
		}
		i++;
	}
	if (player_count == 0)
		return (err_msg(NULL, ERR_PLAYER));
	if (player_count > 1)
		return (err_msg(NULL, ERR_NB_PLAYER));
}
