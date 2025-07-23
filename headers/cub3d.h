/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:00:38 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/23 18:07:53 by ly               ###   ########.fr       */
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
# include <math.h>		// sin, cos, tan, sqrt, fabs

# include <stdbool.h>
# include <limits.h>

///CUSTOMS HEADERS
# include "structures.h"	// Structures for player, map, and global data
# include "utils.h"			// Init and resource managment (frees)
# include "parsing.h"		// Map parsing functions
# include "exec.h"			// Game execution functions
# include "sig.h"			// Signal handling functions

# include "libft.h"

# define SUCCESS 0
# define FAILURE -1

# define TX_NORTH 0
# define TX_SOUTH 1
# define TX_EAST  2
# define TX_WEST  3
# define TX_FRAME 4

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
