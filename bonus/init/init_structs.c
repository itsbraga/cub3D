/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/07 14:09:07 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_map(t_map *map, char *file_path, int fd)
{
	map->file_path = yama(ADD, ft_strdup(file_path), 0);
	secure_malloc(map->file_path, true);
	map->fd = fd;
	map->map2d = NULL;
	map->height = 0;
	map->width = 0;
}

// void	init_game(t_game *game)
// {
// 	game->game_state = STATE_TITLE;
// 	game->player_pos.x = 800;
// 	game->player_pos.y = 700;
// 	game->move.x = 0;
// 	game->move.y = 0;
// }

void	init_raycast(t_raycast *ray, t_game *game)
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
	game->ray = ray;
}

void	init_keys(t_keys *keys, t_game *game)
{
	ft_bzero(keys->key_array, 6);
	game->keys = keys;
}

void	init_structs(t_data *data, t_game *game, t_mlx *mlx)
{
	// init_game(game);
	init_mlx(mlx, game);
	init_title_screen(&game->title_screen);
	init_raycast(game->ray, game);
	init_keys(game->keys, game);
}
