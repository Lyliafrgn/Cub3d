/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:55:30 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/23 09:48:54 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	upload_textures(t_global *data)
{
	t_img	*img;
	int		i;

	i = 0;
	while (i < 4)
	{
		img = &(data->txtr[i]);
		if (!img->path)
			return (ft_err("Err: missing path to texture", data));
		img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, img->path,
				&img->imgw, &img->imgh);
		if (!img->mlx_img)
			return (ft_err("Err: file to image failed", data));
		img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
				&img->llen, &img->endian);
		if (!img->addr)
			return (ft_err("Err: failed to get image data", data));
		i++;
	}
	return (SUCCESS);
}

int	upload_img(t_global *data)
{
	if (upload_textures(data) == FAILURE)
		return (ft_err("Err: failed uploading textures", data));
	data->screen.mlx_img = mlx_new_image(data->mlx_ptr, data->winw, data->winh);
	if (!data->screen.mlx_img)
		return (ft_err("Err: failed to create screen image", data));
	data->screen.addr = mlx_get_data_addr(data->screen.mlx_img,
			&data->screen.bpp, &data->screen.llen,
			&data->screen.endian);
	if (!data->screen.addr)
		return (ft_err("Err: failed to get data address of image", data));
	return (SUCCESS);
}

/*
@Debug
*
static void	print_char_at(t_map *map_struct, int row, int col)
{
	if (!map_struct || !map_struct->map)
	{
		printf("Map is NULL\n");
		return;
	}
	if (row < 0 || row >= map_struct->height)
	{
		printf("Row index %d is out of bounds\n", row);
		return;
	}
	if (col < 0 || col >= (int)strlen(map_struct->map[row]))
	{
		printf("Column %d is out of bounds in row %d\n", col, row);
		return;
	}

	printf("Character at [%d][%d] is '%c'\n", row, col, map_struct->map[row][col]);
}*/


/* OLD VERSION
static int  upload_textures(t_global *data)
{
	t_img	*img;
	int		i;

	i = 0;
	while(i < 4)
	{
		img = &(data->txtr[i]);
		if (!img->path)
			return (ft_err("missing path", data));
		print_maps(data); // @debug
		//print_char_at(&data->map, 3, 4);
		//print_char_at(&data->map, 4, 3);
		img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, img->path, \
			&img->imgw, &img->imgh);
		if (!img->mlx_img)
		{
			ft_err("Err:mlx_xpm_file_to_image : ", data);
			printf("Texture err : %s\n", img->path);
			return (FAILURE);
		}
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
		return (ft_err("failed uploading textures", data));
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
	printf("Character at [%d][%d] is '%c'\n", row, col,
	map_struct->map[row][col]);
}*/
