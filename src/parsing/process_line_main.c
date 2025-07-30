/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:49:59 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/30 18:54:46 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"




int	process_line(t_global *data, t_map *map, char *line)
{
	if (process_texture_line(data, line) == -1)
		return (EXIT_FAILURE);
	if (process_colore_line(data, line) == -1)
		return (EXIT_FAILURE);
	if (process_map_line(data, map, line) == -1)
		return (EXIT_FAILURE);
}
