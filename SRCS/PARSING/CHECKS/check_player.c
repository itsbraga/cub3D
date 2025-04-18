/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:43:21 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/18 18:21:23 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__set_player_direction(char c, t_player *p)
{
	if (c == 'N')
		return (p->dir = N);
	else if (c == 'S')
		return (p->dir = S);
	else if (c == 'E')
		return (p->dir = E);
	else
		return (p->dir = W);
}

static void	__set_player_pos(t_player *p, size_t j, size_t i, char dir)
{
	p->pos.x = (float)j + 0.5;
	p->pos.y = (float)i + 0.5;
	p->dir = __set_player_direction(dir, p);
}

static bool	__found_player(char *line, t_player *p, size_t i)
{
	size_t	line_len;
	size_t	j;

	line_len = ft_strlen(line);
	j = 0;
	while (j < line_len)
	{
		if (ft_strchr("NSEW", line[j]) != NULL)
		{
			__set_player_pos(p, j, i, line[j]);
			return (true);
		}
		j++;
	}
	return (false);
}

void	find_player_start_pos(t_map *map, t_player *p)
{
	size_t	i;
	bool	player_found;

	player_found = false;
	i = 0;
	while (i < map->size.height)
	{
		if (__found_player(map->map2d[i], p, i) == true)
		{
			player_found = true;
			break ;
		}
		i++;
	}
	if (player_found == false)
	{
		err_msg(NULL, ERR_NO_PLAYER);
		exit_game(s_mlx(), FAILURE);
	}
	p->pos.x *= TILE_SIZE;
	p->pos.y *= TILE_SIZE;
	s_game()->player = p;
}
