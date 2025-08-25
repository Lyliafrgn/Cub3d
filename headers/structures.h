/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:43:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/25 19:01:30 by ofilloux         ###   ########.fr       */
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


typedef struct s_vec //Représente un vecteur (x, y) en coordonnées flottantes
{
	double	x;
	double	y;
}	t_vec;

// Représente un point (x, y) en coordonnées entières
typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

// Structure de rayon utilisée pour le raycasting (DDA)
typedef struct s_ray
{
	t_vec	dir; // Direction du rayon (en x et y)
	t_vec	sidedist; // Distance actuelle du rayon jusqu'au bord suivant en x ou y
	t_vec	deltadist; // Distance à parcourir pour passer d'une ligne de grille à la suivante (en x et y)
	double	perp_wall_dist;	// Distance perpendiculaire entre la caméra et le mur (corrige la distorsion fish-eye)
	int		mapx; // Case actuelle du rayon sur la map (coordonnée x)
	int		mapy; // Case actuelle du rayon sur la map (coordonnée y)
	int		stepx; // Direction dans la grille pour DDA (raycasting): Pas (direction +1 ou -1) du rayon en x
	int		stepy; // Pas du rayon en y (Direction dans la grille pour DDA (raycasting))
	int		side; // Côté touché : 0 = NS (Nord/Sud), 1 = EW (Est/Ouest)
	int		start; // pixel vertical de début du mur (haut)
	int		end;  // pixel vertical de fin du mur (bas)
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
	int	border_color;
	int	border_size; // size of the border around the minimap
	int	offset_x; // offset from the left edge of the window
	int	offset_y; // offset from the top edge of the window
	int	map_width_px; // width of the minimap in pixels
	int	map_height_px; // height of the minimap in pixels
	int	step_x; // size of each cell in the minimap
	int	step_y;
	int	player_size; // size of the player square in the minimap
	int	player_color; // color of the player square in the minimap
	int	wall_color; // color of the walls in the minimap
	int	floor_color; // color of the floor in the minimap
	int	ray_color; // color of the rays in the minimap
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
