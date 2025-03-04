/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:20:42 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/04 18:34:09 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	rgb_to_int(char *red, char *green, char *blue)
{
	int	r;
	int	g;
	int	b;
	int	result;

	result = 0;
	r = ft_atoi(red, &result);
	g = ft_atoi(green, &result);
	b = ft_atoi(blue, &result);
	result = (r << 16);
	result = result | (g << 8);
	result = result | (b);
	return (result);
}
