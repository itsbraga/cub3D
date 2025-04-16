/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:13:45 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/16 01:40:27 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	draw_weapon(int state, t_weapon *w, t_game *game)
{
	t_mlx	*mlx;

	mlx = game->mlx;
	my_put_img_to_window(&w->sprites.imgs[state], &mlx->img,
		w->pos.x, w->pos.y);
}
