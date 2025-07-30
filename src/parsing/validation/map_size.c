/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:09:46 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/30 19:13:13 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_height_is_valid(t_map *map)
{
	if (map->height < 3)
		return (write(stderr, "Err: map is too small\n", 33), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	map_width_is_valid(t_map *map)
{
	if (map->width < 3)
		return (write(stderr, "Err: map is too small\n", 33), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
