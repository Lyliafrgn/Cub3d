/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_root.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:12:35 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/04 22:22:11 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//RULES FOR A MAP TO BE VALID
/*✅	1.	a 0 or letter can't be surrounded by a space or '\0'
*✅	2.	The Map should contains at least one letter or one '0'
*✅	3.	The map should contains one letter and only one
*✅	4.	The map should be of dimensions inferior to MAP_MAX_HEIGHT
*		and MAP_MAX_WIDTH
*/

/**
 * @brief Checks if the map contains at least one'0'
 * 		or a player letters (N, S, E, W).
 * 		If it doens't meet this condition, it is not a valid map:
 * 		there is no room for the player to spawn.
 * @return EXIT_SUCCESS validation passed, EXIT_FAILURE otherwise.
 * @note This function is used to validate the map after parsing.
 */
int	map_has_zero_or_letter(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == '0' || map->map[i][j] == 'N' ||
				map->map[i][j] == 'S' || map->map[i][j] == 'E' ||
				map->map[i][j] == 'W')
				return (EXIT_SUCCESS);
			j++;
		}
		i++;
	}
	return (EXIT_FAILURE);
}

/**
 * @brief check that the map has at least one letter or a zero
 * 		to start the validation.
 * 		It also insure that the map is not filled up with spaces
 */
int	map_has_one_letter(t_map *map)
{
	int	i;
	int	j;
	int	letter_count;

	i = 0;
	j = 0;
	letter_count = 0;
	while (i < map->width)
	{
		while (map->map[i][j] != 0)
		{
			if (ok_char_for_map(map->map[i][j] >= 2) && map->map[i][j] != ' ')
				letter_count++;
			if (letter_count > 1)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	if (letter_count == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	validate_map(t_global *data)
{
	if (map_height_is_valid(data->map) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (map_width_is_valid(data->map) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (map_has_zero_or_letter(data->map) != EXIT_SUCCESS)
		return (write(STDERR_FILENO, "Err: Map : no space for spawn\n", 31), EXIT_FAILURE);
	if (map_has_one_letter(data->map) != EXIT_SUCCESS)
		return (write(STDERR_FILENO, "Err: Map : 0 or more than one spawn\n", 37), EXIT_FAILURE);
	if (check_wrong_surrounding_letters(data->map) != EXIT_SUCCESS)
		return (write(STDERR_FILENO, "Err: Map : missing wall or empty inside\n", 41), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
