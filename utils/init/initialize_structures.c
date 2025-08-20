/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:53:58 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/20 17:17:02 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_pars_sta(t_pars *pars_sta)
{

	pars_sta->empty = true;
	pars_sta->map = 0;
	ft_memset(pars_sta->txtr, false, sizeof(pars_sta->txtr));
	ft_memset(pars_sta->color, false, sizeof(pars_sta->color));
}

static void	init_map(t_global *data)
{
	data->map.map_string = NULL;
	data->map.map = NULL;
	data->map.width = 0;
	data->map.height = 0;
/* 	data->left = 0;
	data->right = 0;
	data->up = 0;
	data->down = 0;
	data->cam_left = 0;
	data->cam_right = 0; */
}

static void	init_player(t_global *data) //initialisé en direction de l'est
{
	data->player.x = 1;
	data->player.y = 0.0;
	data->player.angle = 0.0;
	data->player.planex = 0.0;
	data->player.planey = 0.66;
	data->player.dirx = 1.0;
	data->player.diry = 0.0;
	data->player.ms = 0.055;
	data->player.rs = 0.02;
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
		init_img(&data->txtr[i++]);
	init_img(&data->screen);
	(init_color(data->colors[0]), init_color(data->colors[1]));
	init_ray(&data->ray);
	init_map(data);
	init_player(data);
	init_pars_sta(&data->pars_sta);
	ft_memset(&data->dir, 0, sizeof(t_dir));
}
//init_player(&data->player);


/* int	initialize_structures(t_global *data)
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
} */

