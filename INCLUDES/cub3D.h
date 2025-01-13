/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:08:40 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/13 22:47:21 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../MLX/mlx.h"
# include "../LIBFT/INCLUDES/libft.h"
# include "../LIBFT/INCLUDES/ft_printf.h"
# include "structs.h"
# include "defines.h"
# include "tools.h"
# include "colors.h"

/******************************************************************************\
 * INIT
\******************************************************************************/

// init_structs.c
t_mlx	*mlx_s(void);
t_data	*data_s(void);
void	init_data(t_data *data);
void	init_mlx(t_mlx *mlx, t_data *data);

/******************************************************************************\
 * MATHS
\******************************************************************************/

// draw.c
void	draw_line(t_mlx *mlx, t_point p0, t_point p1, int color);
void	draw_player(t_mlx *mlx, t_point player);
//utils.c
void	init_point(t_point *point, int x, int y);

/******************************************************************************\
 * CONFIGS
\******************************************************************************/

// mlx_events.c
int	handle_keypress(int key, t_data *data);

// mlx_exit.c
void	del_win(t_mlx *mlx);
void	del_img(t_mlx *mlx);
int		clean(t_mlx *mlx);

#endif