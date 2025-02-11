/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:09:25 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/11 19:36:27 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	valid_rgb(unsigned int rgb[3])
{
	int	i;

	i = 0;
	while (rgb[i] != '\0')
	{
		if (rgb[i] > 255 || rgb[i] < 0)
			return (false);
		i++;
	}
	return (true);
}