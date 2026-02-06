/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:09:08 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/12 11:33:15 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_img *img)
{
	img->path = NULL;
	img->mlx_img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->llen = 0;
	img->endian = 0;
	img->imgw = 64;
	img->imgh = 64;
}

void	init_color(int color[3])
{
	color[R] = -1;
	color[G] = -1;
	color[B] = -1;
}
//ft_memset(color, -1, sizeof(int) * 3);
