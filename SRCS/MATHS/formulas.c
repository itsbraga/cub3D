/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:35:52 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/16 23:28:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	get_radian(int degree)
{
	return (degree * (PI / 180));
}

float	square(float to_square)
{
	float result;

	result = to_square * to_square;
	return (result);
}

float	norm_angle(float angle)
{

	if (angle < 0)
		angle += (2 * PI);
	else if (angle > (2 * PI))
		angle -= (2 * PI);
	return (angle);
}
