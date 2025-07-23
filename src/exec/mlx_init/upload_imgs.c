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
		img = &(data->path[i]);
		img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->path[i], 
			&img->imgw, &img->imgh);
		if (!img->mlx_img)
			(return(FAILURE));
		img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->llen, &img->endian);
		if (!img->mlx_img)
		(return(FAILURE));
		i++;
	}
	return (SUCCESS);
}

int upload_img(t_global *data)
{
	int	i;

	i = 0;
	if (!data->path[i])
		return (ft_err("Missing texture path", FAILURE));
    if (upload_textures(data) == FAILURE)
		return (FAILURE);
	data->path[TX_FRAME].mlx_img = mlx_new_image(data->mlx_ptr, data->winw, data->winh);
	if (dat->path[TX_FRAME].mlx_img == NULL)
		return (FAILURE);
	data->path[TX_FRAME].addr = mlx_get_data_addr(data->path[TX_FRAME].mlx_img,
			&data->img[TX_FRAME].bpp, &data->path[TX_FRAME].llen,
			&data->img[TX_FRAME].endian);
	if (data->path[TX_FRAME].addr = NULL)
		return (FAILURE);
	return (SUCCESS);
}
