/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/28 22:14:42 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_data(t_data *data)
{
	data->player.x = 800;
	data->player.y = 700;
	data->player_dir = SO;
	data->move.x = 0;
	data->move.y = 0;
	data->minimap_pos.x = 0;
	data->minimap_pos.y = 0;
	data->game_state = STATE_TITLE;
}

void	init_map(t_map *m, t_data *data)
{
	m->map2d = NULL;
	m->MAP_HEIGHT = 0;
	m->MAP_WIDTH = 0; 
	data->map = m;
}

void	init_raycast(t_raycast *ray, t_data *data)
{
	ray->ray_amount = WIN_WIDTH;
	ray->fov = 45;
	ray->player_rad = get_radian(data->player_dir);
	ray->h_offset.x = 0;
	ray->h_offset.y = 0;
	ray->v_offset.x = 0;
	ray->v_offset.y = 0;
	ray->h_ray_inter.x = 0;
	ray->h_ray_inter.y = 0;
	ray->v_ray_inter.x = 0;
	ray->v_ray_inter.y = 0;
	data->ray = ray;
}

void	init_keys(t_keys *k, t_data *data)
{
	ft_bzero(k->key_tab, 6);
	data->keys = k;
}

void	init_structs(t_data *data, t_mlx *mlx)
{
	init_data(data);
	init_mlx(mlx, data);
	if (init_title_screen(&data->title_screen) == FAILURE)
	{
		// err_msg("Title screen", "initialization failed", 0);
		printf("Title screen initialization failed, setting game state to GAME\n");
		data->game_state = STATE_GAME;
	}
	else
		printf("Title screen initialization OK\n");
	init_map(data->map, data);
	init_raycast(data->ray, data);
	init_keys(data->keys, data);
}
