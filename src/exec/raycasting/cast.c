/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/24 02:42:02 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	ft_hit_wall(t_global *data, t_vec *side, t_vec *delta, t_point step)
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
		if (data->ray.mapx < 0 || data->ray.mapy < 0
			||data->ray.mapx >= data->map.width
			|| data->ray.mapy >= data->map.height)
			break ;
		if (data->map.map[data->ray.mapy][data->ray.mapx] > '0')
			break ;
	}
}
/*Sends a ray from player's pos to forward
**finds where it hits a wall
**calculates how far away that wall is
**returns the wall height to draw on a column of the screen
*/

static void	ft_cast_ray(t_global *data, int col)
{
	double			camerax;
	t_vec			sidedist;
	t_vec			deltadist;
	t_point			step;

	camerax = 2 * (col) / (double)data->winw - 1;
	data->ray.mapx = (int)data->player.x;
	data->ray.mapy = (int)data->player.y;
	data->ray.dir.x = data->player.dirx + (data->player.planex) * (camerax);
	data->ray.dir.y = data->player.diry + (data->player.planey) * (camerax);
	ft_init_deltadist(&data->ray, &deltadist);
	ft_set_step(data, &step);
	ft_set_sidedist(data, &sidedist, deltadist);
	ft_hit_wall(data, &sidedist, &deltadist, step);
	ft_choose_wall_texture(&data->ray);
	if (data->ray.side == 0)
		data->ray.perp_wall_dist = (sidedist.x - deltadist.x);
	else
		data->ray.perp_wall_dist = sidedist.y - deltadist.y;
	if (data->ray.perp_wall_dist == 0)
		data->ray.perp_wall_dist = 0.0001;
}

int	ft_get_line_height(t_global *data, int col)
{
	ft_cast_ray(data, col);
	return ((int)(data->winh / data->ray.perp_wall_dist));
}
