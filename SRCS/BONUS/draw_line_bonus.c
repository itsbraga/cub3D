/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:04:48 by pmateo            #+#    #+#             */
/*   Updated: 2025/02/21 21:21:54 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__swap_point(t_point *p0, t_point *p1)
{
	t_point tmp;

	tmp.x = p1->x;
	tmp.y = p1->y;
	p1->x = p0->x;
	p1->y = p0->y;
	p0->x = tmp.x;
	p0->y = tmp.y;
}

// static bool	__valid_point(t_point point)
// {
// 	if (point.x > (W_WIDTH / 4) || point.x < 0)
// 		return (false);
// 	if (point.y > (W_HEIGHT / 4) || point.y < 0)
// 		return (false);
// 	return (true);
// }

// static void	__draw_hline(t_mlx *mlx, t_point p0, t_point p1, int color)
// {
// 	int i = 0;
// 	int y = 0;
// 	int dx = 0;
// 	int dy = 0;
// 	int dir = 0;
// 	int p = 0;
	
// 	if (p0.x > p1.x)
// 		__swap_point(&p0, &p1);
// 	dx = p1.x - p0.x;
// 	dy = p1.y - p0.y;
	
// 	if (dy < 0)
// 		dir = -1;
// 	else
// 		dir = 1;
// 	dy *= dir;
	
// 	if (dx != 0)
// 	{
// 		y = p0.y;
// 		p = 2 * dy - dx;
// 		while (i <= dx)
// 		{
// 			my_pixel_put(mlx, color, ((p0.x + i) / 2), (y / 2));
// 			if (p >= 0)
// 			{
// 				y += dir;
// 				p = p - 2 * dx;
// 			}
// 			p = p + 2 * dy;
// 			i++;
// 		}
// 	}
// 	return ;
// }

// static void	__draw_vline(t_mlx *mlx, t_point p0, t_point p1, int color)
// {
// 	int i = 0;
// 	int x = 0;
// 	int dx = 0;
// 	int dy = 0;
// 	int dir = 0;
// 	int p = 0;
	
// 	if (p0.y > p1.y)
// 		__swap_point(&p0, &p1);
// 	dx = p1.x - p0.x;
// 	dy = p1.y - p0.y;
	
// 	if (dx < 0)
// 		dir = -1;
// 	else
// 		dir = 1;
// 	dx *= dir;
	
// 	if (dy != 0)
// 	{
// 		x = p0.x;
// 		p = 2 * dx - dy;
// 		while (i <= dy)
// 		{
// 			my_pixel_put(mlx, color, (x / 2), ((p0.y + i) / 2));
// 			if (p >= 0)
// 			{
// 				x += dir;
// 				p = p - 2*dy;
// 			}
// 			p = p + 2*dx;
// 			i++;
// 		}
// 	}
// 	return ;
// }

static bool	__valid_point(t_point point)
{
	if (point.x > W_WIDTH || point.x < 0)
		return (false);
	if (point.y > W_HEIGHT || point.y < 0)
		return (false);
	return (true);
}

static void	__draw_hline(t_mlx *mlx, t_point p0, t_point p1, int color)
{
	int i = 0;
	int y = 0;
	int dx = 0;
	int dy = 0;
	int dir = 0;
	int p = 0;
	
	if (p0.x > p1.x)
		__swap_point(&p0, &p1);
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
		__swap_point(&p0, &p1);
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

void	draw_line_bonus(t_mlx *mlx, t_point p0, t_point p1, int color)
{
	if (__valid_point(p0) == false || __valid_point(p1) == false)
	{
		ft_printf(2, "Point called with %s is out of map !!\n", __func__);
		return ;
	}
	if (abs((int)p1.x-(int)p0.x) > abs((int)p1.y-(int)p0.y))
		__draw_hline(mlx, p0, p1, color);
	else
		__draw_vline(mlx, p0, p1, color);
}
