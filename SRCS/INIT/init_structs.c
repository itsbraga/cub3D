/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/14 21:46:09 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*	SINGLETON (data_s() & mlx_s())
	
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
	}
	return (instance);
}

void	init_data(t_data *data)
{
	data->player.x = 160;
	data->player.y = 80;
	data->player_dir = WE;
	data->move_x = 0;
	data->move_y = 0;
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

void	init_mlx(t_mlx *mlx, t_data *data)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		(err_msg("MLX", ERR_MLX, 0), clean_exit(FAILURE));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_WIDTH, W_HEIGHT, "kub");
	if (mlx->win_ptr == NULL)
		(err_msg("MLX", ERR_MLX, 0), clean_exit(FAILURE));
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (mlx->img_ptr == NULL)
		(err_msg("MLX", ERR_MLX, 0), clean_exit(FAILURE));
	mlx->img_buff = (char *)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->line_len,
					&mlx->endian);
	if (mlx->img_buff == NULL)
		(err_msg("MLX", ERR_MLX, 0), clean_exit(FAILURE));
	data->mlx = mlx;
}

t_data	*data_s(void)
{
	static t_data	*instance = NULL;

	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_data));
		secure_malloc(instance, true);
		instance->map_path = NULL;
		ft_bzero(instance->texture, 4);
		ft_bzero(instance->f_rgb, 3);
		ft_bzero(instance->c_rgb, 3);
	}
	return (instance);
}

void	init_map(t_map *m, t_data *data)
{
	m->map2d = NULL;
	m->M_HEIGHT = 0; // MAP
	m->M_WIDTH = 0; 
	data->map = m;
}

void	init_kevent(t_data *data, t_kevent *k)
{
	(void)data;
	ft_bzero(k->key_tab, 6);
}

void	init_ray(t_data *data, t_ray *ray)
{
	ray->ray_amount = W_WIDTH;
	ray->fov = 60;
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
