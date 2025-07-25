/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:55:30 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/23 20:12:02 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../headers/cub3d.h"

static int  upload_textures(t_global *data)
{
	t_img	*img;
	int		i;

	i = 0;
	while(i < 4)
	{
		img = &(data->txtr[i]);
		if (!img->path)
			return (FAILURE); // missing textr err
		img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, img->path, 
			&img->imgw, &img->imgh);
		if (!img->mlx_img)
			return(FAILURE); // msg erreur
		img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->llen, &img->endian);
		if (!img->addr)
			return (FAILURE); // msg erreur
		i++;
	}
	return (SUCCESS);
}

int upload_img(t_global *data)
{
    if (upload_textures(data) == FAILURE)
		return (FAILURE);
	data->screen.mlx_img = mlx_new_image(data->mlx_ptr, data->winw, data->winh);
	if (!data->screen.mlx_img)
		return (FAILURE);
	data->screen.addr = mlx_get_data_addr(data->screen.mlx_img,
			&data->screen.bpp, &data->screen.llen,
			&data->screen.endian);
	if (!data->screen.addr)
		return (FAILURE);
	return (SUCCESS);
}

//AJOUTER FT DESTROY IMAGE