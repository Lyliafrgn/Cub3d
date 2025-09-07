/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:09:46 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/07 15:41:39 by ofilloux         ###   ########.fr       */
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
