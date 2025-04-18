/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:15:56 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/17 20:16:44 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map_debug(t_map *map, const char *name)
{
	size_t	i;

	i = 0;
	printf(BOLD PINK "\n%s: " RESET, name);
	printf("[height = %zu, width = %zu]\n", map->size.height, map->size.width);
	printf(BOLD PG "Player position: [%f, %f]\n\n" RESET, \
		s_game()->player->pos.x, s_game()->player->pos.y);
	while (i < map->size.height)
	{
		printf("%s\n", map->map2d[i]);
		i++;
	}
	printf("\n");
}
