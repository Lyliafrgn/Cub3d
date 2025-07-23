/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:53:58 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/21 18:55:23 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_structures(t_global *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		write(STDERR_FILENO, "Error: Could not allocate memory for map.\n", 42);
		exit(EXIT_FAILURE);
	}
	data->map->map_data = NULL;
	data->map->width = 0;
	data->map->height = 0;
	data->player = malloc(sizeof(t_player));
	if (!data->player)
	{
		free(data->map);
		write(STDERR_FILENO, "Error: Couldn't malloc for player.\n", 36);
		exit(EXIT_FAILURE);
	}
	data->player->x = 0.0f;
	data->player->y = 0.0f;
	data->player->angle = 0.0f;
}
