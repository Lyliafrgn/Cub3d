/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/08 00:54:52 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	draw_wall(t_data *data, int col, int start, int line_height) //reveenir dessus
{
	double			step;
	t_point			tex;
	double			texpos;
	int				pix;

	step = 1.0 * data->txtr[TX_NO].imgh / line_height;
	tex.x = ft_get_texx(data);
	texpos = (data->ray.start - (data->winh) / 2 + line_height / 2) * step;
	while (start < data->ray.end)
	{
		tex.y = (int)texpos & (data->txtr[TX_NO].imgh - 1);
		texpos += step;
		pix = ft_get_texpixel(data, tex.x, tex.y);
		if (data->ray.side == 1)
			pix = (pix >> 1) & 8355711;
		ft_pixel_put(data, col, start, pix);
		start++;
	}
	return (start);
}

static void	draw_column(t_data *data, int col)
{
	int			line_height;
	int			row;
	int			color;

	line_height = ft_get_line_height(data, col);

	data->ray.start = -line_height / 2 + (data->winh) / 2;
	if (data->ray.start < 0)
		data->ray.start = 0;
	data->ray.end = line_height / 2 + (data->winh) / 2;
	if (data->ray.end >= (data->winh))
		data->ray.end = (data->winh) - 1;
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


int	render_scene(t_data *data)
{
	int	col;

	col = 0;
	if (data->left || data->right || data->up || data->down || data->cam_left
		|| data->cam_right)
		ft_move(data);
	while (col < data->winw)
	{
		draw_column(data, col);
		col++;
	}
	if (data->mlx_ptr && data->win_ptr && data->screen.mlx_img)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->screen.mlx_img, 0, 0);
	return (0);
}
