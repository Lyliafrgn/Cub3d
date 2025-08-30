/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 23:02:57 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/30 11:41:11 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	in_wall(t_global *data, int row, int col)
{
	int	tile_x;
	int	tile_y;

	tile_x = 0;
	tile_y = 0;
	calculate_tile_x(data, col, &tile_x);
	calculate_tile_y(data, row, &tile_y);
	if (data->map.map[tile_y][tile_x] == '1')
		return (true);
	return (false);
}

int	sens_x_y(int tile_x_y, int tile_player_x_y)
{
	int	sx;

	sx = 0;
	if (tile_x_y < tile_player_x_y)
		sx = 1;
	else if (tile_x_y > tile_player_x_y)
		sx = -1;
	return (sx);
}

/**
 * @brief
 *	t_point	tile; // tile du pixel du cercle que l'on doit tester
 *	t_point	player_tile; // tile du joueur
 *	t_point	dist; // distance entre le joueur et le pixel du cercle
 *	t_point	sens;  // sens d'avancement tile.x et tile.y (+1 ou -1)
 *	t_point error; // x = error et y = 2 * error // erreur pour l'algorithme de Bresenham
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
 * 			Donc à chaque pas en x, tu accumules une erreur : combien la ligne est
 * 			décalée par rapport au centre de la case.
 * 			Si cette erreur devient trop grande → on compense en avançant d’un cran en y.
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
bool	cross_wall(t_global *data, int row, int col)
{
	t_point	tile;
	t_point	player_tile;
	t_point	dist;
	t_point	sens;
	t_point error;

	calculate_tile_x(data, col, &tile.x);
	calculate_tile_y(data, row, &tile.y);
	calculate_tile_x(data, data->minimap.player_x, &player_tile.x);
	calculate_tile_y(data, data->minimap.player_y, &player_tile.y);
	dist.x = abs(player_tile.x - tile.x);
	dist.y = abs(player_tile.y - tile.y);
	sens.x = sens_x_y(tile.x, player_tile.x);
	sens.y = sens_x_y(tile.y, player_tile.y);

	error.x = dist.x - dist.y;
	while (1)
	{
		if (player_tile.x == tile.x && player_tile.y == tile.y)
			break ;
		error.y = 2 * error.x;
		if (error.y > -dist.y)
		{
			error.x -= dist.y;
			tile.x += sens.x;
		}
		if (data->map.map[tile.y][tile.x] == '1')
			return (true);
		if (error.y < dist.x)
		{
			error.x += dist.x;
			tile.y += sens.y;
		}
		if (data->map.map[tile.y][tile.x] == '1')
			return (true);
	}
	return (false);
}

/** * @brief Draws the player as a filled circle on the minimap.
 * @note Soit deux points (x1, y1) et (x2, y2).
 * La distance euclidienne entre eux est :
 * d= racine ((x2−x1)2+(y2−y1)2)
 * --> on dessine le pixel que si la distance entre le pixel et le centre
 * du joueur est inférieure ou égale au rayon.
 */
void	draw_player(t_global *data, int col, int row)
{
	t_vec	player;
	double	radius;

	player.x = data->minimap.player_x;
	player.y = data->minimap.player_y;
	radius = M_MAP_PLAYER_SIZE / 2.0;
	if (pow(col - player.x, 2.0) + pow(row - player.y, 2.0) <= pow(radius, 2.0))
	{
		if (!in_wall(data, row, col) && !cross_wall(data, row, col))
			ft_pixel_put(data, col, row, data->minimap.player_color);
	}
}
