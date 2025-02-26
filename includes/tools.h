/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:30:51 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/24 21:06:51 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "cub3D.h"

/******************************************************************************\
 * TOOLS
\******************************************************************************/

// error.c
void	err_msg(char *detail, char *reason, int quotes);
int		err_msg_cmd(char *cmd, char *detail, char *reason, int err_no);

// cleanup.c
void	free_tab(char **tab);
void	clean_structs(int exit_status);

// secure.c
void	secure_malloc(void *to_secure, bool cleanup);
void	free_and_set_null(void **to_free);

// draw_tools.c
void	swap_point(t_point *p0, t_point *p1);
bool	valid_point(t_point point, size_t win_x, size_t win_y);

// pixels.c
void	my_pixel_put(t_mlx *mlx, int color, int x, int y);
void	clear_window(t_mlx *mlx, size_t size_x, size_t size_y, int color);

/******************************************************************************\
 * GARBAGE_COLLECTOR
\******************************************************************************/
 
// lst_utils.c
int		remove_gc_node(t_gc_lst**yama, void *ptr);
void	add_gc_node(t_gc_lst **yama, t_gc_lst *node);
void	*new_gc_node(void *ptr, bool is_tab);
 
// utils.c
void	*search_ptr(t_gc_lst **yama, void *ptr);
int		handle_remove(t_gc_lst **yama, void *ptr);
int		free_gc_tab(t_gc_lst **y, char **tab);
 
// garbage_collector.c
void	*yama(int flag, void *ptr, size_t size);
 
/******************************************************************************\
 * 2D_DEBUG
\******************************************************************************/
  
// draw_grid.c
void	draw_grid(t_mlx *mlx);
  
// draw_line.c
void	draw_line_2d(t_mlx *mlx, t_point p0, t_point p1, int color);

// draw_player.c
void	draw_player(t_mlx *mlx, t_data *data, t_point player);

// debug.c
int		render_2d(t_data *data);
  
#endif