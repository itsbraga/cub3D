/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:45:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/24 17:59:42 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static void	__draw_hline(t_mlx *mlx, t_point p0, t_point p1, int color)
{
	int i = 0;
	int y = 0;
	int dx = 0;
	int dy = 0;
	int dir = 0;
	int p = 0;
	
	if (p0.x > p1.x)
		swap_point(&p0, &p1);
	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	
	if (dy < 0)
		dir = -1;
	else
		dir = 1;
	dy *= dir;
	
	if (dx != 0)
	{
		y = p0.y;
		p = 2 * dy - dx;
		while (i <= dx)
		{
			my_pixel_put(mlx, color, p0.x + i, y);
			if (p >= 0)
			{
				y += dir;
				p = p - 2 * dx;
			}
			p = p + 2 * dy;
			i++;
		}
	}
	return ;
}

static void	__draw_vline(t_mlx *mlx, t_point p0, t_point p1, int color)
{
	int i = 0;
	int x = 0;
	int dx = 0;
	int dy = 0;
	int dir = 0;
	int p = 0;
	
	if (p0.y > p1.y)
		swap_point(&p0, &p1);
	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	
	if (dx < 0)
		dir = -1;
	else
		dir = 1;
	dx *= dir;
	
	if (dy != 0)
	{
		x = p0.x;
		p = 2 * dx - dy;
		while (i <= dy)
		{
			my_pixel_put(mlx, color, x, p0.y + i);
			if (p >= 0)
			{
				x += dir;
				p = p - 2*dy;
			}
			p = p + 2*dx;
			i++;
		}
	}
	return ;
}

void	draw_line_2d(t_mlx *mlx, t_point p0, t_point p1, int color)
{
	if (valid_point(p0, W_WIDTH, W_HEIGHT) == false
		|| valid_point(p1, W_WIDTH, W_HEIGHT) == false)
	{
		ft_printf(2, "Point called with %s is out of map !!\n", __func__);
		return ;
	}
	if (abs((int)p1.x-(int)p0.x) > abs((int)p1.y-(int)p0.y))
		__draw_hline(mlx, p0, p1, color);
	else
		__draw_vline(mlx, p0, p1, color);
}
