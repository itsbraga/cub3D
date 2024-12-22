/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:30:51 by pmateo            #+#    #+#             */
/*   Updated: 2024/12/02 19:31:31 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "cub3D.h"

/******************************************************************************\
 * TOOLS
\******************************************************************************/

//init_structs.c
t_mlx   *mlx_s(void);

// errmsg.c
void	err_msg(char *detail, char *reason);
int		err_msg_cmd(char *cmd, char *detail, char *reason, int err_no);

// secure.c
void	secure_malloc(void *to_secure, bool cleanup);
void	free_and_set_null(void **to_free);

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

// garbage_collector.c
void	*yama(int flag, void *ptr, size_t size);


#endif