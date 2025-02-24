/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:01:31 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/24 20:45:42 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*	SINGLETON
	
	ensures a class or structure has only one instance
	and provides a global access point to it
*/
t_data	*data_s(void)
{
	static t_data	*instance = NULL;

	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_data));
		secure_malloc(instance, true);
		instance->map_path = NULL;
		instance->map = yama(CREATE, NULL, sizeof(t_map));
		secure_malloc(instance->map, true);
		instance->ray = yama(CREATE, NULL, sizeof(t_ray));
		secure_malloc(instance->ray, true);
		ft_bzero(instance->texture, 4);
		ft_bzero(instance->f_rgb, 3);
		ft_bzero(instance->c_rgb, 3);
		instance->mlx = NULL;
		instance->game = yama(CREATE, NULL, sizeof(t_game));
		secure_malloc(instance->game, true);
		instance->keys = yama(CREATE, NULL, sizeof(t_keys));
		secure_malloc(instance->keys, true);
		instance->minimap = yama(CREATE, NULL, sizeof(t_minimap));
		secure_malloc(instance->minimap, true);
	}
	return (instance);
}

t_mlx	*mlx_s(void)
{
	static t_mlx	*instance = NULL;
	
	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_mlx));
		secure_malloc(instance, true);
		instance->mlx_ptr = NULL;
		instance->win_ptr = NULL;
		instance->img_ptr = NULL;
		instance->img_buff = NULL;
		instance->bpp = 0;
		instance->line_len = 0;
		instance->endian = 0;
	}
	return (instance);
}

void	init_data(t_data *data)
{
	data->player.x = 800;
	data->player.y = 700;
	data->player_dir = SO;
	data->move.x = 0;
	data->move.y = 0;
}

void	init_mlx(t_mlx *mlx, t_data *data)
{
	char	*win_title;

	win_title = "Telecubies zombies";
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		(err_msg("MLX", ERR_MLX, 0), clean_structs(FAILURE));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_WIDTH, W_HEIGHT, win_title);
	if (mlx->win_ptr == NULL)
		(err_msg("MLX", ERR_MLX, 0), del_win(mlx));
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (mlx->img_ptr == NULL)
		(err_msg("MLX", ERR_MLX, 0), del_img(mlx));
	mlx->img_buff = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, 
			&mlx->line_len, &mlx->endian);
	if (mlx->img_buff == NULL)
		(err_msg("MLX", ERR_MLX, 0), clean_structs(FAILURE));
	data->mlx = mlx;
}
