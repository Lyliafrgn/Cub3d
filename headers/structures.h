/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:43:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/03 19:20:41 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "parsing.h"

typedef struct s_player
{
	double	x;		// Player's x position
	double	y;		// Player's y position
	double	angle;	// Player's direction angle  // @util Non utilisé il me semble
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
	int		width;		// Width of the map (not in pixels)
	int		height;		// Height of the map (not in pixels)
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

//// MINIMAP ////
typedef struct s_mmap
{
	int		border_color;
	int		player_color; // color of the player square in the minimap
	int		wall_color; // color of the walls in the minimap
	int		floor_color; // color of the floor in the minimap
	int		ray_color; // color of the rays in the minimap

	double	scale; // mise à l'echelle de la map par rapport à la minimap
	double	new_tile_size; // new tile size after scaling
	double	new_width_px; // largeur en pxel de la nouvelle map mise à l'échelle
	double	new_height_px; // hauteur de la nouvelle map mise à l'échelle
	int		inner_offset_y; // offset à l'interieur mmap pour centrer map
	int		inner_offset_x; // offset à l'interieur mmap pour centrer map

	double	player_x; // position x du joueur sur la minimap
						//offset horizontal + décalage interne horizontal
						//+ position monde X convertie en pixels minimap
	double	player_y; // position y du joueur sur la minimap
}	t_mmap;

typedef struct s_global
{
	t_map		map;
	t_player	player;
	t_pars		pars_sta; // to know in which type of line we are
	t_ray		ray; // rayon principal pour le raycasting
	t_img		txtr[4]; // NO, SO, EA, WE
	t_img		screen;
	t_mmap		minimap;
	void		*mlx_ptr;
	void		*win_ptr;
	int			winw;
	int			winh;
	int			colors[2][3]; // 2= floor and ceiling & 3= colors (RGB)
	t_dir		dir; // to know which direction the player is moving
}	t_global;



#endif
