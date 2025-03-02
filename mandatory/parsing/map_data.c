/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:53:59 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/02 17:37:35 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//recupere le fd du fichier cub, le traite, et le ferme

char **get_all_xpm_paths(int fd)
{
	int i;
	char **tab;
	char *curr;
	
	i = 0;
	tab = malloc(4 * sizeof(char *));
	curr = NULL;
	secure_malloc(tab, true);
	while (i < 4)
	{
		curr = get_next_line(fd, false);
		secure_malloc(tab, true);
		tab[i] = ft_substr(ft_strchr(curr, '.'), 0, ft_strlen_gnl(curr, 0) - 1);
		printf("pathtex_tab[%d] = %s\n", tab[i]);
		free(curr);
		i++;
	}
	return (tab);
}

int *get_textures(t_data *data, int fd)
{
	char **xpm_path_tab;
	
	xpm_path_tab = get_all_xpm_paths(fd);
	data->texture = malloc(4 * sizeof(int *));
	secure_malloc(data->texture, true);
	
}

unsigned int	rgb_to_int(char *red, char *green, char *blue)
{
	
}

void    get_map_data(t_data *data)
{
	get_textures(data, data->fd);
}
