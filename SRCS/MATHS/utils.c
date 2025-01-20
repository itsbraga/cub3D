/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:35:52 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/20 18:56:15 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_point(t_point *point, double x, double y)
{
	point->x = x;
	point->y = y;
	return ;
}

double	get_radian(int degree)
{
	return (degree * (M_PI / 180));
}