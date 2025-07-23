/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:43:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/21 17:47:29 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_player
{
	float	x;		// Player's x position
	float	y;		// Player's y position
	float	angle;	// Player's direction angle
}	t_player;

typedef struct s_map
{
	char	**map_data;	// 2D array for the map
	int		width;		// Width of the map
	int		height;		// Height of the map
}	t_map;

typedef struct s_global
{
	t_map		*map;
	t_player	*player;
}	t_global;

#endif
