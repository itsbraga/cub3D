/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:35:52 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/06 15:43:53 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

float	degree_to_radian(int degree)
{
	return (degree * (M_PI / 180));
}

float	square(float to_square)
{
	float result;

	result = to_square * to_square;
	return (result);
}

float	norm_rad_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	else if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

float	norm_angle_h(float angle)
{
	if (angle < 0)
		angle += 360.0;
	else if (angle > 360.0)
		angle = fmod(angle, 360.0);
	return (angle);
}

float	norm_angle_v(float angle)
{
	if (angle < -MAX_PITCH)
		angle = -MAX_PITCH;
	else if (angle > MAX_PITCH)
		angle = MAX_PITCH;
	return (angle);
}
