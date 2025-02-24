/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/24 20:09:49 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_map(t_map *m, t_data *data)
{
	m->map2d = NULL;
	m->M_HEIGHT = 0; // MAP
	m->M_WIDTH = 0; 
	data->map = m;
}

void	init_ray(t_ray *ray, t_data *data)
{
	ray->ray_amount = W_WIDTH;
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

void	init_game(t_game *game, t_data *data)
{
	game->game_state = STATE_TITLE;
	game->button.x = 300;
	game->button.y = 400;
	game->width = W_WIDTH;
	game->height = W_HEIGHT;
	data->game = game;
}

void	init_minimap(t_minimap *mini, t_data *data)
{
	mini->img_ptr = NULL;
	mini->img_buff = NULL;
	data->minimap = mini;
}
