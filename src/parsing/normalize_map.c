/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:20:13 by ofilloux          #+#    #+#             */
/*   Updated: 2025/10/01 16:17:03 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_line(t_map *map, char **tmp, int i)
{
	int	line_len;
	int	j;
	int	k;

	line_len = ft_strlen(map->map[i]);
	j = map->min_zero_pos - 1;
	k = 0;
	while (j < map->max_zero_pos + 2)
	{
		if (j >= line_len)
			(*tmp)[k++] = '1';
		else if (map->map[i][j] == ' ')
			(*tmp)[k++] = '1';
		else
			(*tmp)[k++] = map->map[i][j];
		j++;
	}
}

static inline bool	is_inmap_char(char c)
{
	return (c == '0' || c == 'S' || c == 'N' || c == 'E' || c == 'W');
}

void	get_min_max_zero_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->min_zero_pos = INT_MAX;
	map->max_zero_pos = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j] != '\0' && j <= INT_MAX)
		{
			if (is_inmap_char(map->map[i][j]))
			{
				if (j >= 0 && j < map->min_zero_pos)
					map->min_zero_pos = j;
				if (j >= 0 && j > map->max_zero_pos)
					map->max_zero_pos = j;
			}
			j++;
		}
		i++;
	}
	if (map->min_zero_pos == INT_MAX)
		map->min_zero_pos = 0;
}

void	get_min_one_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->min_one_pos = INT_MAX;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j] != '\0' && j <= INT_MAX)
		{
			if (map->map[i][j] == '1')
			{
				if (j >= 0 && j < map->min_one_pos)
					map->min_one_pos = j;
			}
			j++;
		}
		i++;
	}
	if (map->min_one_pos == INT_MAX)
		map->min_one_pos = 0;
}

/**
 * @brief
 * (map->max_zero_pos + 3) --> +3 car :
 * +1 pour le 0 qui est l'index du dernier 0
 * +1 pour le mur qui suit,
 * +1 pour le caractere null
 */
void	normalize_map(t_global *data, t_map *map)
{
	int		i;
	char	*tmp;

	i = 0;
	get_min_max_zero_pos(map);
	get_min_one_pos(map);
	while (i < map->height)
	{
		tmp = malloc(sizeof(char) * (map->max_zero_pos + 3 - map->min_one_pos));
		if (!tmp)
			return ;
		copy_line(map, &tmp, i);
		tmp[map->max_zero_pos + 2 - map->min_one_pos] = '\0';
		ft_free((void **) &map->map[i]);
		map->map[i] = tmp;
		i++;
	}
	data->map.width = map->max_zero_pos + 2 - map->min_one_pos;
}
