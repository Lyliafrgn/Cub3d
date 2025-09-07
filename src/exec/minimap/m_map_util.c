/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_map_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:59:43 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/07 12:09:35 by ofilloux         ###   ########.fr       */
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

bool	not_in_mmap(int col, int row)
{
	return (col < M_MAP_OFFSET_X + M_MAP_BORDER \
		|| col > M_MAP_OFFSET_X + M_MAP_BORDER + M_MAP_SIZE \
		|| row < M_MAP_OFFSET_Y + M_MAP_BORDER \
		|| row > M_MAP_OFFSET_Y + M_MAP_BORDER + M_MAP_SIZE);
}

