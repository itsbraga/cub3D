/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_render_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:14:31 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/16 01:40:45 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

/*
	Calculates the direction vectors for the rays at the left and right
	extremities of the Field of View (FOV)

	The function:
	- Calculates the ray angles for x = 0 (left) and x = WIN_WIDTH (right)
	- Stores the cos/sin components of these angles in the fc struct
	These directions are used for world coordinate interpolation.
*/
static void	__get_extreme_rays(t_fc_render *fc, t_raycasting *r)
{
	float	fov_rad;
	float	player_rad_start;
	float	player_rad_end;

	fov_rad = degree_to_radian(r->fov);
	player_rad_start = norm_rad_angle(r->player_rad - (fov_rad / 2.0f));
	player_rad_end = norm_rad_angle(r->player_rad + (fov_rad / 2.0f));
	fc->leftmost_ray_dir_x = cos(player_rad_start);
	fc->leftmost_ray_dir_y = sin(player_rad_start);
	fc->rightmost_ray_dir_x = cos(player_rad_end);
	fc->rightmost_ray_dir_y = sin(player_rad_end);
}

/*
	Initializes the t_fc_render structure with necessary data before
	starting the floor or ceiling rendering
	@param wall_limits: Array of vertical wall limits for each column

	NB: the vertical scaling factor ('v_scale_factor') is used in the
		perspective projection
*/
void	init_fc_render(t_fc_render *fc, t_raycasting *r, int (*wall_limits)[2])
{
	fc->img = &s_mlx()->img;
	fc->wall_limits = wall_limits;
	fc->horizon_line = WIN_HEIGHT / 2;
	fc->v_scale_factor = 0.5 * WIN_HEIGHT;
	__get_extreme_rays(fc, r);
}

/*
	Draws the pixels of a horizontal scanline for the floor or ceiling

	The function:
	- Iterates over each pixel 'x' across the screen width ('WIN_WIDTH')
	- Checks if the current pixel '(x, fc->y)' is above (ceiling) or
	  below (floor) the vertical wall limits ('wall_limits[x]')
	- If visible, calculates the texture coordinates ('tex_x', 'tex_y') from
	  the interpolated world coordinates ('curr_world_x', 'curr_world_y')
	- Retrieves the texture color, applies shading ('shadow_factor')
	- Draws the final pixel onto the image ('fc->img')
	- Increments the world coordinates ('curr_world_x/y') using the steps
	  ('step_x/y')

	Key variables:
	  - 'x': Horizontal pixel coordinate on the screen (0 to WIN_WIDTH - 1)
	  - 'curr_world_x/y': Interpolated X/Y coordinates in the 3D world
	    (floor/ceiling) corresponding to the screen pixel 'x'
*/
void	draw_hline_pixels(t_fc_render *fc)
{
	int		x;
	float	curr_world_x;
	float	curr_world_y;
	int		tex_x;
	int		tex_y;

	x = 0;
	curr_world_x = fc->start_x;
	curr_world_y = fc->start_y;
	while (x < WIN_WIDTH)
	{
		if ((fc->y < fc->horizon_line && fc->y < fc->wall_limits[x][0])
			|| (fc->y >= fc->horizon_line && fc->y >= fc->wall_limits[x][1]))
		{
			tex_x = (int)(curr_world_x) & (TILE_SIZE - 1);
			tex_y = (int)(curr_world_y) & (TILE_SIZE - 1);
			fc->color = fc->tex_buffer[tex_y * TILE_SIZE + tex_x];
			fc->color = apply_shadow_factor(fc->color, fc->shadow_factor);
			my_pixel_put_to_img(fc->img, fc->color, x, fc->y);
		}
		curr_world_x += fc->step_x;
		curr_world_y += fc->step_y;
		x++;
	}
}
