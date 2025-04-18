/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/04/18 18:21:57 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__init_player(t_player *p, t_game *g)
{
	ft_bzero(p, sizeof(t_player));
	g->player = p;
}

static void	__init_textures(t_textures *tex, t_data *d)
{
	ft_bzero(tex, sizeof(t_textures));
	if (!BONUS)
	{
		tex->path = malloc(sizeof(char *) * 4);
		secure_malloc(tex->path, true);
		ft_bzero(tex->path, sizeof(char *) * 4);
		tex->imgs = malloc(sizeof(t_img) * 4);
		secure_malloc(tex->imgs, true);
		ft_bzero(tex->imgs, sizeof(t_img) * 4);
	}
	else
	{
		tex->path = malloc(sizeof(char *) * 7);
		secure_malloc(tex->path, true);
		ft_bzero(tex->path, sizeof(char *) * 7);
		tex->imgs = malloc(sizeof(t_img) * 7);
		secure_malloc(tex->imgs, true);
		ft_bzero(tex->imgs, sizeof(t_img) * 7);
	}
	d->decor_tex = tex;
}

static void	__init_raycasting(t_raycasting *r, t_game *g)
{
	ft_bzero(r, sizeof(t_raycasting));
	r->fov = 45;
	g->ray = r;
}

static void	__init_keys(t_keys *keys, t_game *g)
{
	ft_bzero(keys->key_array, 7);
	ft_bzero(keys->mouse_btn, 3);
	g->keys = keys;
}

void	init_structs(t_data *d, t_game *g, t_mlx *mlx)
{
	init_mlx(mlx, g);
	init_title_screen(&g->title_screen);
	__init_player(g->player, g);
	__init_textures(d->decor_tex, d);
	__init_raycasting(g->ray, g);
	__init_keys(g->keys, g);
	if (BONUS)
		init_minimap(g->mmap, g);
}
