/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/09 17:38:43 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_map(t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	map->fd = -1;
}

void	init_game(t_game *game)
{
	game->state = TITLE_SCREEN;
	game->player_pos.x = 800; // a remplacer
	game->player_pos.y = 700; // a remplacer
// 	game->move.x = 0;
// 	game->move.y = 0;
}

void	init_raycasting(t_raycasting *ray, t_game *game)
{
	ray->ray_amount = WIN_WIDTH;
	ray->fov = 45;
	ray->player_rad = degree_to_radian(data_s()->player_dir);
	ray->h_offset.x = 0;
	ray->h_offset.y = 0;
	ray->v_offset.x = 0;
	ray->v_offset.y = 0;
	ray->h_ray_inter.x = 0;
	ray->h_ray_inter.y = 0;
	ray->v_ray_inter.x = 0;
	ray->v_ray_inter.y = 0;
	ray->dist_wall = 0;
	ray->vertical_hit = false;
	game->ray = ray;
}

void	init_keys(t_keys *keys, t_game *game)
{
	ft_bzero(keys->key_array, 6);
	game->keys = keys;
}

void	init_structs(t_data *data, t_game *game, t_mlx *mlx)
{
	init_map(data->map);
	ft_memset(game->player, 0, sizeof(t_player));
	init_game(game);
	init_mlx(mlx, game);
	init_title_screen(&game->title_screen);
	init_raycasting(game->ray, game);
	init_keys(game->keys, game);
}
