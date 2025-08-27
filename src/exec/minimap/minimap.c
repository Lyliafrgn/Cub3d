/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:28:14 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/27 18:58:31 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


double	min_two_val(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
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
	mmap->border_size = 2;
	mmap->offset_x = 8;
	mmap->offset_y = 8;
	mmap->map_frame_width_px = 150;
	mmap->map_frame_heigh_px = 150;

	mmap->player_size = 2;
	mmap->player_color = 0xFF0000; // red
	mmap->wall_color = 0x000000; // black
	mmap->floor_color = 0xCCCCCC; // light grey
	mmap->ray_color = 0x00FF00; // green

	mmap->scale = min_two_val((double) 150 / (data->map.width * TILE_SIZE), \
								(double) 150 / (data->map.height * TILE_SIZE));
	mmap->new_tile_size = (int) floor(TILE_SIZE * mmap->scale);
	if (mmap->new_tile_size < 1)
		mmap->new_tile_size = 1;
}


void	draw_borders(t_global *data, t_mmap mmap, int col, int row)
{
	int	outer_right;
	int	outer_bottom;

	outer_right = mmap.offset_x + mmap.map_frame_width_px + 2 * mmap.border_size;
	outer_bottom = mmap.offset_y + mmap.map_frame_heigh_px + 2 * mmap.border_size;
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


bool	not_in_mmap(t_global *data, int col, int row)
{
	return (col < data->minimap.offset_x + data->minimap.border_size \
		|| col > data->minimap.offset_x + data->minimap.border_size \
		+ data->minimap.map_frame_width_px \
		|| row < data->minimap.offset_y + data->minimap.border_size \
		|| row > data->minimap.offset_y + data->minimap.border_size \
		+ data->minimap.map_frame_heigh_px);
}

void calculate_tilex(t_global *data, int col, int *tile_x)
{
	int	new_width_px;

	new_width_px = data->map.width * data->minimap.new_tile_size;
	*tile_x = (col - data->minimap.offset_x - data->minimap.border_size) \
				* data->map.width / new_width_px;
	if (*tile_x < 0)
		*tile_x = 0;
	if (*tile_x >= data->map.width)
		*tile_x = data->map.width - 1;
}

void calculate_tiley(t_global *data, int row, int *tile_y)
{
	int	new_height_px;

	new_height_px = data->map.height * data->minimap.new_tile_size;
	*tile_y = (row - data->minimap.offset_y - data->minimap.border_size) \
				* data->map.height / new_height_px;
	if (*tile_y < 0)
		*tile_y = 0;
	if (*tile_y >= data->map.height)
		*tile_y = data->map.height - 1;
}

void	drawmap(t_global *data, int col, int row)
{
	int	new_width_px;
	int	new_height_px;
	int	tile_x;
	int	tile_y;

	if (not_in_mmap(data, col, row))
		return ;

	new_width_px = data->map.width * data->minimap.new_tile_size;
	new_height_px = data->map.height * data->minimap.new_tile_size;
	tile_x = (col - data->minimap.offset_x - data->minimap.border_size) * data->map.width / new_width_px;
	tile_y = (row - data->minimap.offset_y - data->minimap.border_size) * data->map.height / new_height_px;
	if (tile_x < 0)
		tile_x = 0;
	if (tile_x >= data->map.width)
		tile_x = data->map.width - 1;
	if (tile_y < 0)
		tile_y = 0;
	if (tile_y >= data->map.height)
		tile_y = data->map.height - 1;
	if (data->map.map[tile_y][tile_x] == '1')
		ft_pixel_put(data, col, row, data->minimap.wall_color);
	else if (data->map.map[tile_y][tile_x] == '0')
		ft_pixel_put(data, col, row, data->minimap.floor_color);
	else
		ft_pixel_put(data, col, row, data->minimap.wall_color);

	// centrer la minimap,
}

void	draw_minimap(t_global *data)
{
	int	row;
	int	col;
	//int	color;

	init_minimap(data, &data->minimap);
	col = data->minimap.offset_x;
	while (col < data->minimap.offset_x \
		+ data->minimap.map_frame_width_px + 2 * data->minimap.border_size)
	{
		row = data->minimap.offset_y;
		while (row < data->minimap.offset_y \
		+ data->minimap.map_frame_heigh_px + 2 * data->minimap.border_size)
		{
			draw_borders(data, data->minimap, col, row);
			drawmap (data,col, row);
			// draw player
			// draw rays
			row++;
		}
		col++;
	}
}
