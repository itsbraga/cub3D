/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:09:28 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/18 18:54:11 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render_frame(t_game *g)
{
	t_mlx	*mlx;
	t_data	*d;

	mlx = g->mlx;
	d = g->data;
	if (g->state == TITLE_SCREEN)
		draw_title_screen(g, mlx);
	else if (g->state == GAME)
	{
		move_player(g, g->keys);
		reset_move(g->player);
		clear_img(&mlx->img, WIN_WIDTH, WIN_HEIGHT, GRAY_PIX);
		raycasting(d, g->player, g->ray);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img.img_ptr, 0, 0);
		if (BONUS)
		{
			handle_doors(d->door_nb, d->doors);
			render_minimap(g, g->mmap);
			if (d->weapon_count > 0)
				render_curr_weapon(g);
		}
	}
	return (SUCCESS);
}
