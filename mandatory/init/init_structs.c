/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/04 02:37:23 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2025/03/03 20:15:05 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data(t_data *data)
{
	data->player_pos.x = 800; // a remplacer
	data->player_pos.y = 700; // a remplacer
	data->player_dir = SO; // a remplacer
	data->move.x = 0;
	data->move.y = 0;
}

void	init_map(t_map *m, t_data *data)
{
	m->map2d = NULL;
	m->height = 0;
	m->width = 0; 
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

void	init_keys(t_keys *keys, t_data *data)
{
	ft_bzero(keys->key_array, 6);
	data->keys = keys;
}

void	init_structs(t_data *data, t_mlx *mlx)
{
	init_data(data);
	init_mlx(mlx, data);
	init_map(data->map, data);
	init_raycast(data->ray, data);
	init_keys(data->keys, data);
}
