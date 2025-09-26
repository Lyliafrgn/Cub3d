/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:06:41 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/26 17:17:20 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Normalize an angle to the range [-π, π].
 * @param angle Pointer to the angle in radians to be normalized.
*/
// void	normalize_angle(double *angle)
// {
// 	while (*angle > M_PI)
// 		*angle -= 2 * M_PI;
// 	while (*angle < -M_PI)
// 		*angle += 2 * M_PI;
// }

// bool	not_player_vue_cirle(t_vec player, int row, int col)
// {
// 	return (pow((double)col - player.x, 2.0) + pow((double)row - player.y, 2.0)
// 			> pow((double)M_MAP_PLAYER_VUE, 2.0)
// 			||
// 			pow(col - player.x, 2.0) + pow(row - player.y, 2.0)
// 			<= pow(M_MAP_PLAYER_RAD / 2.0, 2.0));
// }

//
// 	double	angle;	// Player's direction angle
// 	double	dirx;	// Direction (vecteur unitaire) du joueur sur x
// 	double	diry;	// Direction du joueur sur y

	//angle entre chaque rayons
	//angle de départ = angle du joueur - (FOV/2)
	//angle d'arrivée = angle du joueur + (FOV/2)

	// direction du joureur
	// double dir_x = data->player.dirx;
	// double dir_y = data->player.diry;

	// Normalisation dans [-π, π]
	// while (diff > M_PI)
	// 	diff -= 2 * M_PI;
	// while (diff < -M_PI)
	// 	diff += 2 * M_PI;
	//fov = M_PI/3.0; // 60°
// void	draw_rays(t_global *data, int row, int col)
// {
// 	double	player_angle;
// 	double	angle_pixel_to_player;
// 	t_vec	player;
// 	double	diff;

// 	player.x = data->minimap.player_x;
// 	player.y = data->minimap.player_y;
// 	if (not_player_vue_cirle(player, row, col))
// 		return ;
// 	player_angle = atan2(data->player.diry, data->player.dirx);
// 	normalize_angle(&player_angle);
// 	angle_pixel_to_player = atan2(row - player.y, col - player.x);
// 	normalize_angle(&angle_pixel_to_player);
// 	diff = angle_pixel_to_player - player_angle;
// 	normalize_angle(&diff);
// 	if (fabs(diff) > M_PI / 3.0 / 2.0)
// 		return ;
// 	if (!in_wall(data, row, col) && !cross_wall(data, row, col))
// 		ft_pixel_put(data, col, row, data->minimap.ray_color);
// }
