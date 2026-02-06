/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:43:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/26 19:02:59 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "parsing.h"

typedef struct s_player
{
	double	x;		// Player's x position
	double	y;		// Player's y position
	double	angle;	// Player's direction angle
	double	dirx;	// Direction (vecteur unitaire) du joueur sur x
	double	diry;	// Direction du joueur sur y
	double	planex;	// Composante x du plan de caméra (perpendiculaire à dir)
	double	planey;	// Composante y du plan de caméra
	double	ms;	// Vitesse de déplacement (move speed)
	double	rs;	// Vitesse de rotation (rotation speed)
}	t_player;

typedef struct s_map
{
	int		fd;			// File descriptor for the map file
	char	*map_string;	//to save map_line when exploring map file
	char	**map;	// 2D array for the map
	int		width;		// Width of the map
	int		height;		// Height of the map
}	t_map;

typedef struct s_img
{
	char	*path; // path to txtr file
	void	*mlx_img; // ptr to mlx's image (returned by mlx_xpm_file_to_image)
	char	*addr; // memory addr of the img
	int		bpp; // bits per pixel
	int		llen; // lenght of a line of pixels in the img (in octets)
	int		endian; //If 0 = little endian (RGB order), if 1 = big endian (RGB)
	int		imgw; // width of the img
	int		imgh; // Height of the img
}	t_img;

//Represents a vector (x, y) in floating point coordinates
typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

//Represents a point (x, y) in integer coordinates
typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_ray
{
	t_vec	dir; // Ray direction
	t_vec	sidedist; // Dist from ray's pos to first sides x y
	t_vec	deltadist; // Dist ray must travel from side x/y to the next one
	double	perp_wall_dist;	//Perp dist between player and wall touched by a ray
	int		mapx; // Current pos of ray on the map (integer)
	int		mapy;
	int		stepx; // Step of the ray on x on grid for DDA: +1 or -1
	int		stepy;
	int		side; // Hitted side : 0 = NS (No/SO), 1 = EW (EA/WE)
	int		start; // Vertical pixel of wall start (top)
	int		end;// Vertical pixel of wall end (bottom)
	int		wall;
}	t_ray;

typedef struct s_dir
{
	int			left;
	int			right;
	int			up;
	int			down;
	int			cam_left;
	int			cam_right;
}	t_dir;

typedef struct s_global
{
	t_map		map;
	t_player	player;
	t_pars		pars_sta; // to know in which type of line we are
	t_ray		ray; // rayon principal pour le raycasting
	t_img		txtr[4]; // NO, SO, EA, WE
	t_img		screen;
	void		*mlx_ptr;
	void		*win_ptr;
	int			winw;
	int			winh;
	int			colors[2][3]; // 2= floor and ceiling & 3= colors (RGB)
	t_dir		dir; // to know which direction the player is moving
}	t_global;

//////NOT USED YET//////
////// Global structure
typedef struct s_int_array
{
	int	*array;
	int	size;
}	t_int_arr;

#endif
