/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surrounding_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:18:13 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/04 22:17:05 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_left(t_map *map, int i, int j)
{
	if (j == 0)
		return (EXIT_FAILURE);
	if (ft_isspace(map->map[i][j - 1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_right(t_map *map, int i, int j)
{
	if (j == (int) ft_strlen(map->map[i]) - 1)
		return (EXIT_FAILURE);
	if (ft_isspace(map->map[i][j + 1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_up(t_map *map, int i, int j)
{
	if (i <= 0)
		return (0);
	if (j >= (int) ft_strlen(map->map[i - 1]))
		return (EXIT_FAILURE);
	if (ft_isspace(map->map[i - 1][j]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_down(t_map *map, int i, int j)
{
	if (i >= map->height)
		return (0);
	if (j >= (int) ft_strlen(map->map[i + 1]))
		return (EXIT_FAILURE);
	if (map->map[i + 1] && ft_isspace(map->map[i + 1][j]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_wrong_surrounding_letters(t_map *map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (i < map->width)
	{
		while (map->map[i][j] != 0)
		{
			if ((ok_char_for_map(map->map[i][j] >= 2) && map->map[i][j] != ' ') \
					|| map->map[i][j] == 0)
			{
				flag += check_up(map, i, j) + check_down(map, i, j);
				flag += check_left(map, i, j) + check_right(map, i, j);
			}
			j++;
		}
		i++;
	}
	if (flag > 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
