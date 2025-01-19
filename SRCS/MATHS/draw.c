/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:41:54 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/19 17:47:15 by pmateo           ###   ########.fr       */
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
	int 	L = 10;
	double h = 1.3 * L;
	double theta = get_radian(90);
	
	a.x = player.x + cos(theta) * h;
	a.y = player.y - sin(theta) * h;
	printf("A.x = %f\nA.y = %f\n", a.x, a.y);
	b.x = player.x + cos(theta + (M_PI / 2)) * (L / 2);
	b.y = player.y - sin(theta + (M_PI / 2)) * (L / 2);
	printf("B.x = %f\nB.y = %f\n", b.x, b.y);
	c.x = player.x + cos(theta - (M_PI / 2)) * (L / 2);
	c.y = player.y - sin(theta - (M_PI / 2)) * (L / 2);
	printf("C.x = %f\nC.y = %f\n", c.x, c.y);
	my_pixel_put(mlx, HYELLOW, WIDTH / 2, HEIGHT / 2);
	// draw_line(mlx, , b, HYELLOW);
	// draw_line(mlx, b, c, HYELLOW);
	// draw_line(mlx, c, a, HYELLOW);
	// fill_triangle(mlx, a, b, c, HYELLOW);
	return ;
}

void fill_triangle(t_mlx *mlx, t_point p1, t_point p2, t_point p3, int color)
{
    if (p1.y > p2.y) { 
        t_point temp = p1; 
        p1 = p2; 
        p2 = temp; 
    }
    if (p1.y > p3.y) { 
        t_point temp = p1; 
        p1 = p3; 
        p3 = temp; 
    }
    if (p2.y > p3.y) { 
        t_point temp = p2; 
        p2 = p3; 
        p3 = temp; 
    }

    float invslope1;
    if (p2.y - p1.y != 0) {
        invslope1 = (float)(p2.x - p1.x) / (float)(p2.y - p1.y);
    } else {
        invslope1 = 0;
    }

    float invslope2;
    if (p3.y - p1.y != 0) {
        invslope2 = (float)(p3.x - p1.x) / (float)(p3.y - p1.y);
    } else {
        invslope2 = 0;
    }

    float invslope3;
    if (p3.y - p2.y != 0) {
        invslope3 = (float)(p3.x - p2.x) / (float)(p3.y - p2.y);
    } else {
        invslope3 = 0;
    }

    float curx1, curx2;

    curx1 = curx2 = p1.x;  
    
    int y;
    for (y = p1.y; y < p2.y; y++) {
        int x1 = (int)(curx1 + 0.5f);
        int x2 = (int)(curx2 + 0.5f);
        
        if (x1 > x2) {
            int temp = x1;
            x1 = x2;
            x2 = temp;
        }
        
        for (int x = x1; x <= x2; x++) {
             my_pixel_put(mlx, color, x, y);
        }
        
        curx1 += invslope1;
        curx2 += invslope2;
    }

    curx1 = p2.x;
    
    for (y = p2.y; y <= p3.y; y++) {
        int x1 = (int)(curx1 + 0.5f);
        int x2 = (int)(curx2 + 0.5f);
        
        if (x1 > x2) {
            int temp = x1;
            x1 = x2;
            x2 = temp;
        }
        
        for (int x = x1; x <= x2; x++) {
         	  my_pixel_put(mlx, color, x, y);
        }
        
        curx1 += invslope3;
        curx2 += invslope2;
    }
}



