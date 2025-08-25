/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:28:14 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/25 19:32:06 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// white border
void	init_minimap(t_global *data, t_mmap *mmap)
{
	mmap->border_color = 0xFFFFFF;
	mmap->border_size = 2;
	mmap->offset_x = 8;
	mmap->offset_y = 8;
	mmap->map_width_px = 100;
	mmap->map_height_px = 100;
	mmap->step_x = mmap->map_width_px / data->map.width;
	mmap->step_y = mmap->map_height_px / data->map.height;
	mmap->player_size = 2;
	mmap->player_color = 0xFF0000; // red
	mmap->wall_color = 0x000000; // black
	mmap->floor_color = 0xCCCCCC; // light grey
	mmap->ray_color = 0x00FF00; // green
}


void	draw_borders(t_global *data, t_mmap mmap, int col, int row)
{
	int	outer_right;
	int	outer_bottom;

	outer_right = mmap.offset_x + mmap.map_width_px + 2 * mmap.border_size;
	outer_bottom = mmap.offset_y + mmap.map_height_px + 2 * mmap.border_size;
	if (col < mmap.offset_x \
		|| col > outer_right \
		|| row < mmap.offset_y \
		|| row > outer_bottom)
		return ;
	if (col >= mmap.offset_x + mmap.border_size \
		&& col <= outer_right - mmap.border_size \
		&& row >= mmap.offset_y + mmap.border_size \
		&& row <= outer_bottom - mmap.border_size)
		return ;
	ft_pixel_put(data, col, row, mmap.border_color);
}

void	draw_minimap(t_global *data)
{
	int	row;
	int	col;
	//int	color;

	init_minimap(data, &data->minimap);
	col = 0;
	while (col < data->winw)
	{
		row = 0;
		while (row < data->winh)
		{
			draw_borders(data, data->minimap, col, row);
			//drawmap
			row++;
		}
		col++;
	}
}
