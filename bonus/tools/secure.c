/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:58:48 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/20 14:33:11 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	secure_malloc(void *to_secure, bool cleanup)
{
	if (to_secure == NULL)
	{
		err_msg("malloc", strerror(errno), 0);
		if (cleanup == true)
			clean_structs(FAILURE);
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
