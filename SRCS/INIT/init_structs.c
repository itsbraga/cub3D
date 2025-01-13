/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/04 20:44:14 by art3mis          ###   ########.fr       */
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
		instance->map= NULL;
		ft_bzero(instance->texture, 4);
		ft_bzero(instance->f_rgb, 3);
		ft_bzero(instance->c_rgb, 3);
	}
	return (instance);
}

void	init_data(t_data *data)
{
	data->map_path = NULL;
	data->map = NULL;
	ft_bzero(data->texture, 4);
	ft_bzero(data->f_rgb, 3);
	ft_bzero(data->c_rgb, 3);
	data->mlx = NULL;
}

void	init_mlx(t_mlx *mlx, t_data *data)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		(err_msg("MLX", ERR_MLX, 0), clean_exit(FAILURE));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "kub");
	if (mlx->win_ptr == NULL)
		(err_msg("MLX", ERR_MLX, 0), clean_exit(FAILURE));
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (mlx->img_ptr == NULL)
		(err_msg("MLX", ERR_MLX, 0), clean_exit(FAILURE));
	mlx->img_buff = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->line_len,
					&mlx->endian);
	if (mlx->img_buff == NULL)
		(err_msg("MLX", ERR_MLX, 0), clean_exit(FAILURE));
	data->mlx = mlx;
}
