/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:24:45 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/31 23:15:37 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	Core function for drawing a vertical line of wall texture
	@param start_y: Starting y-coordinate of the wall line
	@param end_y: Ending y-coordinate of the wall line
	@param tex_buffer: Array containing the wall texture data

	Variables:
	- curr_y: Current y-coordinate being drawn
	- tex_y: Current texture y-coordinate
	- accumulator_tex_y: Accumulator for texture y-coordinate calculation
	- color: Final color to draw
	- img: Pointer to the MLX image structure for drawing

	The function:
	- Calculates shadow factor based on wall distance
	- Samples texture coordinates with proper wrapping
	- Applies distance-based shadowing
	- Draws each pixel of the vertical line
*/
static void	__draw_vline_wall_tex(int start_y, int end_y, int *tex_buffer,
t_raycasting *r)
{
	int 	curr_y;
	int 	tex_y;
	float	accumulator_tex_y;
	int 	color;
	t_img	*img;

	curr_y = start_y;
	accumulator_tex_y = r->offset_tex_y * r->step_tex_y;
	img = &s_mlx()->img;
	while (curr_y <= end_y)
	{
		r->shadow_factor = calculate_shadow_factor(r->dist_wall);
		tex_y = (int)accumulator_tex_y & (TILE_SIZE - 1);
		accumulator_tex_y += r->step_tex_y;
		color = tex_buffer[tex_y * TILE_SIZE + r->tex_x];
		color = apply_shadow_factor(color, r->shadow_factor);
		my_pixel_put_to_img(img, color, r->curr_ray, curr_y);
		curr_y++;
	}
	return ; 
}

/*
	Main function for drawing a wall segment
	@param ray_rad: Current ray angle in radians

	Variables:
	- tex_buffer: Array to store wall texture data
	- fixed_angle: Normalized angle between player direction and ray
	- wall_h: Height of the wall segment on screen
	- offset_tex_y: Vertical offset for texture sampling
	- step_tex_y: Step size for texture sampling
	- wall_start_y/end_y: Vertical boundaries of the wall on screen

	The function:
	- Corrects wall distance for perspective
	- Calculates wall height and texture sampling parameters
	- Handles wall height exceeding screen height
	- Determines wall boundaries on screen
	- Loads and draws the wall texture
*/
void	draw_wall(t_raycasting *r, float ray_rad)
{
	int		tex_buffer[TILE_SIZE * TILE_SIZE];
	float	fixed_angle;

	fixed_angle = norm_rad_angle(r->player_rad - ray_rad);
	r->dist_wall *= cos(fixed_angle);
	r->wall_h = (TILE_SIZE * WIN_HEIGHT) / r->dist_wall;
	r->offset_tex_y = 0;
	r->step_tex_y = TILE_SIZE / r->wall_h;
	if (r->wall_h > WIN_HEIGHT)
	{
		r->offset_tex_y = (r->wall_h - WIN_HEIGHT) / 2.0f;
		r->wall_h = WIN_HEIGHT;
	}
	r->wall_start_y = (WIN_HEIGHT / 2) - (r->wall_h / 2);
	r->wall_end_y = r->wall_start_y + r->wall_h;
	handle_tex_buffer(tex_buffer, r, ray_rad);
	__draw_vline_wall_tex(r->wall_start_y, r->wall_end_y, tex_buffer, r);
}
