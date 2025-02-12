/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:09:46 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/11 19:36:27 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3D.h"

// check_map.c
bool    first_verification(char **map, int rows, t_point *start);

// check_map2.c


// check_rgb.c
bool	valid_rgb(unsigned int rgb[3]);

// check_cub_file.c


#endif