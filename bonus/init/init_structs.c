/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/04 19:15:09 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_game(t_game *game)
{
	game->game_state = STATE_TITLE;
	game->player_pos.x = 800;
	game->player_pos.y = 700;
	game->move.x = 0;
	game->move.y = 0;
	game->minimap_pos.x = 0;
	game->minimap_pos.y = 0;
}

void	init_map(t_map *m, t_game *game)
{
	m->map2d = NULL;
	m->height = 0;
	m->width = 0; 
	game->map = m;
}

void	init_raycast(t_raycast *ray, t_game *game)
{
	ray->ray_amount = WIN_WIDTH;
	ray->fov = 45;
	ray->player_rad = get_radian(data_s()->player_dir);
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
	init_game(game);
	init_mlx(mlx, game);
	init_title_screen(&game->title_screen);
	init_map(game->map, game);
	init_raycast(game->ray, game);
	init_keys(game->keys, game);
}
