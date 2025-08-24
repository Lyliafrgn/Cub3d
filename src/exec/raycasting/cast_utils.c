/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/24 02:29:19 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_choose_wall_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x > 0)
			ray->wall = TX_EA;
		else
			ray->wall = TX_WE;
	}
	else
	{
		if (ray->dir.y > 0)
			ray->wall = TX_SO;
		else
			ray->wall = TX_NO;
	}
}

void	ft_set_step(t_global *data, t_point *step)
{
	step->x = 1;
	if (data->ray.dir.x < 0)
		step->x = -1;
	step->y = 1;
	if (data->ray.dir.y < 0)
		step->y = -1;
}

void	ft_set_sidedist(t_global *data, t_vec *sidedist, t_vec deltadist)
{
	if (data->ray.dir.x < 0)
		sidedist->x = (data->player.x - data->ray.mapx) * deltadist.x;
	else
		sidedist->x = (data->ray.mapx + 1.0 - data->player.x) * deltadist.x;
	if (data->ray.dir.y < 0)
		sidedist->y = (data->player.y - data->ray.mapy) * deltadist.y;
	else
		sidedist->y = (data->ray.mapy + 1.0 - data->player.y) * deltadist.y;
	if (sidedist->x == 0)
		sidedist->x = 0.1;
	if (sidedist->y == 0)
		sidedist->y = 0.1;
}

void	ft_init_deltadist(t_ray *ray, t_vec *deltadist)
{
	if (ray->dir.x == 0)
		deltadist->x = 1e30;
	else
		deltadist->x = fabs(1 / ray->dir.x);

	if (ray->dir.y == 0)
		deltadist->y = 1e30;
	else
		deltadist->y = fabs(1 / ray->dir.y);
}
