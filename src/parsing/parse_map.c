/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:52:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/26 18:46:13 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_map_file(t_global *data, const char *file_name)
{
	data->map.fd = open(file_name, O_RDONLY);
	if (data->map.fd < 0)
	{
		perror("Error opening map file");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static inline void	update_do_read_status(bool *do_read, char *line)
{
	*do_read = true;
	if (!line)
		*do_read = false;
}

int	read_file(t_global *data, t_map *map)
{
	char	*line;
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
			err_msg("Err : invalid line\n");
			close(map->fd);
			ft_free((void **) &line);
			free_resources(data);
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
	printf("saved map is :\n%s\n", data->map.map_string);
	printf("Map width: %d, height: %d\n", data->map.width, data->map.height);
	printf("Map content:\n");
	print_pp_char_arr(data->map.map);
	printf("____________\n");
	printf("Map textur: \nNO: `%s`,\nSO: `%s`,\nEA: `%s`,\nWE: `%s`\n",
		data->txtr[TX_NO].path, data->txtr[TX_SO].path,
		data->txtr[TX_EA].path, data->txtr[TX_WE].path);
	printf("colors : floor: %d, %d, %d; ceiling: %d, %d, %d\n\n",
		data->colors[0][0], data->colors[0][1], data->colors[0][2],
		data->colors[1][0], data->colors[1][1], data->colors[1][2]);
}
///width --> mettre la width maximale

int	parse_map_root(t_global *data, char *file_name)
{
	if (!is_cub_extension(file_name))
		return (err_msg("Error: invalid file extension, must be .cub\n"));
	if (open_map_file(data, file_name) != EXIT_SUCCESS)
		return (err_msg(MAP_NOT_FOUND));
	read_file(data, &data->map);
	data->map.map = ft_split(data->map.map_string, '\n');
	if (validate_map(data) != EXIT_SUCCESS)
		return (err_msg(MAP_INVALID));
	normalize_map(data, &data->map);
	if (ft_find_player(data) != SUCCESS)
		return (err_msg(FIND_PLAYER_FAILED));
	return (EXIT_SUCCESS);
}

/// a 0 can't be surrounded by a space

// Only one letter is possible

// calculate max width and max height from 0 and letters.
//  it can'b be inferior to 3 (map to small to place the player)
//   a map with only the player is possible
// in other words, it is validated if other conditions are met
// + if there is at least one letter in the map, or one 0

/// a map shouldn't contain empty space. --> add parsing state IN, OUT, WALL

// a map size should be of maximum 1000x1000
