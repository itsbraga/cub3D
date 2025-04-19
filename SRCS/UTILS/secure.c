/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:58:48 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/19 02:54:21 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	secure_singleton(void *to_secure)
{
	if (to_secure == NULL)
		exit(FAILURE);
}

void	secure_malloc(void *to_secure, bool full_clean)
{
	if (to_secure == NULL)
	{
		err_msg("malloc", strerror(errno));
		if (full_clean == true)
			exit_game(s_mlx(), FAILURE);
	}
}

void	free_and_set_null(void **to_free)
{
	if (to_free != NULL && (*to_free) != NULL)
	{
		free(*to_free);
		*to_free = NULL;
	}
}
