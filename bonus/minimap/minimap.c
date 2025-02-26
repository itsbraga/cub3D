/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:51:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/26 21:16:41 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	__draw_tile(t_data *data, t_point tile)
{
	t_point	pixel;
	size_t	x_end;
	size_t	y_end;

	pixel.x = tile.x * (TILE_SIZE / 3);
	pixel.y = tile.y * (TILE_SIZE / 3);
	x_end = pixel.x + (TILE_SIZE / 3);
	y_end = pixel.y + (TILE_SIZE / 3);
	while (pixel.y < y_end)
	{
		pixel.x = tile.x * (TILE_SIZE / 3);
		while (pixel.x < x_end)
		{
			my_pixel_put(data->mlx, WHITE_PIX, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

static void	__draw_minimap(t_data *data, t_map *mini)
{
	t_point	tile;

	// FIRST CALL: MAP2D CREATION
	get_map_info(mini);
	tile.y = 0;
	while (tile.y < mini->M_HEIGHT)
	{
		tile.x = 0;
		while (tile.x < mini->M_WIDTH)
		{
			if (mini->map2d[(int)tile.y][(int)tile.x] == '1')
				__draw_tile(data, tile);
			tile.x++;
		}
		tile.y++;
	}
}

int	render_minimap(t_data *data, t_minimap *mini)
{
	t_mlx	*mlx;
	void	*main_img;
	char	*main_buff;
	
	mlx = mlx_s();

	clear_window(mlx, WIN_WIDTH, WIN_HEIGHT, BLACK_PIX);
	// SECOND CALL: MAP2D CREATION ----> WARNING!
	get_map_info(data->map);
	raycasting(data, data->ray);
	
	main_img = mlx->img_ptr;
	main_buff = mlx->img_buff;

	mini->img_ptr = mlx_new_image(mlx->mlx_ptr, (WIN_WIDTH / 3), (WIN_HEIGHT / 3));
	if (mini->img_ptr == NULL)
		return (err_msg("MLX", ERR_MLX, 0), FAILURE);
	mini->img_buff = mlx_get_data_addr(mini->img_ptr, &mlx->bpp,
		&mlx->line_len, &mlx->endian);
	if (mini->img_buff == NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, mini->img_ptr);
		return (err_msg("MLX", ERR_MLX, 0), FAILURE);
	}
	mlx->img_ptr = mini->img_ptr;
	mlx->img_buff = mini->img_buff;
	
	clear_window(mlx, (WIN_WIDTH / 3), (WIN_HEIGHT / 3), LAVENDER_PIX);
	__draw_minimap(data, data->map);
	draw_miniplayer(mlx, data, data->player);

	mlx->img_ptr = main_img;
	mlx->img_buff = main_buff;

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		main_img, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mini->img_ptr, 10, 10);

	mlx_destroy_image(mlx->mlx_ptr, mini->img_ptr);

	return (SUCCESS);
}
