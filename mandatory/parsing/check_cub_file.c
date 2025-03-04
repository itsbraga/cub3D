/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:24:27 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 14:22:16 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// verifier si le fichier existe + permission apres avoir verifier l'extension
// si cub file est ok a 100% donner le fd du fichier ouvert dans data

bool	valid_ext(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (filename == '\0' || dot == '\0')
		return (false);
	else if (dot != '\0' && ft_strcmp(dot, ".cub") == 0)
		return (true);
	return (true);
}

// /*  La description de la carte sera toujours en dernier
//     dans le fichier, le reste des éléments peut être
//     dans n’importe quel ordre
// */
bool    valid_config(char **config)
{
    if (**config == '\0')
        return (err_msg(NULL, ERR_EMPTY, 0), false);
    if (ft_strchr("NOSOWEEA", **config) != NULL)
    {
        // func check texture
        // func check color code
        // func check map
    }
    else if (ft_strchr("FC", **config) != NULL)
    {
        // func check color code
        // func check texture
        // func check map
    }
    else
        return (err_msg(NULL, ERR_CONFIG, 0), false);
    return (true);
}

