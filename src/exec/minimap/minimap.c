/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:28:14 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/07 12:02:46 by ofilloux         ###   ########.fr       */
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
	mmap->player_color = 0xFF0000; // red
	mmap->wall_color = 0x000000; // black
	mmap->floor_color = 0xCCCCCC; // light grey
	mmap->ray_color = 0x7DFF7D; // green
	mmap->scale = min_two_val((double)M_MAP_SIZE / (data->map.width * TILE_SIZE), \
								(double)M_MAP_SIZE / (data->map.height * TILE_SIZE));
	mmap->new_tile_size = TILE_SIZE * mmap->scale;
	if (mmap->new_tile_size < 1)
		mmap->new_tile_size = 1;
	mmap->new_width_px = data->map.width * mmap->new_tile_size;
	mmap->new_height_px = data->map.height * mmap->new_tile_size;
	calc_inner_offsets(&data->minimap);
	mmap->player_x = M_MAP_OFFSET_X + M_MAP_BORDER + mmap->inner_offset_x \
				+ (double)(data->player.x * mmap->new_tile_size);
	mmap->player_y = M_MAP_OFFSET_Y + M_MAP_BORDER + mmap->inner_offset_y \
				+ (double)(data->player.y * mmap->new_tile_size);
}

void	draw_minimap(t_global *data)
{
	int	row;
	int	col;

	init_minimap(data, &data->minimap);
	col = M_MAP_OFFSET_X;
	while (col < M_MAP_OFFSET_X + M_MAP_SIZE + 2 * M_MAP_BORDER)
	{
		row = M_MAP_OFFSET_Y;
		while (row < M_MAP_OFFSET_Y + M_MAP_SIZE + 2 * M_MAP_BORDER)
		{
			draw_borders(data, data->minimap, col, row);
			drawmap(data, col, row);
			draw_player(data, col, row);
			//draw_rays(data, col, row);
			row++;
		}
		col++;
	}
}
