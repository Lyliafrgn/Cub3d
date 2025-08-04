/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:48:48 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/04 20:32:29 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/**
 *  0 pour les espaces vides,
 *  1 pour les murs,
 *  N,S,E ou W
 *
 *
*/

/**
 * @note (actual_len + line_len + 2) ==> +2 for newline + null char
 */
int	save_map_line(t_map *map, char *line)
{
	int		actual_len;
	int		line_len;
	char	*tmp;

	actual_len = ft_strlen(map->map_string);
	line_len = ft_strlen(line);
	tmp = malloc(sizeof(char) * (actual_len + line_len + 2));
	if (!tmp)
		return (EXIT_FAILURE);
	tmp = ft_strjoin(map->map_string, line);
	ft_free((void **) &map->map_string);
	map->map_string = tmp;
	return (EXIT_SUCCESS);
}

int	process_map_line(t_global *data, t_map *map, char *line)
{
	if (!(data->pars_sta.empty || data->pars_sta.map >= 0))
		return (0);
	if (!is_valide_map_line(line) || line_is_only_spaces(line))
		return (0);
		//return (write(STDERR_FILENO, "Err: outer nothern wall contain\n", 33), EXIT_FAILURE);
	data->pars_sta.map = 1;
	map->height++;
	if (map->height == 1 && !all_line_is_one(line))
		return (write(STDERR_FILENO, "Err: outer nothern wall contain invalid char\n", 46), EXIT_FAILURE);
	if (map->height > 1 && !start_with_one(line))
		return (write(STDERR_FILENO, "Err: outer western wall contain invalid char\n", 46), EXIT_FAILURE);
	if (map->height > 1 && !finish_with_one(line))
		return (write(STDERR_FILENO, "Err: outer eastern wall contain invalid char\n", 46), EXIT_FAILURE);
	if (map->height > 1 && all_line_is_one(line))
		data->pars_sta.map = -1;
	if (map->height > MAP_MAX_HEIGHT)
		return (write(STDERR_FILENO, "Err: map too big\n", 18), EXIT_FAILURE);
	if (save_map_line(map, line) == EXIT_FAILURE)
		return (write(STDERR_FILENO, "Err: saving map line\n", 22), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
