/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:04:48 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/18 22:27:44 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	Updates the Y-coordinate and the decision parameter 'p' for the
	next pixel in Bresenham's line algorithm when the line is primarily
	horizontal (dx >= dy)
	@param y: Pointer to the current Y-coordinate
	@param p: Pointer to the current decision parameter
	@param dx: The absolute difference in X-coordinates (always positive here)
	@param dy_orig: The original difference in Y-coordinates (can be negative)

	Logic:
	- Determines the vertical direction ('dir': 1 for down, -1 for up)
	- Calculates the absolute value of the Y difference ('dy_abs')
	- If the decision parameter 'p' is non-negative, it means the line is
	  closer to the next Y-coordinate, so increment/decrement 'y' and
	  update 'p'
	- Always update 'p' for the next iteration
*/
static void	__update_hline_state(int *y, int *p, int dx, int dy_orig)
{
	int	dir;
	int	dy_abs;

	if (dy_orig < 0)
		dir = -1;
	else
		dir = 1;
	dy_abs = dy_orig * dir;
	if (*p >= 0)
	{
		*y += dir;
		*p -= 2 * dx;
	}
	*p += 2 * dy_abs;
}

/*
	Draws a line using Bresenham's algorithm optimized for cases where the
	change in X is greater than or equal to the change in Y (|dx| >= |dy|)
	@param img: Pointer to the image structure where the line will be drawn
	@param p0: The starting point of the line
	@param p1: The ending point of the line

	Steps:
	- Ensures p0.x <= p1.x by swapping points if necessary
	- Calculates dx (change in x) and dy_orig (original change in y)
	- Handles the vertical line case (dx == 0) by returning (handled
	  by __draw_vline)
	- Initializes the starting Y-coordinate ('y') and the loop counter ('i')
	- Calculates the initial decision parameter 'p' based on the absolute dy
	- Iterates from the starting x to the ending x:
		- Draws a pixel at the current (p0.x + i, y)
		- Calls __update_hline_state to determine the y for the next pixel
		  and update 'p'
		- Increments the x-counter 'i'
*/
static void	__draw_hline(t_img *img, t_point p0, t_point p1, int color)
{
	int	dx;
	int	dy_orig;
	int	p;
	int	i;
	int	y;

	if (p0.x > p1.x)
		swap_point(&p0, &p1);
	dx = p1.x - p0.x;
	dy_orig = p1.y - p0.y;
	if (dx == 0)
		return ;
	y = p0.y;
	i = 0;
	if (dy_orig < 0)
		p = 2 * (dy_orig * -1) - dx;
	else
		p = 2 * dy_orig - dx;
	while (i <= dx)
	{
		my_pixel_put_to_img(img, color, p0.x + i, y);
		__update_hline_state(&y, &p, dx, dy_orig);
		i++;
	}
}

/*	Opposite of above  */
static void	__update_vline_state(int *x, int *p, int dy, int dx_orig)
{
	int	dir;
	int	dx_abs;

	if (dx_orig < 0)
		dir = -1;
	else
		dir = 1;
	dx_abs = dx_orig * dir;
	if (*p >= 0)
	{
		*x += dir;
		*p -= 2 * dy;
	}
	*p += 2 * dx_abs;
}

/*	Opposite of above  */
static void	__draw_vline(t_img *img, t_point p0, t_point p1, int color)
{
	int	dx_orig;
	int	dy;
	int	p;
	int	i;
	int	x;

	if (p0.y > p1.y)
		swap_point(&p0, &p1);
	dx_orig = p1.x - p0.x;
	dy = p1.y - p0.y;
	if (dy == 0)
		return ;
	x = p0.x;
	i = 0;
	if (dx_orig < 0)
		p = 2 * (dx_orig * -1) - dy;
	else
		p = 2 * dx_orig - dy;
	while (i <= dy)
	{
		my_pixel_put_to_img(img, color, x, p0.y + i);
		__update_vline_state(&x, &p, dy, dx_orig);
		i++;
	}
}

void	draw_line(t_img *img, t_point p0, t_point p1, int color)
{
	if (is_valid_point(p0, WIN_WIDTH, WIN_HEIGHT) == false
		|| is_valid_point(p1, WIN_WIDTH, WIN_HEIGHT) == false)
	{
		err_msg(NULL, "Point called is out of map");
		return ;
	}
	if (abs((int)p1.x - (int)p0.x) > abs((int)p1.y - (int)p0.y))
		__draw_hline(img, p0, p1, color);
	else
		__draw_vline(img, p0, p1, color);
}
