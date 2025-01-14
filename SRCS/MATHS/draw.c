/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:41:54 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/14 23:15:04 by pmateo           ###   ########.fr       */
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

static void	draw_h_line(t_mlx *mlx, t_point p0, t_point p1, int color)
{
	int i = 0;
	int y = 0;
	int dx = 0;
	int dy = 0;
	int dir = 0;
	int p = 0;
	printf("%s\n", __func__);
	if (p0.x > p1.x)
		__swap_point(&p0, &p1);
	printf("1\n");
	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	if (dy < 0)
		dir = -1;
	else
		dir = 1;
	dy *= dir;
	printf("2\n");
	if (dx != 0)
	{
		y = p0.y;
		p = 2*dy - dx;
		printf("3\n");
		while (i <= dx)
		{
			my_pixel_put(mlx, color, p0.x + i, y);
			printf("4\n");
			if (p >= 0)
			{
				y += dir;
				p = p - 2*dx;
			}
			p = p + 2*dy;
			i++;
			printf("i = %d\n", i);
		}
	}
}

static void	draw_v_line(t_mlx *mlx, t_point p0, t_point p1, int color)
{
	int i = 0;
	int x = 0;
	int dx = 0;
	int dy = 0;
	int dir = 0;
	int p = 0;
	printf("%s\n", __func__);
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
		p = 2*dx - dy;
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
			printf("i = %d\n", i);
		}
	}
}

void	draw_line(t_mlx *mlx, t_point p0, t_point p1, int color)
{
	if (abs((int)p1.x-(int)p0.x) > abs((int)p1.y-(int)p0.y))
		draw_h_line(mlx, p0, p1, color);
	else
		draw_v_line(mlx, p0, p1, color);
	return ;
}

void	draw_player(t_mlx *mlx, t_point player)
{
	t_point a;
	t_point b;
	t_point c;
	// t_point p;
	int 	L = 300;
	double h = (sqrt(3) / 2) * L;
	double theta = get_radian(0);
	
	a.x = player.x + cos(theta) * h;
	a.y = player.y - sin(theta) * h;
	printf("A.x = %f\nA.y = %f\n", a.x, a.y);
	b.x = player.x + cos(theta + get_radian(120)) * L;
	b.y = player.y - sin(theta + get_radian(120)) * L;
	printf("B.x = %f\nB.y = %f\n", b.x, b.y);
	c.x = player.x + cos(theta + get_radian(240)) * L;
	c.y = player.y - sin(theta + get_radian(240)) * L;
	printf("C.x = %f\nC.y = %f\n", c.x, c.y);
	// __swap_point(&a, &b);
	// p.x = a.x + (((b.y - a.y) * (c.x - a.x)) / (c.y - a.y));
	// p.y = b.y; 
	// draw_line(mlx, a, b, HYELLOW);
	// draw_line(mlx, b, c, HYELLOW);
	// draw_line(mlx, c, a, HYELLOW);
	fill_triangle(mlx, a, b, c);
	// my_pixel_put(mlx, HRED, p.x, p.y);
	return ;
}

void	flat_top(t_mlx *mlx, t_point a, t_point b, t_point c)
{
	double y;
	double x;
	double x_left;
	double x_right;

	y = a.y;
	x = a.x;
	x_left = a.x;
	x_right = a.x;
	while (y <= b.y)
	{
		while (x <= x_right)
		{
			my_pixel_put(mlx, HYELLOW, x_left, y);
			x++;
		}
		x_left = a.x + (((y - a.y) * (b.x - a.x)) / (b.y - a.y));
		printf("div0 %f | x_left = %f\n", b.y - a.y, x_left);
		x = x_left;
		x_right = a.x + (((y - a.y) * (c.x - a.x)) / (c.y - a.y));
		printf("div0 %f | x_r = %f\n", c.y - a.y, x_right);
		y++;
	}
}

void	flat_bottom(t_mlx *mlx, t_point a, t_point b, t_point c)
{
	double y;
	// double x;
	double x_left;
	double x_right;

	y = c.y;
	// x = c.x;
	x_left = a.x;
	x_right = a.x;
	while (y >= a.y)
	{
		while (x_left <= x_right)
		{
			my_pixel_put(mlx, HYELLOW, x_left, y);
			x_left++;
		}
		x_left = c.x + (((y - c.y) * (b.x - c.x)) / (b.y - c.y));
		x_right = c.x + (((y - c.y) * (a.x - c.x)) / (a.y - c.y));
		y--;
	}
}

void	fill_triangle(t_mlx *mlx, t_point a, t_point b, t_point c)
{
	t_point	p;

	if (a.y > b.y)
		__swap_point(&a, &b);
	if (a.y > c.y)
		__swap_point(&a, &c);
	if (b.y > c.y)
		__swap_point(&b, &c);

	if (a.y == b.y)
		flat_top(mlx, a, b, c);
	else if (b.y == c.y)
		flat_bottom(mlx, a, b, c);
	else
	{
		p.x = a.x + (((b.y - a.y) * (c.x - a.x)) / (c.y - a.y));
		p.y = b.y;
		draw_line(mlx, b, p, HRED);
		flat_top(mlx, a, b, p);
		flat_bottom(mlx, p, b, c);
	}
}



