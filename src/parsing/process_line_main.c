/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:49:59 by ofilloux          #+#    #+#             */
/*   Updated: 2025/10/08 11:30:48 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	invalid_line(char *line)
{
	if (!line)
		return (false);
	while (*line && *line == ' ')
		line++;
	if (!ft_strnstr(line, "NO ", 3) && !ft_strnstr(line, "SO ", 3) \
		&& !ft_strnstr(line, "WE ", 3) && !ft_strnstr(line, "EA ", 3) \
		&& !ft_strnstr(line, "F ", 2) && !ft_strnstr(line, "C ", 2) \
		&& !ft_strnstr(line, "0", 1) && !ft_strnstr(line, "1", 1) \
		&& !ft_strnstr(line, "\n", 1))
		return (true);
	return (false);
}

int	process_line(t_global *data, t_map *map, char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " \t");
	data->pars_sta.empty = line_is_only_spaces(line);
	if (invalid_line(tmp))
	{
		err_msg("Invalid config\n");
		free_resources(data);
		ft_free((void **) &tmp);
		return (EXIT_FAILURE);
	}
	if (process_texture_line(data, tmp) == EXIT_FAILURE)
		return (ft_free((void **) &tmp), EXIT_FAILURE);
	if (process_colore_line(data, tmp) == EXIT_FAILURE)
		return (ft_free((void **) &tmp), EXIT_FAILURE);
	ft_free((void **) &tmp);
	if (process_map_line(data, map, line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
