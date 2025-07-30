/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:53:58 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/30 01:45:44 by ly               ###   ########.fr       */
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
	data->player = malloc(sizeof(t_player));
	if (!data->player)
	{
		free(data->map);
		write(STDERR_FILENO, "Error: Couldn't malloc for player.\n", 36);
		exit(EXIT_FAILURE);
	}
	data->player->x = 0.0f;
	data->player->y = 0.0f;
	data->player->angle = 0.0f;
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
}
