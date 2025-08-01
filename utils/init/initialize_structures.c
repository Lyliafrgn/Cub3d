/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:53:58 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/01 18:33:04 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_pars_sta(t_pars *pars_sta)
{

	pars_sta->empty = true;
	pars_sta->map = 0;
	ft_memset(pars_sta->txtr, false, sizeof(pars_sta->txtr));
	ft_memset(pars_sta->color, false, sizeof(pars_sta->color));
}

int	init_map(t_global *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		write(STDERR_FILENO, "Error: Could not allocate memory for map.\n", 42);
		exit(EXIT_FAILURE);
	}
	data->map->map_string = NULL;
	data->map->map = NULL;
	data->map->width = 0;
	data->map->height = 0;
	return (EXIT_SUCCESS);
}

int	init_player(t_global *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
	{
		free(data->map);
		write(STDERR_FILENO, "Error: Could not allocate memory for player.\n", 44);
		exit(EXIT_FAILURE);
	}
	data->player->x = 0.0f;
	data->player->y = 0.0f;
	data->player->angle = 0.0f;
	return (EXIT_SUCCESS);
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

void	initialize_img_colors(t_global *data)
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
}


int	initialize_structures(t_global *data)
{
	if (init_map(data) == EXIT_FAILURE)
	{
		write(STDERR_FILENO, "Error: Could not initialize map.\n", 34);
		exit(EXIT_FAILURE);
	}
	if (init_player(data) == EXIT_FAILURE)
	{
		write(STDERR_FILENO, "Error: Could not initialize player.\n", 37);
		exit(EXIT_FAILURE);
	}
	init_pars_sta(&data->pars_sta);
	initialize_img_colors(data);
	return (EXIT_SUCCESS);
}

