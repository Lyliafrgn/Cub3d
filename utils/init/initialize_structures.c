/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:53:58 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/23 17:51:13 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_map(t_global *data)
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
	return (EXIT_SUCCESS);
}

int	init_player(t_global *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
	{
		free(data->map);
		write(STDERR_FILENO, "Error: Could not allocate memory for player.\n", 44);
		exit(EXIT_FAILURE);
	}
	data->player->x = 0.0f;
	data->player->y = 0.0f;
	data->player->angle = 0.0f;
	return (EXIT_SUCCESS);
}

int	initialize_structures(t_global *data)
{
	if (init_map(data) == EXIT_FAILURE)
	{
		write(STDERR_FILENO, "Error: Could not initialize map.\n", 34);
		exit(EXIT_FAILURE);
	}
	if (init_player(data) == EXIT_FAILURE)
	{
		write(STDERR_FILENO, "Error: Could not initialize player.\n", 37);
		exit(EXIT_FAILURE);
	}
	data->player = malloc(sizeof(t_player));
	if (!data->player)
	{
		write(STDERR_FILENO, "Error: Couldn't malloc for player.\n", 36);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
