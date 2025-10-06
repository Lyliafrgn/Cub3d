/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:09:46 by ofilloux          #+#    #+#             */
/*   Updated: 2025/10/06 16:22:35 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_height_is_valid(t_map *map)
{
	if (map->height > MAP_MAX_HEIGHT)
		return (err_msg("Err: map too big\n"));
	return (EXIT_SUCCESS);
}

static void	get_max_width(t_map *map)
{
	int		i;
	long	j;

	i = 0;
	map->width = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			j++;
			if (j >= INT_MAX)
			{
				map->width = (int) j;
				break ;
			}
		}
		if (j > map->width)
			map->width = (int) j;
		i++;
	}
}

int	map_width_is_valid(t_map *map)
{
	get_max_width(map);
	if (map->width > MAP_MAX_WIDTH)
		return (err_msg("Err: map too big\n"));
	return (EXIT_SUCCESS);
}

int	validate_colors(t_global *data)
{
    if (!data->pars_sta.color[0] || !data->pars_sta.color[1])
        return (err_msg("Err: floor or ceiling color not specified\n"));
    return (EXIT_SUCCESS);
}
