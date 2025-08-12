/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_erreurs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:21:17 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/12 11:55:39 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_ERREURS_H
# define MSG_ERREURS_H

//void	initialize_structures(t_global *data)
# define MAP_PARS_ERR		"Err: Map not parsed well.\n"

//map parsing errors
# define NORTH_WALL_INVALID	"Err: outer nothern wall contain invalid char\n"
# define SOUTH_WALL_INVALID	"Err: outer southern wall contain invalid char\n"
# define EAST_WALL_INVALID	"Err: outer eastern wall contain invalid char\n"
# define WEST_WALL_INVALID	"Err: outer western wall contain invalid char\n"
# define MAP_TOO_WIDE		"Err: map width exceeds maximum allowed\n"
# define MAP_TOO_HIGH		"Err: map height exceeds maximum allowed\n"
# define MAP_INVALID		"Err: map is invalid\n"
# define MAP_NOT_CLOSED		"Err: map is not closed\n"
# define MAP_NOT_FOUND		"Err: map not found\n"
# define MAP_SAVING_FAILED	"Err: saving map line failed\n"

//int	init_player(t_global *data)
# define PLAYER_MALLOC_ERROR	"Err: player memory allocation failed\n"

#endif
