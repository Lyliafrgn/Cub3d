/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:00:38 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/07 14:05:03 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>		// printf, perror
# include <stdlib.h>	// malloc, free, exit
# include <unistd.h>	// write, read, close
# include <fcntl.h>		// open
# include <string.h>	// strerror
# include <errno.h>		// errno
# include <math.h>		// sin, cos, tan, sqrt, fabs# include
# include <X11/X.h>
# include <X11/keysym.h>

# include <stdbool.h>
# include <limits.h>

///CUSTOMS HEADERS
# include "structures.h"	// Structures for player, map, and global data
# include "utils.h"			// Init and resource managment (frees)
# include "parsing.h"		// Map parsing functions
# include "exec.h"			// Game execution functions
# include "msg_erreurs.h"	// Error messages

# include "libft.h"
# include "mlx.h"

# define SUCCESS 0
# define FAILURE -1

# define TX_NO 0
# define TX_SO 1
# define TX_EA 2
# define TX_WE 3

# define R 0
# define G 1
# define B 2

# define TILE_SIZE 128// Size in pixels

/// Define a max size for the map so we don't overflow use to much memory
# define MAP_MAX_HEIGHT 500
# define MAP_MAX_WIDTH 500

//MINIMAP
# define _USE_MATH_DEFINES
# define M_MAP_SIZE 300.0 // in pixels // size of the minimap square
# define M_MAP_OFFSET_X 8 // margin from the window edge to the minimap border
# define M_MAP_OFFSET_Y 8 // offset from the top edge of the window
# define M_MAP_BORDER 2 // size of the border around the minimap
# define M_MAP_PLAYER_RAD 5 // size of the player on the minimap
# define M_MAP_PLAYER_VUE 50.0 // size of the player view lines on the minimap

// MIMIMAP COLORS
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define LIGHT_GREY 0xCCCCCC
# define LIGHT_GREEN 0x7DFF7D

enum e_map_elem
{
	IN,
	WALL,
	S,
	N,
	E,
	W,
	EMPTY
};

# define FLOOR 0
# define CEILING 1

#endif

// Authorized functions

/*
* ==========================
*  FILE MANAGEMENT FUNCTIONS
* ==========================
//	open,
//	close,
//	read,
//	write,
//	printf,

* ==========================
*  MEMORY MANAGEMENT FUNCTIONS
* ==========================
//	malloc,
//	free,

* ==========================
*  Error Management & exit
* ==========================
//	perror,
//	strerror,
//	exit

* ==========================
*  LIB MATH FUNCTIONS
* ==========================
• Toutes les fonctions de
la lib math (-lm man man 3
math)

* ==========================
* MINILIBX FUNCTIONS
* ==========================
• Toutes les fonctions de la
MinilibX

*/
