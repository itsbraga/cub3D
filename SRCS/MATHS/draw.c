/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:41:54 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/13 09:32:51 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void	swap_point(t_point *p0, t_point *p1)
{
	int x_tmp;
	int y_tmp;

	x_tmp = p0->x;
	y_tmp = p0->y;
	p0->x = p1->x;
	p0->y = p1->y;
	p1->x = x_tmp;
	p1->y = y_tmp;
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
		swap_point(&p0, &p1);
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
	if (abs(p1.x-p0.x) > abs(p1.y-p0.y))
		draw_h_line(mlx, p0, p1, color);
	else
		draw_v_line(mlx, p0, p1, color);
	return ;
}