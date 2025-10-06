/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 23:00:35 by ofilloux          #+#    #+#             */
/*   Updated: 2025/10/06 15:14:31 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_tile_x(t_global *data, double col, int *tile_x)
{
	double	new_width_px;

	*tile_x = 0;
	new_width_px = data->minimap.new_width_px;
	*tile_x = (int)floor((((double)((col - M_MAP_OFFSET_X - M_MAP_BORDER
							- data->minimap.inner_offset_x)
						* data->map.width) / new_width_px)));
	if (*tile_x < 0)
		*tile_x = 0;
	if (*tile_x >= data->map.width)
		*tile_x = data->map.width - 1;
}

void	calculate_tile_y(t_global *data, double row, int *tile_y)
{
	double	new_height_px;

	*tile_y = 0;
	new_height_px = data->minimap.new_height_px;
	*tile_y = (int)floor((((double)((row - M_MAP_OFFSET_Y - M_MAP_BORDER
							- data->minimap.inner_offset_y)
						* data->map.height) / new_height_px)));
	if (*tile_y < 0)
		*tile_y = 0;
	if (*tile_y >= data->map.height)
		*tile_y = data->map.height - 1;
}

void	drawmap(t_global *data, int col, int row)
{
	int	tile_x;
	int	tile_y;

	if (not_in_mmap(col, row))
		return ;
	calculate_tile_x(data, col, &tile_x);
	calculate_tile_y(data, row, &tile_y);
	if (data->map.map[tile_y][tile_x] == '1')
		ft_pixel_put(data, col, row, data->minimap.wall_color);
	else if (data->map.map[tile_y][tile_x] == '0')
		ft_pixel_put(data, col, row, data->minimap.floor_color);
	else
		ft_pixel_put(data, col, row, data->minimap.wall_color);
}
