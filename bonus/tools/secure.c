/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:58:48 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/28 21:12:01 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	secure_malloc(void *to_secure, bool cleanup)
{
	if (to_secure == NULL)
	{
		err_msg("malloc", strerror(errno), 0);
		if (cleanup == true)
			singletons_cleanup(FAILURE);
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
