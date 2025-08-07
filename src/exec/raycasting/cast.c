/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/08 01:34:25 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*Fonctions à créer :
cast_single_ray(...)
*/

static void	ft_set_step(t_data *data, t_point *step)
{
	step->x = 1;
	if (data->ray.dir.x < 0)
		step->x = -1;
	step->y = 1;
	if (data->ray.dir.y < 0)
		step->y = -1;
}

static void	ft_set_sidedist(t_data *data, t_vec *sidedist, t_vec deltadist)
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

static void	ft_hit_wall(t_data *data, t_vec *side, t_vec *delta, t_point step)
{
	while (1)
	{
		if (side->x < side->y)
		{
			side->x += delta->x;
			data->ray.mapx += step.x;
			data->ray.side = 0;
		}
		else
		{
			side->y += delta->y;
			data->ray.mapy += step.y;
			data->ray.side = 1;
		}
		if (data->ray.mapx < 0 || data->ray.mapy < 0 || data->ray.mapx >= data->map->width
			|| data->ray.mapy >= data->map->height)
			break ;
		if (data->map[data->ray.mapy][data->ray.mapx] > '0')
			break ;
	}
}

int	ft_get_line_height(t_data *data, int col)
{
	double      	camerax;
	t_vec			sidedist;
	t_vec			deltadist;
	t_point			step;

    camerax = 2 * (col) / (double)data->winw - 1;
	data->ray.mapx = (int)data->player.x;
	data->ray.mapy = (int)data->player.y;
	data->ray.dir.x = data->player.dirx + (data->player.planex) * (camerax);
	data->ray.dir.y = data->player.diry + (data->player.planey) * (camerax);
	deltadist.x = 1e30;
	if (data->ray.dir.x != 0)
		deltadist.x = fabs(1 / data->ray.dir.x);
	deltadist.y = 1e30;
	if (data->ray.dir.y != 0)
		deltadist.y = fabs(1 / data->ray.dir.y);
	ft_set_step(data, &step);
	ft_set_sidedist(data, &sidedist, deltadist);
	ft_hit_wall(data, &sidedist, &deltadist, step);
	data->ray.perp_wall_dist = (sidedist.y - deltadist.y);
	if (data->ray.side == 0)
		data->ray.perp_wall_dist = (sidedist.x - deltadist.x);
    if (data->ray.perp_wall_dist == 0)
	    data->ray.perp_wall_dist = 0.0001;
	return ((int)(data->winh / data->ray.perp_wall_dist));
}
