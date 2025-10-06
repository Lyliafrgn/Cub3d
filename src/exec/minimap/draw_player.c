/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 23:02:57 by ofilloux          #+#    #+#             */
/*   Updated: 2025/10/06 15:10:05 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

/** * @brief Draws the player as a filled circle on the minimap.
 * @note Soit deux points (x1, y1) et (x2, y2).
 * La distance euclidienne entre eux est :
 * d= racine ((x2−x1)2+(y2−y1)2)
 * --> on dessine le pixel que si la distance entre le pixel et le centre
 * du joueur est inférieure ou égale au rayon.
 */
// void	draw_player(t_global *data, int col, int row)
// {
// 	t_vec	player;
// 	double	radius;

// 	player.x = data->minimap.player_x;
// 	player.y = data->minimap.player_y;
// 	radius = M_MAP_PLAYER_RAD / 2.0;
// 	if (pow(col - player.x, 2.0) + pow(row - player.y, 2.0) <= pow(radius, 2.0))
// 	{
// 		if (!in_wall(data, row, col) && !cross_wall(data, row, col))
// 			ft_pixel_put(data, col, row, data->minimap.player_color);
// 	}
// }

void	normalize_angle(double *angle)
{
	while (*angle > M_PI)
		*angle -= 2 * M_PI;
	while (*angle < -M_PI)
		*angle += 2 * M_PI;
}

bool	not_player_vue_cirle(t_vec player, int row, int col)
{
	return (sqr((double)col - player.x) + sqr((double)row - player.y)
		> sqr((double)M_MAP_PLAYER_VUE)
		|| sqr(col - player.x) + sqr(row - player.y)
		<= sqr(M_MAP_PLAYER_RAD));
}

void	draw_player(t_global *data, int col, int row)
{
	t_vec	player;
	double	player_angle;
	double	angle_pixel_to_player;
	double	diff;

	player.x = data->minimap.player_x;
	player.y = data->minimap.player_y;
	if (sqr(col - player.x) + sqr(row - player.y) <= sqr(M_MAP_PLAYER_RAD))
	{
		if (!in_wall(data, row, col) && !cross_wall2(data, row, col))
			ft_pixel_put(data, col, row, data->minimap.player_color);
	}
	if (not_player_vue_cirle(player, row, col))
		return ;
	player_angle = atan2(data->player.diry, data->player.dirx);
	angle_pixel_to_player = atan2(row - player.y, col - player.x);
	diff = angle_pixel_to_player - player_angle;
	normalize_angle(&diff);
	if (fabs(diff) > M_PI / 3.0 / 2.0)
		return ;
	if (!in_wall(data, row, col) && !cross_wall2(data, row, col))
		ft_pixel_put(data, col, row, data->minimap.ray_color);
}
