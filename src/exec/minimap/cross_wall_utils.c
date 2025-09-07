/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_wall_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:13:54 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/07 13:18:26 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_tiles_coor(t_coor player, t_coor pixel,
						t_tile *current, t_tile *target)
{
	current->x = (int)floor(player.x);
	current->y = (int)floor(player.y);
	target->x = (int)floor(pixel.x);
	target->y = (int)floor(pixel.y);
}

void	set_dist(t_coor player, t_coor pixel, t_vec *dist)
{
	dist->x = pixel.x - player.x;
	dist->y = pixel.y - player.y;
}

void	set_dir(t_point *dir, t_vec dist)
{
	dir->x = -1;
	if (dist.x > 0)
		dir->x = 1;
	dir->y = -1;
	if (dist.y > 0)
		dir->y = 1;
}

void	set_delta_dist(t_vec dist, t_vec *delta_dist)
{
	if (dist.x == 0)
		delta_dist->x = 1e30;
	else
		delta_dist->x = fabs(1 / dist.x);
	if (dist.y == 0)
		delta_dist->y = 1e30;
	else
		delta_dist->y = fabs(1 / dist.y);
}

void	set_side_dist(t_dda *dda, t_vec dist, t_vec *side_dist)
{
	if (dist.x > 0)
		side_dist->x = (dda->current.x + 1 - dda->player.x) * dda->delta_dist.x;
	else
		side_dist->x = (dda->player.x - dda->current.x) * dda->delta_dist.x;
	if (dist.y > 0)
		side_dist->y = (dda->current.y + 1 - dda->player.y) * dda->delta_dist.y;
	else
		side_dist->y = (dda->player.y - dda->current.y) * dda->delta_dist.y;
}
