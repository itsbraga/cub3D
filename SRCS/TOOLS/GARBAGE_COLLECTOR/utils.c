/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:33:24 by pmateo            #+#    #+#             */
/*   Updated: 2024/12/02 18:33:35 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

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
	if (node->is_tab == true)
		return (free_gc_tab(yama, node->ptr));
	else
		return (remove_gc_node(yama, ptr));
}

int	free_gc_tab(t_gc_lst **y, char **tab)
{
	int	error;
	int	i;

	error = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		error = remove_gc_node(y, tab[i]);
		i++;
	}
	remove_gc_node(y, tab);
	return (error);
}
