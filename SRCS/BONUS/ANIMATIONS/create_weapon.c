/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:51:48 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/11 05:15:18 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	set_weapon_id(char *name)
{
	int			i;
	const char	*weapon_types[] = {
		"MP40", "GUN", "FLAMETHROWER", "FLASHLIGHT", "FIVE", "SIX",
		"SEVEN", "EIGHT", "NINE", "TEN", NULL};

	i = 0;
	while (weapon_types[i] != NULL)
	{
		if (ft_strncmp(name, weapon_types[i], ft_strlen(weapon_types[i])) == 0)
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
