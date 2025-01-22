/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/22 03:57:57 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// singleton version
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

void	init_map(t_map *s, t_data *data)
{
	s->map = NULL;
	s->M_HEIGHT = 0; //MAP
	s->M_WIDTH = 0; 
	s->T_HEIGHT = 0; //TILES
	s->T_WIDTH = 0;
	data->map = s;
}

void	init_data(t_data *data)
{
	
	data->map_path = NULL;
	data->map = NULL;
	ft_bzero(data->texture, 4);
	ft_bzero(data->f_rgb, 3);
	ft_bzero(data->c_rgb, 3);
	data->player.x = W_WIDTH / 2;
	data->player.y = W_HEIGHT / 2;
	data->player_dir = WE;
	data->mlx = NULL;
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
