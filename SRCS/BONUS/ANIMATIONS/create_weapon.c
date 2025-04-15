/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:51:48 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/15 19:23:03 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	set_weapon_id(char *name)
{
	int			i;
	const char	*typename[] = {"MP40", "ENFORCER_PISTOL", "FLAMETHROWER", NULL};

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

	new = yama(CREATE, NULL, sizeof(t_weapon));
	secure_malloc(new, true);
	ft_bzero(new, sizeof(t_weapon));
	new->name = yama(ADD, ft_strdup(ft_strtrim(name, "\n")), 0);
	new->id = set_weapon_id(name);
	printf("DEBUG WEAPON: new->name = %s\n", new->name);
	printf("DEBUG WEAPON: new->id = %d\n", new->id);
	new->state = IDLE;
	return (new);
}
