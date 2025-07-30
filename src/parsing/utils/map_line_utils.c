/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:21:43 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/30 19:46:13 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_permited_char_for_map(char c)
{
	if (c == ' ')
		return (EMPTY);
	if (c == '1')
		return (WALL);
	if (c == '0')
		return (IN);
	if (c == 'S')
		return (S);
	if (c == 'N')
		return (N);
	if (c == 'E')
		return (E);
	if (c == 'W')
		return (W);
	if (c == '\n')
		return (-2);
	return (-1);
}

bool	start_with_one(char *line)
{
	int	flag;

	flag = -1;
	while (line)
	{
		flag = is_permited_char_for_map(*line);
		if (flag != EMPTY || flag != WALL)
			return (false);
		if (flag == WALL)
			return (true);
		line++;
	}
	return (false);
}

bool	finish_with_one(char *line)
{
	int	i;
	int	flag;

	flag = -1;
	i = ft_strlen(line) - 1;
	while (i >= 0)
	{
		flag = is_permited_char_for_map(line[i]);
		if (flag != EMPTY || flag != WALL || line[i] != '/n')
			return (false);
		if (flag == WALL)
			return (true);
		i--;
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
		if (flag != EMPTY || flag != WALL || line[i] != '/n')
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
		if (!ft_isspace(line[i]) || line[i] != '/n')
			return (false);
	}
	return (true);
}
