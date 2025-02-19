/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:40:21 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/19 23:40:45 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__keypress_handler(int keycode, t_data *d)
{
	float	move_x;
	float	move_y;
	float	next_player_x;
	float	next_player_y;
	float	buffer;
	int		collision_pos;
	int		collision_neg;
	
	move_x = 0;
	move_y = 0;
	buffer = 0.2;
	
	printf("Keycode pressed: %d (0x%x)\n", keycode, keycode);
	printf("Game state: %d\n", d->game->game_state);
	if (d->game->game_state == STATE_TITLE)
	{
		if (keycode == XK_Return) // Touche Entrée
		{
			d->game->game_state = STATE_GAME;
			return (SUCCESS); // same as continue;
		}
	}
	if (keycode == XK_Escape)
		clean(d->mlx);
	if (keycode == XK_Left)
	{
		d->player_dir -= 4;
		if (d->player_dir < 0)
		d->player_dir += 360; // (pour rester entre 0 et 2 PI radians)
		d->ray->player_rad = get_radian(d->player_dir);
		return (SUCCESS);
	}
	if (keycode == XK_Right)
	{
		d->player_dir += 4;
		if (d->player_dir > 360)
		d->player_dir = d->player_dir % 360;
		d->ray->player_rad = get_radian(d->player_dir);
		return (SUCCESS);
	}
	/********************** Player mouvements *************************/
	
	// cos = deplacement horizontal ; sin = deplacement vertical
	if (keycode == W)
	{
		move_x = cos(get_radian(d->player_dir)) * 5;
		move_y = sin(get_radian(d->player_dir)) * 5;
	}
	else if (keycode == A)
	{
		move_x = sin(get_radian(d->player_dir)) * 5;
		move_y = -cos(get_radian(d->player_dir)) * 5;
	}
	else if (keycode == S)
	{
		move_x = -cos(get_radian(d->player_dir)) * 5;
		move_y = -sin(get_radian(d->player_dir)) * 5;
	}
	else if (keycode == D)
	{
		move_x = -sin(get_radian(d->player_dir)) * 5;
		move_y = cos(get_radian(d->player_dir)) * 5;
	}
	// d->player.x = roundf(d->player.x + move_x);
	// d->player.y = roundf(d->player.y + move_y);
	
	next_player_x = d->player.x + move_x;
	next_player_y = d->player.y + move_y;
	printf("d->map->map2d[x: %d][y: %d]\n", (int)next_player_x, (int)next_player_y);
	
	// Verif des limites de la map
	if (next_player_x < 0 || next_player_x >= d->map->M_WIDTH ||
		next_player_y < 0 || next_player_y >= d->map->M_HEIGHT)
		return (SUCCESS); // same as continue;
		
	// Verif des collisions comprenant le joueur et sa zone de securite (buffer)
	
	// obs: Sans buffer, la collision n'est effectuee qu'a la position exacte du joueur
	// 		donc il peut se retrouver trop pres des murs
	collision_pos = d->map->map2d[(int)(next_player_x + buffer)][(int)(next_player_y + buffer)];
	collision_neg = d->map->map2d[(int)(next_player_x - buffer)][(int)(next_player_y - buffer)];
	if (collision_pos == '1' || collision_neg == '1')
	{
		printf(BOLD RED "Collision!\n" RESET);
		return (SUCCESS); // same as continue;
	}

	// Mise a jour de la position du joueur
	d->player.x = next_player_x;
	d->player.y = next_player_y;
	
	// if (avoid_collisions(keycode, d) == FAILURE)
	// 	return (FAILURE);
	
	/******************************************************************/
	return (SUCCESS);
}

static int	__mouse_handler(int button, int cursor_x, int cursor_y, t_data *data)
{
	t_game	*g;
	
	g = data->game;
	if (g->game_state == STATE_TITLE)
	{
		if (button == Button1) // Clic gauche
		{
			if ((cursor_x >= g->button.x && cursor_x <= g->button.x + 200) &&
				(cursor_y >= g->button.y && cursor_y <= g->button.y + 50))
				{
					data->game->game_state = STATE_GAME;
					return (SUCCESS);
				}
		}
	}
	return (SUCCESS);
}

void	set_hooks(t_mlx *mlx, t_data *data)
{
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &__keypress_handler, data);
	mlx_mouse_hook(mlx->win_ptr, &__mouse_handler, data);
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask, &clean, mlx);
}
