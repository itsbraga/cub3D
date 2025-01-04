/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:24:27 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/04 19:38:50 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*  La description de la carte sera toujours en dernier
    dans le fichier, le reste des éléments peut être
    dans n’importe quel ordre
*/
bool    is_valid_cubfile(char **config)
{
    if (**config == '\0')
        return (err_msg(NULL, ERR_CONFIG, 0), false);
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
        return (err_msg(NULL, ERR_EMPTY, 0), false);
    return (true);
}

