/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fc_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:07:23 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/08 18:54:44 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	Calculates the necessary parameters to draw a horizontal scanline
	on the floor

	The function:
	- Calculates the perpendicular distance ('row_dist') between the camera
	  and the world points corresponding to the screen line 'fc->y'
	- Calculates the steps ('step_x', 'step_y'): how much the world coordinates
	  change when moving one pixel horizontally on the screen
	- Calculates the world coordinates ('start_x', 'start_y') for the first
	  pixel (x = 0) of the scanline
	- Calculates the shadow factor ('shadow_factor') based on the distance
*/
static void	__calculate_floor_scanline(t_fc_render *fc, t_player *player)
{
	float	curr_dist_from_horizon;
	float	delta_ray_dir_x;
	float	delta_ray_dir_y;

	curr_dist_from_horizon = fc->y - fc->horizon_line;
	fc->row_dist = (fc->v_scale_factor * TILE_SIZE) / curr_dist_from_horizon;
	delta_ray_dir_x = fc->rightmost_ray_dir_x - fc->leftmost_ray_dir_x;
	delta_ray_dir_y = fc->rightmost_ray_dir_y - fc->leftmost_ray_dir_y;
	fc->step_x = fc->row_dist * delta_ray_dir_x / WIN_WIDTH;
	fc->step_y = fc->row_dist * delta_ray_dir_y / WIN_WIDTH;
	fc->start_x = player->pos.x + fc->row_dist * fc->leftmost_ray_dir_x;
	fc->start_y = player->pos.y + fc->row_dist * fc->leftmost_ray_dir_y;
	fc->shadow_factor = calculate_shadow_factor(fc->row_dist);
}

/*
	Draws the floor texture onto the screen, row by horizontal row

	The function:
	- Initializes the rendering structure 'fc'
	- Loads the floor texture buffer
	- Iterates over each horizontal row 'y' of the screen, from the horizon
	  down to the bottom of the screen
	- For each row 'y', calls '__calculate_floor_scanline' to get the
	  scanline parameters
	- Calls 'draw_hline_pixels' to draw the pixels for that row
*/
void	draw_floor_tex(t_raycasting *r, int wall_limits[WIN_WIDTH][2],
	t_player *player)
{
	t_fc_render	fc;
	int			tex_buffer[TILE_SIZE * TILE_SIZE];

	init_fc_render(&fc, r, wall_limits);
	handle_fc_tex_buffer(F, tex_buffer);
	fc.tex_buffer = tex_buffer;
	fc.y = fc.horizon_line;
	while (fc.y < WIN_HEIGHT)
	{
		__calculate_floor_scanline(&fc, player);
		draw_hline_pixels(&fc);
		fc.y++;
	}
}

/*
	Calculates the necessary parameters to draw a horizontal scanline
	on the ceiling

	The function:
	- Similar to '__calculate_floor_scanline', but calculates parameters
	  for the ceiling (so the distance to the horizon is inverted)
*/
static void	__calculate_ceil_scanline(t_fc_render *fc, t_player *player)
{
	float	curr_dist_from_horizon;
	float	delta_ray_dir_x;
	float	delta_ray_dir_y;

	curr_dist_from_horizon = fc->horizon_line - fc->y;
	fc->row_dist = (fc->v_scale_factor * TILE_SIZE) / curr_dist_from_horizon;
	delta_ray_dir_x = fc->rightmost_ray_dir_x - fc->leftmost_ray_dir_x;
	delta_ray_dir_y = fc->rightmost_ray_dir_y - fc->leftmost_ray_dir_y;
	fc->step_x = fc->row_dist * delta_ray_dir_x / WIN_WIDTH;
	fc->step_y = fc->row_dist * delta_ray_dir_y / WIN_WIDTH;
	fc->start_x = player->pos.x + fc->row_dist * fc->leftmost_ray_dir_x;
	fc->start_y = player->pos.y + fc->row_dist * fc->leftmost_ray_dir_y;
	fc->shadow_factor = calculate_shadow_factor(fc->row_dist);
}

/*
	Draws the ceiling texture onto the screen, row by horizontal row

	The function:
	- Initializes the rendering structure 'fc'
	- Loads the ceiling texture buffer
	- Iterates over each horizontal row 'y' of the screen, from the top
	  down to the horizon
	- For each row 'y', calls '__calculate_ceil_scanline' to get the
	  scanline parameters
	- Calls 'draw_hline_pixels' to draw the pixels for that row
*/
void	draw_ceil_tex(t_raycasting *r, int wall_limits[WIN_WIDTH][2],
t_player *player)
{
	t_fc_render	fc;
	int			tex_buffer[TILE_SIZE * TILE_SIZE];

	init_fc_render(&fc, r, wall_limits);
	handle_fc_tex_buffer(C, tex_buffer);
	fc.tex_buffer = tex_buffer;
	fc.y = 0;
	while (fc.y < fc.horizon_line)
	{
		__calculate_ceil_scanline(&fc, player);
		draw_hline_pixels(&fc);
		fc.y++;
	}
}

/*
	Fundamental differences between Wall vs Floor/Ceiling Rendering:

	WALLS RENDERING (draw_wall_tex.c -> __draw_vline_texture):

	  - Approach: Vertical (column by column).
	  - Logic: For a given screen column 'x', determine the wall height
	    on the screen ('wall_h'). Then, map this vertical screen height
	    to the vertical texture height using a constant step ('step_tex_y')
	    to find the texture 'tex_y' coordinate for each screen pixel 'y'
	    in the wall column.
	  - Key calculation: 'tex_y = (int)accumulator_tex_y & (TILE_SIZE - 1)', 
	    where 'accumulator_tex_y += step_tex_y'.


	FLOOR/CEILING RENDERING (draw_fc_tex.c -> draw_hline_pixels):
	
	  - Approach: Horizontal (row by row / scanline).
	  - Logic: For a given screen row 'y', calculate the real-world distance
	    ('row_dist') to the floor/ceiling plane. Determine the world
		coordinates ('start_x', 'start_y') corresponding to the start of the
	    scanline ('x = 0').
	    Then, calculate steps ('step_x', 'step_y') to interpolate the world
	    coordinates ('curr_world_x/y') while scanning horizontally ('x++')
		across the screen row. These world coordinates provide the texture
	    coordinates.
	  - Key calculation: 'curr_world_x += step_x', 'curr_world_y += step_y'.

	CONCLUSION:
	
	Walls are mapped vertically (Screen Y -> Texture Y),
	Floor/Ceiling are mapped horizontally via perspective projection
	(Screen X -> World X/Y -> Texture X/Y).
*/