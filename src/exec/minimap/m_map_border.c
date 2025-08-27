/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_map_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:58:21 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/27 22:59:13 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_borders(t_global *data, t_mmap mmap, int col, int row)
{
	int	outer_right;
	int	outer_bottom;

	outer_right = M_MAP_OFFSET_X + M_MAP_SIZE + 2 * M_MAP_BORDER;
	outer_bottom = M_MAP_OFFSET_Y + M_MAP_SIZE + 2 * M_MAP_BORDER;
	if (col < M_MAP_OFFSET_X \
		|| col > outer_right \
		|| row < M_MAP_OFFSET_Y \
		|| row > outer_bottom)
		return ;
	if (col >= M_MAP_OFFSET_X + M_MAP_BORDER \
		&& col <= outer_right - M_MAP_BORDER \
		&& row >= M_MAP_OFFSET_Y + M_MAP_BORDER \
		&& row <= outer_bottom - M_MAP_BORDER)
		return ;
	ft_pixel_put(data, col, row, mmap.border_color);
}
