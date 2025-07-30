/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:21:43 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/30 17:39:27 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_permited_char_for_map(char c)
{
	if (c == ' ')
		return (2);
	if (c == '1')
		return (1);
	if (c == '0')
		return (0);
	return (-1);
}

bool	start_with_one(char *line)
{
	int	flag;

	flag = -1;
	while (line)
	{
		flag = is_permited_char_for_map(*line);
		if (flag == -1 || flag == 0)
			return (false);
		if (flag == 1)
			return (true);
		line++;
	}
	return (false);
}

bool	all_line_is_one(char *line)
{
	int	flag;

	flag = -1;
	while (line)
	{
		flag = is_permited_char_for_map(*line);
		if (flag == -1 || flag == 0)
			return (false);
		line++;
	}
	return (true);
}

bool	is_valide_map_line(char *line)
{
	int	flag;

	flag = -1;
	while (line)
	{
		flag = is_permited_char_for_map(*line);
		if (flag == -1)
			return (false);
		line++;
	}
	return (true);
}

bool	line_is_only_spaces(char *line)
{
	int	i;

	i = -1;
	if (!line)
		return (true);
	while (line[++i])
	{
		if (!ft_isspace(line[i]))
			return (false);
	}
	return (true);
}
