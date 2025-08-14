/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:56:10 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/14 15:47:12 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_global *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->txtr[i].mlx_img)
			mlx_destroy_image(data->mlx_ptr, data->txtr[i].mlx_img);
		ft_free((void **)&data->txtr[i].path);
		i++;
	}
}

void	free_map(t_map *map)
{
	int	i;

	if (!map->map)
		return ;
	i = 0;
	while (i < map->height)
	{
		ft_free((void **) &map->map[i]);
		i++;
	}
	ft_free((void **) &map->map);
	ft_free((void **) &map->map_string);
	map->height = 0;
	map->width = 0;
}

int	free_resources(t_global *data)
{
	free_textures(data);
	free_map(&data->map);
	return (EXIT_SUCCESS);
}
