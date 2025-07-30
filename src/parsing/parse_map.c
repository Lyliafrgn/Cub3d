/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:52:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/30 19:56:10 by ofilloux         ###   ########.fr       */
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

static void	update_do_read_status(bool *do_read, char *line)
{
	*do_read = true;
	if (!line)
		*do_read = false;
}



void	read_file(t_global *data, t_map *map)
{
	char	*line;
	int		ret;
	bool	do_read;

	do_read = true;
	while (do_read)
	{
		line = ft_get_next_line(map->fd);
		update_do_read_status(&do_read, line);
		if (!do_read)
			return (close(map->fd), ft_free((void **) &line), EXIT_SUCCESS);
		if (process_line(map, line) == EXIT_FAILURE)
		{
			perror("Err : invalid line");
			close(map->fd);
			ft_free((void **) &line);
			// free_resources
			exit(EXIT_FAILURE);
		}
		ft_free((void **) &line);
	}
	printf("saved map is :\n %s\n", map->map_string);//debug
}

int	parse_map_root(t_global *data, char *file_name)
{
	if (open_map_file(data, file_name) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	init_map(data->map);
	read_file(data, &data->map);
	// transform_map_data(&data->map) // remplir map_data grace a map_string
	//validate_map();
	printf("Starting the map parsing: %s\n", file_name);

	return (EXIT_SUCCESS);
}
