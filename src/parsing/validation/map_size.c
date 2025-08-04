/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:09:46 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/04 16:43:51 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_height_is_valid(t_map *map)
{
	if (map->height < 3)
		return (write(STDERR_FILENO, "Err: map is too small\n", 23), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	map_width_is_valid(t_map *map)
{
	if (map->width < 3)
		return (write(STDERR_FILENO, "Err: map is too small\n", 23), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
