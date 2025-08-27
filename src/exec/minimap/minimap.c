/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:28:14 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/27 23:19:38 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_inner_offsets(t_mmap *mmap)
{
	int	diff;

	if (mmap->new_width_px > mmap->new_height_px)
	{
		diff = M_MAP_SIZE - mmap->new_height_px;
		mmap->inner_offset_y = diff / 2 + (diff % 2);
		mmap->inner_offset_x = 0;
	}
	else if (mmap->new_width_px < mmap->new_height_px)
	{
		diff = M_MAP_SIZE - mmap->new_width_px;
		mmap->inner_offset_x = diff / 2 + (diff % 2);
		mmap->inner_offset_y = 0;
	}
	else
	{
		mmap->inner_offset_x = 0;
		mmap->inner_offset_y = 0;
	}

}

// white border
/**
 * 	mmap->player_color = 0xFF0000; // red
	mmap->wall_color = 0x000000; // black
	mmap->floor_color = 0xCCCCCC; // light grey
	mmap->ray_color = 0x00FF00; // green
 */
void	init_minimap(t_global *data, t_mmap *mmap)
{
	mmap->border_color = 0xFFFFFF;
	mmap->player_size = 3;
	mmap->player_color = 0xFF0000; // red
	mmap->wall_color = 0x000000; // black
	mmap->floor_color = 0xCCCCCC; // light grey
	mmap->ray_color = 0x00FF00; // green
	mmap->scale = min_two_val((double) 150 / (data->map.width * TILE_SIZE), \
								(double) 150 / (data->map.height * TILE_SIZE));
	mmap->new_tile_size = TILE_SIZE * mmap->scale;
	if (mmap->new_tile_size < 1)
		mmap->new_tile_size = 1;
	mmap->new_width_px = data->map.width * data->minimap.new_tile_size;
	mmap->new_height_px = data->map.height * data->minimap.new_tile_size;
}

void	draw_minimap(t_global *data)
{
	int	row;
	int	col;
	//int	color;

	init_minimap(data, &data->minimap);
	calc_inner_offsets(&data->minimap);
	col = M_MAP_OFFSET_X;
	while (col < M_MAP_OFFSET_X + M_MAP_SIZE + 2 * M_MAP_BORDER)
	{
		row = M_MAP_OFFSET_Y;
		while (row < M_MAP_OFFSET_Y + M_MAP_SIZE + 2 * M_MAP_BORDER)
		{
			draw_borders(data, data->minimap, col, row);
			drawmap(data,col, row);
			draw_player(data, col,row);
			// draw rays
			row++;
		}
		col++;
	}
}
