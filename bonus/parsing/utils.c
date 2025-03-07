/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:20:42 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/07 16:45:21 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	convert_rgb_into_int(char *red, char *green, char *blue)
{
	int	r;
	int	g;
	int	b;
	int	result;

	result = 0;
	r = ft_atoi(red, &result);
	if (r < 0 || r > 255)
		(err_msg(NULL, ERR_RGB), exit(FAILURE)); // a voir si free qqch
	g = ft_atoi(green, &result);
	if (g < 0 || g > 255)
		(err_msg(NULL, ERR_RGB), exit(FAILURE)); // a voir si free qqch
	b = ft_atoi(blue, &result);
	if (b < 0 || b > 255)
		(err_msg(NULL, ERR_RGB), exit(FAILURE)); // a voir si free qqch
	result = (r << 16);
	result = result | (g << 8);
	result = result | (b);
	return (result);
}
