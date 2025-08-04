/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sourrounding_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:18:13 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/04 21:38:02 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_left()
{

}

int	check_right()
{

}

int	check_up()
{

}

int	check_down()
{

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
		return (write(STDERR_FILENO, "Err: map contains errors\n", 26), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
