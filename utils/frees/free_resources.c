/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:56:10 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/26 19:48:13 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	free_textures(t_global *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->txtr[i].mlx_img)
		{
			mlx_destroy_image(data->mlx_ptr, data->txtr[i].mlx_img);
			data->txtr[i].mlx_img = NULL;
		}
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

static void	free_screen(t_global *data)
{
	if (data->screen.mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->screen.mlx_img);
		data->screen.mlx_img = NULL;
	}
}

static void	free_window(t_global *data)
{
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
}

int	free_resources(t_global *data)
{
	free_textures(data);
	free_map(&data->map);
	free_screen(data);
	free_window(data);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	return (EXIT_SUCCESS);
}
