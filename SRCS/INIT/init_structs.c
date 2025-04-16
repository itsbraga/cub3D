/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/16 04:09:47 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__init_player(t_player *player, t_game *game)
{
	ft_bzero(player, sizeof(t_player));
	game->player = player;
}

static void	__init_textures(t_textures *tex, t_data *data)
{
	ft_bzero(tex, sizeof(t_textures));
	if (!BONUS)
	{
		tex->path = yama(CREATE, NULL, sizeof(char *) * 4);
		secure_malloc(tex->path, true);
		ft_bzero(tex->path, sizeof(char *) * 4);
		tex->imgs = yama(CREATE, NULL, sizeof(t_img) * 4);
		secure_malloc(tex->imgs, true);
	}
	else
	{
		tex->path = yama(CREATE, NULL, sizeof(char *) * 7);
		secure_malloc(tex->path, true);
		ft_bzero(tex->path, sizeof(char *) * 7);
		tex->imgs = yama(CREATE, NULL, sizeof(t_img) * 7);
		secure_malloc(tex->imgs, true);
	}
	data->decor_tex = tex;
}

static void	__init_raycasting(t_raycasting *r, t_game *game)
{
	ft_bzero(r, sizeof(t_raycasting));
	r->fov = 45;
	game->ray = r;
}

static void	__init_keys(t_keys *keys, t_game *game)
{
	ft_bzero(keys->key_array, 7);
	game->keys = keys;
}

void	init_structs(t_data *data, t_game *game, t_mlx *mlx)
{
	init_mlx(mlx, game);
	init_title_screen(&game->title_screen);
	__init_player(game->player, game);
	__init_textures(data->decor_tex, data);
	__init_raycasting(game->ray, game);
	__init_keys(game->keys, game);
	if (BONUS)
	{
		
		init_minimap(game->mmap, game);
	}
}
