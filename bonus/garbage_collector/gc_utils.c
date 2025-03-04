/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:33:24 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/03 20:15:05 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	*search_ptr(t_gc_lst **yama, void *ptr)
{
	t_gc_lst	*curr;

	curr = *yama;
	while (curr != NULL)
	{
		if (curr->ptr == ptr)
			return (curr->ptr);
		curr = curr->next;
	}
	return (NULL);
}

int	handle_remove(t_gc_lst **yama, void *ptr)
{
	t_gc_lst	*node;

	node = *yama;
	while (node->ptr != ptr)
		node = node->next;
	if (node->is_array == true)
		return (free_gc_array(yama, node->ptr));
	else
		return (remove_gc_node(yama, ptr));
}

int	free_gc_array(t_gc_lst **y, char **array)
{
	int	error;
	int	i;

	error = 0;
	i = 0;
	while (array[i] != NULL)
	{
		error = remove_gc_node(y, array[i]);
		i++;
	}
	remove_gc_node(y, array);
	return (error);
}
