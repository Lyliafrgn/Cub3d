/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:52:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/23 18:54:00 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_map_file(t_global *data, const char *file_name)
{
	data->map->fd = open(file_name, O_RDONLY);
	if (data->map->fd < 0)
	{
		perror("Error opening map file");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	read_file(t_map *map)
{
	char	*line;
	int		ret;

	while ((ret = ft_get_next_line(map->fd, &line)) > 0)
	{
		// Process the line and fill map_data, width, and height
		free(line); // Free the line after processing
	}
	if (ret < 0)
	{
		perror("Error reading map file");
		close(map->fd);
		exit(EXIT_FAILURE);
	}
	close(map->fd);
}

int	parse_map_root(t_global *data, char *file_name)
{
	if (open_map_file(data, file_name) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	init_map(data->map);
	read_file(&data->map);
	printf("Starting the map parsing: %s\n", file_name);

	return (EXIT_SUCCESS);
}
