/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:52:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/04 22:40:51 by ofilloux         ###   ########.fr       */
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



int	read_file(t_global *data, t_map *map)
{
	char	*line;
	//int		ret;
	bool	do_read;

	do_read = true;
	while (do_read)
	{
		line = ft_get_next_line(map->fd);
		update_do_read_status(&do_read, line);
		if (!do_read)
			return (close(map->fd), ft_free((void **) &line), EXIT_SUCCESS);
		if (process_line(data, map, line) == EXIT_FAILURE)
		{
			write(STDERR_FILENO, "Err : invalid line\n", 20);
			close(map->fd);
			ft_free((void **) &line);
			// free_resources
			exit(EXIT_FAILURE);
		}
		ft_free((void **) &line);
	}
	return (0);
}

/**
 * @brief fonction that prints the maps for debugging purpose
 * @debug
 */
void	print_maps(t_global *data)
{
	printf("saved map is :\n%s\n", data->map->map_string);
	printf("Map width: %d, height: %d\n", data->map->width, data->map->height);
	printf("Map content:\n");
	print_pp_char_arr(data->map->map);
	printf("____________\n");
}

int	parse_map_root(t_global *data, char *file_name)
{
	if (open_map_file(data, file_name) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	//init_map(data->map); //@info normalement deja initialised
	read_file(data, data->map);
	data->map->map = ft_split(data->map->map_string, '\n');
	print_maps(data);
	if (data->map && validate_map(data) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/// a 0 can't be surrounded by a space

// Only one letter is possible

// calculate max width and max height from 0 and letters. it can'b be inferior to 3 (map to small to place the player)
 // a map with only the player is possible
// in other words, it is validated if other conditions are met + if there is at least one letter in the map, or one 0

/// a map shouldn't contain empty space. --> add parsing state IN, OUT, WALL

// a map size should be of maximum 1000x1000
