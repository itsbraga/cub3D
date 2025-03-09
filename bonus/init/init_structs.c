/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/10 00:30:01 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_map(t_map *map, char *path_to_file, int fd, t_data *data)
{
	map->path_to_file = yama(ADD, ft_strdup(path_to_file), 0);
	secure_malloc(map->path_to_file, true);
	map->fd = fd;
	map->map2d = NULL;
	map->height = 0;
	map->width = 0;
	data->map = map;
}

void	init_player(t_player *player, t_game *game)
{
	player->dir = 0;
	player->pos.x = 0;
	player->pos.y = 0;
	player->move.x = 0;
	player->move.y = 0;
	game->player = player;
}

void	init_raycasting(t_raycasting *ray, t_game *game)
{
	ray->ray_amount = WIN_WIDTH;
	ray->fov = 45;
	ray->player_rad = degree_to_radian(game_s()->player->dir);
	ray->h_offset.x = 0;
	ray->h_offset.y = 0;
	ray->v_offset.x = 0;
	ray->v_offset.y = 0;
	ray->h_ray_inter.x = 0;
	ray->h_ray_inter.y = 0;
	ray->v_ray_inter.x = 0;
	ray->v_ray_inter.y = 0;
	game->ray = ray;
}

void	init_keys(t_keys *keys, t_game *game)
{
	ft_bzero(keys->key_array, 6);
	game->keys = keys;
}

void	init_structs(t_game *game, t_mlx *mlx)
{
	init_player(game->player, game);
	init_mlx(mlx, game);
	init_title_screen(&game->title_screen);
	init_textures(data_s()->textures, data_s());
	init_raycasting(game->ray, game);
	init_keys(game->keys, game);
}
