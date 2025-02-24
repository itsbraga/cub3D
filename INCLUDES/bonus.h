/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:58:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/24 20:10:23 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "cub3D.h"

// collisions.c
int		avoid_collisions(t_data *data, t_point *new_player);

/******************************************************************************\
 * MINIMAP
\******************************************************************************/

// draw_line_bonus.c
void	draw_line_bonus(t_mlx *mlx, t_point p0, t_point p1, int color);

// draw_miniplayer.c
void	draw_miniplayer(t_mlx *mlx, t_data *data, t_point player);

// minimap.c
int		render_minimap(t_data *data, t_minimap *mini);

#endif