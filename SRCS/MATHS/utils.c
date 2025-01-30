/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:35:52 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/29 18:28:19 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_point(t_point *point, float x, float y)
{
	point->x = x;
	point->y = y;
	return ;
}

bool	is_point_valid(t_point point)
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