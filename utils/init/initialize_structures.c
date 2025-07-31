/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:53:58 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/31 03:52:36 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_data(t_global *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		write(STDERR_FILENO, "Error: Could not allocate memory for map.\n", 42);
		exit(EXIT_FAILURE);
	}
	data->map->map_data = NULL;
	data->map->width = 0;
	data->map->height = 0;
}

static void	init_img(t_img *img)
{
	img->path = NULL;
	img->mlx_img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->llen = 0;
	img->endian = 0;
	img->imgw = 64;
	img->imgh = 64;
}

static void	init_color(int color[3])
{
	color[R] = -1;
	color[G] = -1;
	color[B] = -1;
}

static void	init_player(t_player *player) //initialisé en direction de l'est
{
	player->x = 0.0;
	player->y = 0.0;
	player->angle = 0.0;
	player->planex = 0.0;
	player->planey = 0.66;
	player->dirx = 1.0;
	player->diry = 0.0;
	player->ms = 0.055;
	player->rs = 0.02;
}

static void	init_ray(t_ray *ray)
{
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->mapx = 0;
	ray->mapy = 0;
	ray->sidedist.x = 0;
	ray->sidedist.y = 0;
	ray->deltadist.x = 0;
	ray->deltadist.y = 0;
	ray->perp_wall_dist = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->side = 0;
}

void	initialize_structures(t_global *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		init_img(&data->txtr[i]);
		i++;
	}
	init_img(&data->screen);
	i = 0;
	while (i < 2)
	{
		init_color(data->colors[i]);
		i++;
	}
	init_data(data);
	init_ray(&data->ray);
	init_player(&data->player);
}
