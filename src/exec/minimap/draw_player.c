/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 23:02:57 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/27 23:26:27 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_global *data, int col, int row)
{
	double	player_x;
	double	player_y;

	player_x = M_MAP_OFFSET_Y + M_MAP_BORDER + data->minimap.inner_offset_x \
				+ data->player.y * data->minimap.new_tile_size;
	player_y = M_MAP_OFFSET_X + M_MAP_BORDER + data->minimap.inner_offset_y \
				+ data->player.x * data->minimap.new_tile_size;

	// Mettre player x et y directement dans la structure minimap pour pouvoir les utiliser lorsque je dessinerai le champ de vision du joueur sur la minimap

	if (data->player.y * data->minimap.scale == row - M_MAP_OFFSET_Y - M_MAP_BORDER \
		- data->minimap.inner_offset_y \
		&& data->player.x * data->minimap.scale == row - M_MAP_OFFSET_X - M_MAP_BORDER \
		- data->minimap.inner_offset_x)
			ft_pixel_put(data, col, row, data->minimap.player_color);
}
