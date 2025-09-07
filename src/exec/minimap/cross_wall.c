/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:07:04 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/07 13:37:01 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief converti un pixel (col,row) sur la minimap en coordonnées monde.
 */
static void	m_map_px_to_world(t_global *data, int col, int row, t_coor *player)
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

static void	set_dda_info(t_dda	*dda, t_global *data, int row, int col)
{
	dda->player.x = data->player.x;
	dda->player.y = data->player.y;
	m_map_px_to_world(data, col, row, &dda->pixel);
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

	set_dda_info(&dda, data, row, col);
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
		if (dda.current.x < 0 || dda.current.y < 0 \
			|| dda.current.x >= data->map.width \
			|| dda.current.y >= data->map.height \
			|| data->map.map[dda.current.y][dda.current.x] == '1')
			return (true);
	}
	return (false);
}

/**
 * @brief
 *	t_point	tile; // tile du pixel du cercle que l'on doit tester
 *	t_point	player_tile; // tile du joueur
 *	t_point	dist; // distance entre le joueur et le pixel du cercle
 *	t_point	sens;  // sens d'avancement tile.x et tile.y (+1 ou -1)
 *	t_point error; // x = error et y = 2 * error // erreur pour
 *	l'algorithme de Bresenham
 *
 * Algorithme de Bresenham
 * Savoir si une ligne entre le joueur et le pixel croise un mur
 *
 * Deux coordonnées dans une grille :
 * 		1. case de départ (x0, y0) = joueur
 * 		2. case d’arrivée (x1, y1) = pixel du cercle converti en case
 * 1. Calcules des différences :
 * 		dx = abs(x1 - x0);
 * 		dy = abs(y1 - y0);
 * 2. sens avances (+1 ou -1) :
 * 		sx = (x0 < x1) ? 1 : -1;
 * 		sy = (y0 < y1) ? 1 : -1;
 * 3. Initialiser une erreur
 * 		err = dx - dy;
 * 		Le rôle de err : on avances de gauche à droite dans une grille.
 * 			La vraie ligne n’est pas forcément exactement au milieu des cases.
 * 			Donc à chaque pas en x, tu accumules une erreur :
 * 			combien la ligne est décalée par rapport au centre de la case.
 * 			Si cette erreur devient trop grande
 * 				→ on compense en avançant d’un cran en y.
 * 			Si elle est trop petite → tu restes sur la même ligne en y.
 * 4. À chaque étape, pose d'un point (x,y)
 *		while (x != x1 || y != y1) {
 *			// Ici, tu vérifies si map[y][x] == '1' (mur)
 *			int e2 = 2 * err;
 *			if (e2 > -dy) { err -= dy; x += sx; }
 *			if (e2 < dx)  { err += dx; y += sy; }
 *		}
 * @note Il y avait pas mal de bugs liés à calculate_tile_x qui prenait un int
 * 		et qui générait des approximations lors de la conversion float -> int
 * @return true if cross a wall, false otherwise
 */
// bool	cross_wall(t_global *data, int row, int col)
// {
// 	t_point	tile;
// 	t_point	player_tile;
// 	t_point	dist;
// 	t_point	sens;
// 	t_point error;

// 	calculate_tile_x(data, col, &tile.x);
// 	calculate_tile_y(data, row, &tile.y);
// 	calculate_tile_x(data, data->minimap.player_x, &player_tile.x);
// 	calculate_tile_y(data, data->minimap.player_y, &player_tile.y);
// 	dist.x = abs(player_tile.x - tile.x);
// 	dist.y = abs(player_tile.y - tile.y);
// 	sens.x = sens_x_y(tile.x, player_tile.x);
// 	sens.y = sens_x_y(tile.y, player_tile.y);
// 	error.x = dist.x - dist.y;
// 	while (1)
// 	{
// 		if (player_tile.x == tile.x && player_tile.y == tile.y)
// 			break ;
// 		error.y = 2 * error.x;
// 		if (error.y > -dist.y)
// 		{
// 			error.x -= dist.y;
// 			tile.x += sens.x;
// 		}
// 		if (data->map.map[tile.y][tile.x] == '1')
// 			return (true);
// 		if (error.y < dist.x)
// 		{
// 			error.x += dist.x;
// 			tile.y += sens.y;
// 		}
// 		if (data->map.map[tile.y][tile.x] == '1')
// 			return (true);
// 	}
// 	return (false);
// }
