/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:51:48 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/16 15:05:41 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	set_weapon_id(char *name)
{
	int			i;
	const char	*typename[] = {"MP40", "GLOCK21", "FLAMETHROWER", NULL};

	i = 0;
	while (typename[i] != NULL)
	{
		if (ft_strncmp(name, typename[i], ft_strlen(typename[i])) == 0)
			return (i);
		i++;
	}
	return (-1);
}

t_weapon	*new_weapon(char *name)
{
	t_weapon	*new;
	char		*trimmed_name;

	new = yama(CREATE, NULL, sizeof(t_weapon));
	secure_malloc(new, true);
	ft_bzero(new, sizeof(t_weapon));
	trimmed_name = ft_strtrim(name, "\n");
	new->name = yama(ADD, ft_strdup(trimmed_name), 0);
	free_and_set_null((void **)&trimmed_name);
	new->id = set_weapon_id(name);
	new->state = IDLE;
	return (new);
}
