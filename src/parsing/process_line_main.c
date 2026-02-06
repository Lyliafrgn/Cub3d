/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:49:59 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/04 17:14:17 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	process_line(t_global *data, t_map *map, char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " \t");
	data->pars_sta.empty = line_is_only_spaces(line);
	if (process_texture_line(data, tmp) == EXIT_FAILURE)
		return (ft_free((void **) &tmp), EXIT_FAILURE);
	if (process_colore_line(data, tmp) == EXIT_FAILURE)
		return (ft_free((void **) &tmp), EXIT_FAILURE);
	ft_free((void **) &tmp);
	if (process_map_line(data, map, line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return(EXIT_SUCCESS);
}
