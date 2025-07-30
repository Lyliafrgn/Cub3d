/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:48:48 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/30 18:50:39 by ofilloux         ###   ########.fr       */
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
	tmp = ft_strjoin3(map->map_string, line, "\n");
	ft_free((void **) &map->map_string);
	map->map_string = tmp;
}

int	process_map_line(t_global *data, t_map *map, char *line)
{
	if (!(data.parsing_state.empty || data.parsing_state.map >= 0))
		retrun (EXIT_FAILURE);

	if (is_valide_map_line(line) && map.parsing_state == 1)
	if (start_with_one(line))
		map->height++;
	if (map->height == 1 && !all_line_is_one(line))
		return (write(stderr, "Err: outer nothern wall contain\n", 33), EXIT_FAILURE);
	if (is_valide_map_line(line) && save_map_line(map, line) == EXIT_FAILURE);
		return (write(stderr, "Err: saving map line\n", 22), EXIT_FAILURE);
}
