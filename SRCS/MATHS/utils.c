/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:35:52 by pmateo            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/07 00:17:42 by pmateo           ###   ########.fr       */
=======
/*   Updated: 2025/02/11 19:36:27 by annabrag         ###   ########.fr       */
>>>>>>> 3dbbc232b03eb618ea312caa03c51d253e17a066
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_point(t_point *point, float x, float y)
{
	point->x = x;
	point->y = y;
}

bool	valid_point(t_point point)
{
	if (point.x > W_WIDTH || point.x < 0)
		return (false);
	if (point.y > W_HEIGHT || point.y < 0)
		return (false);
	return (true);
}

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