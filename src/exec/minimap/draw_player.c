/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 23:02:57 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/28 09:13:03 by ofilloux         ###   ########.fr       */
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


/** * @brief Draws the player as a filled circle on the minimap.
 * @note Soit deux points (x1, y1) et (x2, y2).
 * La distance euclidienne entre eux est :
 * d= racine ((x2−x1)2+(y2−y1)2)
 * --> on dessine le pixel que si la distance entre le pixel et le centre
 * du joueur est inférieure ou égale au rayon.
 */
void	draw_player(t_global *data, int col, int row)
{
	double	player_x;
	double	player_y;
	double	radius;

	player_x = data->minimap.player_x;
	player_y = data->minimap.player_y;
	radius = M_MAP_PLAYER_SIZE / 2.0;
	if (pow(col - player_x, 2.0) + pow(row - player_y, 2.0) <= pow(radius, 2.0))
	{
		if (!in_wall(data, row, col))
			ft_pixel_put(data, col, row, data->minimap.player_color);
	}
}
