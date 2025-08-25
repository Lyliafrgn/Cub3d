/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/25 18:30:04 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/**
 * @brief draw a line on the col column with the correct texture, correct height,
 * and a light effect.
*/
static int	draw_wall(t_global *data, int col, int start, int line_height)
{
	double			step;
	t_point			tex;
	double			texpos;
	int				pix;
	t_img			*teximg;

	teximg = &data->txtr[data->ray.wall];
	step = 1.0 * teximg->imgh / line_height;
	tex.x = ft_get_texx(data);
	texpos = (data->ray.start - (data->winh) / 2 + line_height / 2) * step;
	while (start < data->ray.end)
	{
		tex.y = (int)texpos;
		if (tex.y >= 0 && tex.y < teximg->imgh)
		{
			pix = ft_get_texpixel(data, tex.x, tex.y);
			if (data->ray.side == 1)
				pix = (pix >> 1) & 0x7F7F7F;
			ft_pixel_put(data, col, start, pix);
		}
		texpos += step;
		start++;
	}
	return (start);
}

/*
 * Converts an RGB color represented as an array of 3 integers
 * (red, green, blue) into a single 24-bit integer color value.
 * Each color component is packed into one byte:
 * [Red << 16 | Green << 8 | Blue]
 */
static int	ft_rgb_to_int(int color[3])
{
	int	red;
	int	green;
	int	blue;

	red = color[0] << 16;
	green = color[1] << 8;
	blue = color[2];
	return (red | green | blue);
}

/**
 * @brief Calculate the start and end pixel positions
 * 	for drawing the wall slice on the screen.
 * 	Ensures that the start and end positions are within the screen bounds.
 * 	If not, it clamps them.
 */
static void	calculate_wall_start_end_screen(t_global *data, int line_height)
{
	data->ray.start = (data->winh / 2) - (line_height / 2);
	if (data->ray.start < 0)
		data->ray.start = 0;
	data->ray.end = (data->winh / 2) + (line_height / 2);
	if (data->ray.end >= (data->winh))
		data->ray.end = (data->winh) - 1;
}

/*
For each column, it projects a ray and draws:
The ceiling, the wall and the floor
*/
static void	draw_column(t_global *data, int col)
{
	int			line_height;
	int			row;
	int			color;

	line_height = ft_get_line_height(data, col);
	calculate_wall_start_end_screen(data, line_height);
	if (data->ray.start > data->ray.end)
		return ;
	row = 0;
	color = ft_rgb_to_int(data->colors[CEILING]);
	while (row < data->ray.start)
		ft_pixel_put(data, col, row++, color);
	row = draw_wall(data, col, data->ray.start, line_height);
	color = ft_rgb_to_int(data->colors[FLOOR]);
	while (row < data->winh)
		ft_pixel_put(data, col, row++, color);
}

/** Updates the player's position/direction
 *Calculates and draws each column of pixels
 *Displays the final buffer in the window
 */
int	render_scene(t_global *data)
{
	int	col;

	col = 0;
	ft_move(data);
	while (col < data->winw)
	{
		draw_column(data, col);
		col++;
	}
	draw_minimap(data);
	if (data->mlx_ptr && data->win_ptr && data->screen.mlx_img)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->screen.mlx_img, 0, 0);
	return (0);
}
