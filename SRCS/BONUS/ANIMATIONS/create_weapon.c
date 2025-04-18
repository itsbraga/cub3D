/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:51:48 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/18 18:39:42 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	set_weapon_id(char *name)
{
	int			i;
	const char	*typename[] = {"MP40", "GLOCK21", "STUNNER", NULL};

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

	new = malloc(sizeof(t_weapon));
	secure_malloc(new, true);
	ft_bzero(new, sizeof(t_weapon));
	trimmed_name = ft_strtrim(name, "\n");
	new->name = ft_strdup(trimmed_name);
	new->id = set_weapon_id(name);
	new->state = IDLE;
	free_and_set_null((void **)&trimmed_name);
	return (new);
}
