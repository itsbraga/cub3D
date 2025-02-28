/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:09:30 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/28 21:10:13 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	free_tab(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i] != NULL)
	{
		free_and_set_null((void **)&tab[i]);
		i++;
	}
	free_and_set_null((void **)&tab);
}

void	free_title_screen(t_title_screen *screen)
{
	if (screen->bg_img.img_ptr != NULL)
		del_img(mlx_s(), screen->bg_img.img_ptr);
	if (screen->start_btn.img.img_ptr != NULL)
		del_img(mlx_s(), screen->start_btn.img.img_ptr);
}
