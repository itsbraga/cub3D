/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fc_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:07:23 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/03 02:31:48 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	Precalculates trigonometric values needed for floor and ceiling rendering

	The function:
	- Normalizes the angle between player direction and ray
	- Calculates and stores trigonometric values for efficient rendering and
	  perspective correction
*/
void	fc_precalculations(t_raycasting *r, float ray_rad)
{
	float	fixed_angle;

	fixed_angle = norm_rad_angle(r->player_rad - ray_rad);
	r->ray_cos = cos(ray_rad);
	r->ray_sin = sin(ray_rad);
	r->fixed_angle_cos = cos(fixed_angle);
}

/*
	Core function for drawing a single row of floor texture
	@param fc: Pointer to floor/ceiling core struct containing rendering state
	@param tex_buffer: Array containing the floor texture data

	Variables:
	- floor: Point struct for the current floor position in world space
	- shadow_factor: Factor to apply for distance-based shadowing
	- img: Pointer to the MLX image structure for drawing
	- dy: Vertical distance from screen center
	- row_dist: Distance to the current row in world space
	- tex_x/y: Texture coordinates for sampling
	- color: Final color to draw

	The function:
	- Calculates the distance to the current row
	- Determines the world position for texture sampling
	- Applies distance-based shadowing
	- Samples and draws the texture at the current position
*/
static void	__draw_hline_floor(t_raycasting *r, t_fc_core *fc, int *tex_buffer)
{
	t_point	floor;
	float	shadow_factor;
	t_img	*img;

	img = &s_mlx()->img;
	fc->vdist = fc->curr_y - (WIN_HEIGHT / 2.0f);
	if (fc->vdist == 0)
		return ;
	fc->row_dist = ((float)TILE_SIZE * WIN_HEIGHT) / (2.0f * fc->vdist);
	fc->row_dist /= r->fixed_angle_cos;
	floor.x = s_game()->player->pos.x + fc->row_dist * r->ray_cos;
	floor.y = s_game()->player->pos.y + fc->row_dist * r->ray_sin;
	shadow_factor = calculate_shadow_factor(fc->row_dist);
	fc->tex_x = ((int)floor.x) & (TILE_SIZE - 1);
	fc->tex_y = ((int)floor.y) & (TILE_SIZE - 1);
	fc->color = tex_buffer[fc->tex_y * TILE_SIZE + fc->tex_x];
	fc->color = apply_shadow_factor(fc->color, shadow_factor);
	my_pixel_put_to_img(img, fc->color, r->curr_ray, fc->curr_y);
}

/*
	Main function for drawing the floor texture

	Variables:
	- tex_buffer: Array to store floor texture data
	- fc: Structure to maintain rendering state

	The function:
	- Initializes texture buffer and rendering state
	- Iterates from wall_end_y to screen bottom
	- Calls core function for each row of the floor
*/
void draw_floor_texture(t_raycasting *r)
{
	int			tex_buffer[TILE_SIZE * TILE_SIZE];
	t_fc_core	fc;

	handle_fc_tex_buffer(F, tex_buffer);
	ft_bzero(&fc, sizeof(t_fc_core));
	fc.curr_y = r->wall_end_y;
	while (fc.curr_y <= WIN_HEIGHT)
	{
		__draw_hline_floor(r, &fc, tex_buffer);
		fc.curr_y++;
	}
	return ;
}

/*
	Core function for drawing a single row of ceiling texture
	@param fc: Pointer to floor/ceiling core struct containing rendering state
	@param tex_buffer: Array containing the ceiling texture data

	Variables:
	- ceiling: Point struct for the current ceiling position in world space
	- shadow_factor: Factor to apply for distance-based shadowing
	- img: Pointer to the MLX image structure for drawing
	- dy: Vertical distance from screen center
	- row_dist: Distance to the current row in world space
	- tex_x/y: Texture coordinates for sampling
	- color: Final color to draw

	The function:
	- Calculates the distance to the current row
	- Determines the world position for texture sampling
	- Applies distance-based shadowing
	- Samples and draws the texture at the current position
*/
static void	__draw_hline_ceiling(t_raycasting *r, t_fc_core *fc,
int *tex_buffer)
{
	t_point ceiling;
	float	shadow_factor;
	t_img	*img;

	img = &s_mlx()->img;
	fc->vdist = (WIN_HEIGHT / 2.0f) - fc->curr_y;
	if (fc->vdist == 0)
		return ;
	fc->row_dist = ((float)TILE_SIZE * WIN_HEIGHT) / (2.0f * fc->vdist);
	fc->row_dist /= r->fixed_angle_cos;
	ceiling.x = s_game()->player->pos.x + fc->row_dist * r->ray_cos;
	ceiling.y = s_game()->player->pos.y + fc->row_dist * r->ray_sin;
	shadow_factor = calculate_shadow_factor(fc->row_dist);
	fc->tex_x = ((int)ceiling.x) & (TILE_SIZE - 1);
	fc->tex_y = ((int)ceiling.y) & (TILE_SIZE - 1);
	fc->color = tex_buffer[fc->tex_y * TILE_SIZE + fc->tex_x];
	fc->color = apply_shadow_factor(fc->color, shadow_factor);
	my_pixel_put_to_img(img, fc->color, r->curr_ray, fc->curr_y);
}

/*
	Main function for drawing the ceiling texture

	Variables:
	- tex_buffer: Array to store ceiling texture data
	- fc: Structure to maintain rendering state

	The function:
	- Initializes texture buffer and rendering state
	- Iterates from screen top to wall_start_y
	- Calls core function for each row of the ceiling
*/
void draw_ceiling_texture(t_raycasting *r)
{
	int			tex_buffer[TILE_SIZE * TILE_SIZE];
	t_fc_core	fc;

	handle_fc_tex_buffer(C, tex_buffer);
	ft_bzero(&fc, sizeof(t_fc_core));
	fc.curr_y = 0;
	while (fc.curr_y <= r->wall_start_y)
	{
		__draw_hline_ceiling(r, &fc, tex_buffer);
		fc.curr_y++;
	}
	return ;
}
