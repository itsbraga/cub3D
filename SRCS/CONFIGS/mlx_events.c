/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:20:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/02/14 21:49:02 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//ne pas oublier de reset le tableau de boolean

void	move_forward(t_data *data)
{
	data->move_x = cos(get_radian(data->player_dir)) * 3;
	data->move_y = sin(get_radian(data->player_dir)) * 3;
}

void	move_backward(t_data *data)
{
	data->move_x = -cos(get_radian(data->player_dir)) * 3;
	data->move_y = -sin(get_radian(data->player_dir)) * 3;
}

void	straf_leftward(t_data *data)
{
	data->move_x = sin(get_radian(data->player_dir)) * 3;
	data->move_y = -cos(get_radian(data->player_dir)) * 3;
}

void	straf_rightward(t_data *data)
{
	data->move_x = -sin(get_radian(data->player_dir)) * 3;
	data->move_y = cos(get_radian(data->player_dir)) * 3;
}

void	rotate_leftward(t_data *data)
{
	data->player_dir -= 4;
	if (data->player_dir < 0)
		data->player_dir += 360; // (pour rester entre 0 et 2 PI radians)
	data->ray->player_rad = get_radian(data->player_dir);
}

void	rotate_rightward(t_data *data)
{
	data->player_dir += 4;
	if (data->player_dir > 360)
		data->player_dir = data->player_dir % 360;
	data->ray->player_rad = get_radian(data->player_dir);
}

void	init_movetab(move_tab *functions)
{
	functions[0] = move_forward;
	functions[1] = move_backward; 
	functions[2] = straf_leftward; 
	functions[3] = straf_rightward; 
	functions[4] = rotate_leftward;
	functions[5] = rotate_rightward;
	functions[6] = NULL;
}

void	handle_movement(t_data *data, t_kevent *key)
{
	int	i;
	move_tab	functions[7];

	i = 0;
	init_movetab(functions);
	data->player.x = roundf(data->player.x + data->move_x);
	data->player.y = roundf(data->player.y + data->move_y);
}

int	set_keypress_flag(int keyval, t_data *data, t_kevent *key)
{	
	if (keyval == XK_Escape)
	{
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
		data->mlx->win_ptr = NULL;
	}
	if (keyval == W)
		key->key_tab[W_KEY] = 1;
	if (keyval == S)
		key->key_tab[S_KEY] = 1;
	if (keyval == D)
		key->key_tab[D_KEY] = 1;
	if (keyval == A)
		key->key_tab[A_KEY] = 1;
	if (keyval == XK_Left)
		key->key_tab[LEFT_KEY] = 1;
	if (keyval == XK_Right)
		key->key_tab[RIGHT_KEY] = 1;
	return (SUCCESS);
}


