/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/08 01:14:20 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*revenir sur ces fonctions */

void	ft_pixel_put(t_data *data, int c, int r, int color)
{
	char	*dst;

	if (c < 0 || c >= data->winw || r < 0 || r >= data->winh)
		return ;
	dst = data->screen.addr + (r * data->screen.llen + c
			* (data->screen.bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_get_texpixel(t_data *data, int texx, int texy) //revenir dessus
{
	t_img	tex;
	char	*color;
	int		wall;

	if (data->ray.side == 1)
	{
		wall = TX_NO;
		if (data->player.y <= data->ray.mapy)
			wall = TX_SO;
	}
	else
	{
		wall = TX_EA;
		if (data->player.x <= data->ray.mapx)
			wall = TX_WE;
	}
	tex = data->txtr[wall];
	if (texx < 0 || texx >= tex.imgw || texy < 0 || texy >= tex.imgh)
		return (0);
	color = (tex.addr + (texy * tex.llen + texx * (tex.bpp / 8)));
	return (*(unsigned int *)color);
}

int	ft_get_texx(t_data *data)
{
	double	wallx;
	int		texx;

	if (data->ray.side == 0)
		wallx = data->player.y + data->ray.perp_wall_dist * data->ray.dir.y;
	else
		wallx = data->player.x + data->ray.perp_wall_dist * data->ray.dir.x;
	wallx -= floor((wallx)); //changer name                           
	texx = (int)(wallx * (double)(data->txtr[TX_NO].imgw));
	if (data->ray.side == 0 && data->ray.dir.x > 0)
		texx = data->txtr[TX_NO].imgh - texx - 1;
	if (data->ray.side == 1 && data->ray.dir.y < 0)
		texx = data->txtr[TX_NO].imgw - texx - 1;
	return (texx);
}
