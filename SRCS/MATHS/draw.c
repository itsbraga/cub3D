/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:41:54 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/21 23:36:41 by pmateo           ###   ########.fr       */
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
}

static void	draw_v_line(t_mlx *mlx, t_point p0, t_point p1, int color)
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
}

void	draw_line(t_mlx *mlx, t_point p0, t_point p1, int color)
{
	if (abs((int)p1.x-(int)p0.x) > abs((int)p1.y-(int)p0.y))
		draw_h_line(mlx, p0, p1, color);
	else
		draw_v_line(mlx, p0, p1, color);
}

void	draw_player(t_data *data, t_mlx *mlx, t_point player)
{
	t_point a;
	t_point b;
	t_point c;
	int		L = 200;
	double	h = 1.3 * L;
	double	theta = get_radian(data->player_dir);
	
	a.x = player.x + cos(theta) * h;
	a.y = player.y + sin(theta) * h;
	printf("A.x = %f\nA.y = %f\n", a.x, a.y);
	printf("player.x = %f, cos(theta) = %f, h = %f\n", player.x, cos(theta), h);
	printf("player.y = %f, sin(theta) = %f, h = %f\n", player.y, sin(theta), h);
	
	b.x = player.x + cos(theta + (M_PI / 2)) * (L / 2);
	b.y = player.y + sin(theta + (M_PI / 2)) * (L / 2);
	printf("B.x = %f\nB.y = %f\n", b.x, b.y);
	
	c.x = player.x + cos(theta - (M_PI / 2)) * (L / 2);
	c.y = player.y + sin(theta - (M_PI / 2)) * (L / 2);
	printf("C.x = %f\nC.y = %f\n", c.x, c.y);
	
	// my_pixel_put(mlx, HYELLOW, W_WIDTH / 2, W_HEIGHT / 2);
	draw_line(mlx, a, b, HYELLOW);
	draw_line(mlx, b, c, HYELLOW);
	draw_line(mlx, c, a, HYELLOW);
	// fill_triangle(mlx, a, b, c, HYELLOW);
}

void fill_triangle(t_mlx *mlx, t_point p1, t_point p2, t_point p3, int color)
{
    // Tri des points par Y croissant
    if (p1.y > p2.y) { t_point temp = p1; p1 = p2; p2 = temp; }
    if (p1.y > p3.y) { t_point temp = p1; p1 = p3; p3 = temp; }
    if (p2.y > p3.y) { t_point temp = p2; p2 = p3; p3 = temp; }

    // Calcul des deltas pour chaque segment
    double dx12 = p2.x - p1.x;
    double dy12 = p2.y - p1.y;
    double dx13 = p3.x - p1.x;
    double dy13 = p3.y - p1.y;
    double dx23 = p3.x - p2.x;
    double dy23 = p3.y - p2.y;

    // Calcul des pentes avec protection contre la division par zéro
    double slope1;
    double slope2;
    double slope3;

    if (dy12 != 0)
        slope1 = dx12 / dy12;
    else
        slope1 = 0;

    if (dy13 != 0)
        slope2 = dx13 / dy13;
    else
        slope2 = 0;

    if (dy23 != 0)
        slope3 = dx23 / dy23;
    else
        slope3 = 0;

    // Variables pour le scanning
    double curx1 = p1.x;
    double curx2 = p1.x;

    // Première partie du triangle (du sommet à la ligne médiane)
    int sy = (int)ceil(p1.y);
    int ey = (int)ceil(p2.y);
    
    if (sy < ey) {
        curx1 += slope1 * (sy - p1.y);
        curx2 += slope2 * (sy - p1.y);
        
        for (int y = sy; y < ey; y++) {
            int x1 = (int)round(curx1);
            int x2 = (int)round(curx2);
            
            if (x1 > x2) { int temp = x1; x1 = x2; x2 = temp; }
            for (int x = x1; x <= x2; x++) {
                my_pixel_put(mlx, color, x, y);
            }
            
            curx1 += slope1;
            curx2 += slope2;
        }
    }

    // Deuxième partie du triangle (de la ligne médiane au bas)
    sy = (int)ceil(p2.y);
    ey = (int)ceil(p3.y);
    
    if (sy < ey) {
        curx1 = p2.x + slope3 * (sy - p2.y);
        curx2 = p1.x + slope2 * (sy - p1.y);
        
        for (int y = sy; y < ey; y++) {
            int x1 = (int)round(curx1);
            int x2 = (int)round(curx2);
            
            if (x1 > x2) { int temp = x1; x1 = x2; x2 = temp; }
            for (int x = x1; x <= x2; x++) {
                my_pixel_put(mlx, color, x, y);
            }
            
            curx1 += slope3;
            curx2 += slope2;
        }
    }
}
