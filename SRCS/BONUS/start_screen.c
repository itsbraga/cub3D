/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:48:41 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/24 18:33:27 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__draw_start_button(t_mlx *mlx, t_game *game)
{
	int		button_width;
	int		button_height;
	t_point	pixel;
	
	button_width = 200;
	button_height = 50;
	pixel.y = game->button.y;
	while (pixel.y < (game->button.y + button_height))
	{
		pixel.x = game->button.x;
		while (pixel.x < (game->button.x + button_width))
		{
			my_pixel_put(mlx, HRED, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

void	draw_start_screen(t_mlx *mlx, t_game *game)
{
	void	*tmp_bg_img = NULL;
	void	*tmp_button_img;
	char	*button_buff;
	t_mlx	*tmp_mlx;

	clear_window(mlx, W_WIDTH, W_HEIGHT, HBLACK);
	tmp_mlx = mlx;

	// Créer une image temporaire pour le fond
	tmp_bg_img = mlx_xpm_file_to_image(mlx->mlx_ptr, START_SCREEN,
			&game->width, &game->height);
	printf("tmp_bg_img = %p\n", tmp_bg_img);
	printf("##DEBUG 1 ##\n");
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, tmp_bg_img, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, tmp_bg_img);
	printf("##DEBUG 2 ##\n");

	// Créer une image temporaire pour le bouton
	tmp_button_img = mlx_new_image(mlx->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (tmp_button_img == NULL)
		(err_msg("MLX", ERR_MLX, 0), del_img(mlx));
	printf("##DEBUG 3 ##\n");

	button_buff = mlx_get_data_addr(tmp_button_img, &mlx->bpp, &mlx->line_len,
			&mlx->endian);
	if (button_buff == NULL)
		(err_msg("MLX", ERR_MLX, 0), clean_structs(FAILURE));
	printf("##DEBUG 4 ##\n");

	tmp_mlx->mlx_ptr = mlx->mlx_ptr;
	tmp_mlx->win_ptr = mlx->win_ptr;
	tmp_mlx->img_ptr = tmp_button_img;
	tmp_mlx->img_buff = button_buff;
	tmp_mlx->bpp = mlx->bpp;
	tmp_mlx->line_len = mlx->line_len;
	tmp_mlx->endian = mlx->endian;
	printf("##DEBUG 5 ##\n");

	__draw_start_button(tmp_mlx, game);
	printf("##DEBUG 6 ##\n");

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, tmp_button_img, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, tmp_button_img);
}
