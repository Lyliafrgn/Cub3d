/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:07:04 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/07 12:59:29 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief converti un pixel (col,row) sur la minimap en coordonnées monde.
 */
static inline void	minimap_px_to_world(t_global *data, int col, int row, t_coor *player)
{
	double	tile_size;
	double	offx;
	double	offy;

	tile_size = data->minimap.new_tile_size;
	offx = M_MAP_OFFSET_X + M_MAP_BORDER + data->minimap.inner_offset_x;
	offy = M_MAP_OFFSET_Y + M_MAP_BORDER + data->minimap.inner_offset_y;
	player->x = (col - offx) / tile_size;
	player->y = (row - offy) / tile_size;
}


void	set_tiles_coor(t_coor player, t_coor pixel, t_tile *current, t_tile *target)
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

void set_side_dist(t_dda *dda, t_vec dist,t_vec *side_dist)
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

void set_dda_info(t_dda	*dda, t_global *data, int row, int col)
{
	dda->player.x = data->player.x;
	dda->player.y = data->player.y;
	minimap_px_to_world(data, col, row, &dda->pixel);
	set_tiles_coor(dda->player, dda->pixel, &dda->current, &dda->target);
	set_dist(dda->player, dda->pixel, &dda->dist);
	set_dir(&dda->dir, dda->dist);
	set_delta_dist (dda->dist, &dda->delta_dist);
	set_side_dist(dda, dda->dist, &dda->side_dist);
}
/**
 * @brief Vérifie si la ligne entre le joueur et le pixel (col,row)
 * traverse un mur en utilisant un algorithme DDA (Digital Differential Analyzer)
 * (grid traversal).
 * player = coordonate of the player in pixel
 * @return true si un mur bloque la ligne de vue, false sinon.
 */
bool	cross_wall2(t_global *data, int row, int col)
{
	t_dda	dda;
	// t_coor	player;
	// t_coor	pixel;
	// t_tile	current;
	// t_tile	target;
	// t_vec	dist;
	// t_point	dir;
	// t_vec	delta_dist;
	// t_vec	side_dist;

	set_dda_info(&dda, data, row , col);
	// minimap_px_to_world(data, col, row, &pixel);
	// set_tiles_coor(data->player, pixel, &current, &target);
	// set_dist(data->player, pixel, &dist);
	// set_dir(&dir, dist);
	// set_delta_dist (dist, &delta_dist);
	// if (dist.x > 0)
	// 	side_dist.x = (current.x + 1 - player.x) * delta_dist.x;
	// else
	// 	side_dist.x = (player.x - current.x) * delta_dist.x;
	// if (dist.y > 0)
	// 	side_dist.y = (current.y + 1 - player.y) * delta_dist.y;
	// else
	// 	side_dist.y = (player.y - current.y) * delta_dist.y;
	while (dda.current.x != dda.target.x || dda.current.y != dda.target.y)
	{
		if (dda.side_dist.x < dda.side_dist.y)
		{
			dda.side_dist.x += dda.delta_dist.x;
			dda.current.x += dda.dir.x;
		}
		else
		{
			dda.side_dist.y += dda.delta_dist.y;
			dda.current.y += dda.dir.y;
		}
		if (dda.current.x < 0 || dda.current.y < 0 || dda.current.x >= data->map.width
			|| dda.current.y >= data->map.height
			|| data->map.map[dda.current.y][dda.current.x] == '1')
			return (true);
	}
	return (false);
}
