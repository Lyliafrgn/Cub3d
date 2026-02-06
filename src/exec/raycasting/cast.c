/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/25 08:41:12 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*Moves forward one square at a time,
vertically or horizontally
(depending on which is closer (sidedist.x or sidedist.y))
*when there is a wall (value > ‘0’), it stops
*+ if wall touched is vertical (side = 0) if horizontal (side = 1)
*(influences the lighting and texture later)
*/
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

/**
 * @brief Sends a ray from player's pos to forward
 * finds where it hits a wall
 * calculates how far away that wall is
 *
 * camerax = x-coordinate of the column in window, mapped to range [-1, 1]
 * mapx et mapy
 * 		= position of the player in the map grid (as int)
 * 		= Cellule de départ du rayon
 * ray.dir.x and ray.dir.y = direction of the ray
 *
 * @returns the wall height to draw on a column of the screen
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

/**
 * @brief Calculates the height of the wall to be drawn:
 * @return height = window height / wall distance
*/
int	ft_get_line_height(t_global *data, int col)
{
	ft_cast_ray(data, col);
	return ((int)(data->winh / data->ray.perp_wall_dist));
}
