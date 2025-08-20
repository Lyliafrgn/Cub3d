/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:48:48 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/20 17:40:36 by ofilloux         ###   ########.fr       */
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
/* Initialises the direction vector
 * + camera plane according to the player's char
 */
static void	set_player_direction(t_player *player, char dir)
{
	player->dirx = 0;
	player->diry = 0;
	player->planex = 0;
	player->planey = 0;
	if (dir == 'N')
	{
		player->diry = -1;
		player->planex = 0.66;
	}
	else if (dir == 'S')
	{
		player->diry = 1;
		player->planex = -0.66;
	}
	else if (dir == 'E')
	{
		player->dirx = 1;
		player->planey = 0.66;
	}
	else if (dir == 'W')
	{
		player->dirx = -1;
		player->planey = -0.66;
	}
}

static int	set_player_from_map(t_global *data, int col, int row)
{
	char	dir;

	data->player.x = col + 0.5;
	data->player.y = row + 0.5;
	dir = data->map.map[row][col];
	data->map.map[row][col] = '0';
	set_player_direction(&data->player, dir);
	return (SUCCESS);
}

int	ft_find_player(t_global *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->map.height)
	{
		col = 0;
		while (col < data->map.width)
		{
			if (ft_strchr("NSEW", data->map.map[row][col]))
			{
				if (set_player_from_map(data, col, row) == FAILURE)
					return (FAILURE);
			}
			col++;
		}
		row++;
	}
	return (SUCCESS);
}

/**
 * @note (actual_len + line_len + 2) ==> +2 for newline + null char
 */
int	save_map_line(t_map *map, char *line)
{
	// int		actual_len;
	// int		line_len;
	char	*tmp;

	//actual_len = ft_strlen(map->map_string);
	//line_len = ft_strlen(line);
	// tmp = malloc(sizeof(char) * (actual_len + line_len + 2));
	tmp = ft_strjoin(map->map_string, line);
	if (!tmp)
		return (EXIT_FAILURE);
	ft_free((void **) &map->map_string);
	map->map_string = tmp;
	return (EXIT_SUCCESS);
}

/**
 * @brief Process a map line.
 *
 * Logique :
 *			1.	si la ligne est déjà parsée (data->pars_sta.map < 0),
 *				on ne la traite pas.
 *			2.	parsing pas encore commencé et ligne vide --> ignoré
 *			3.	si parsing non commencé (data->pars_sta.map == 0)
 *				et ligne non valide, on ne la traite pas.
 *			Sinon, parsing est en cours OU doit être commencé.
 *				4.	on incrémente la hauteur de la map.
 *				5.	si c'est la 1ère ligne, on vérifie qu'elle est valide
 *				6.	si c'est pas la 1ère ligne, on vérifie les murs ouest et est.
 *				7.	si la ligne est entièrement composée de 1,
 *					on marque le parsing comme terminé
 *				8.	si la hauteur de la map dépasse la limite,
 *					on retourne une erreur.
 *
 * @param data Global data structure.
 * @param map Map structure.
 * @param line Line to process.
 * @return int EXIT_SUCCESS or EXIT_FAILURE.
 */
int	process_map_line(t_global *data, t_map *map, char *line)
{
	if (data->pars_sta.map < 0)
		return (EXIT_SUCCESS);
	if (data->pars_sta.map == 0 && data->pars_sta.empty)
		return (EXIT_SUCCESS);
	if (data->pars_sta.map != 1 && (!is_valide_map_line(line) || line_is_only_spaces(line)))
		return (EXIT_SUCCESS);
	data->pars_sta.map = 1;
	map->height++;
	if (map->height == 1 && !all_line_is_one(line))
		return (write(STDERR_FILENO, NORTH_WALL_INVALID, 46), EXIT_FAILURE);
	if (map->height > 1 && !start_with_one(line))
		return (write(STDERR_FILENO, WEST_WALL_INVALID, 46), EXIT_FAILURE);
	if (map->height > 1 && !finish_with_one(line))
		return (write(STDERR_FILENO, EAST_WALL_INVALID, 46), EXIT_FAILURE);
	if (map->height > 1 && all_line_is_one(line))
		data->pars_sta.map = -1;
	if (map->height > MAP_MAX_HEIGHT)
		return (write(STDERR_FILENO, MAP_TOO_HIGH, 41), EXIT_FAILURE);
	if (save_map_line(map, line) == EXIT_FAILURE)
		return (write(STDERR_FILENO, MAP_SAVING_FAILED, 29), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
	//if (!(data->pars_sta.empty || data->pars_sta.map >= 0))
	/* if (data->pars_sta.empty && data->pars_sta.map == 1)
	// pas vide mais dejà parsé
	{
		data->pars_sta.map = -1;
		return (0);
	} */
