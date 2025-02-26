/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:59:14 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/26 20:35:24 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_structs(t_data *data, t_mlx *mlx)
{
	init_data(data);
	init_mlx(mlx, data);
	init_map(data->map, data);
	init_ray(data->ray, data);
	init_keys(data->keys, data);
	init_game(data->game, data);
	init_minimap(data->minimap, data);
}
