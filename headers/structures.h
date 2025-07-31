/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:43:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/31 02:08:58 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

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
	char	**map_data;	// 2D array for the map
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
	int		endian; //if 0 = little endian (RGB order), if 1 = big endian (RGB)
	int		imgw; // Width of the img
	int		imgh; // Height of the img
}	t_img;

typedef struct s_vec //Représente un vecteur (x, y) en coordonnées flottantes
{	
	double	x;
	double	y;
}	t_vec;

// Représente un point (x, y) en coordonnées entières (souvent utilisé pour la grille)
typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

// Structure de rayon utilisée pour le raycasting (DDA)
typedef struct s_ray
{
	t_vec	dir;				// Direction du rayon (en x et y)
	t_vec	sidedist;			// Distance actuelle du rayon jusqu'au bord suivant en x ou y
	t_vec	deltadist;			// Distance à parcourir pour passer d'une ligne de grille à la suivante (en x et y)
	double	perp_wall_dist;		// Distance perpendiculaire entre la caméra et le mur (corrige la distorsion fish-eye)
	int		mapx;				// Case actuelle du rayon sur la map (coordonnée x)
	int		mapy;				// Case actuelle du rayon sur la map (coordonnée y)
	int		stepx;				// Pas (direction +1 ou -1) du rayon en x
	int		stepy;				// Pas du rayon en y
	int		side;				// Côté touché : 0 = NS (Nord/Sud), 1 = EW (Est/Ouest)
}	t_ray;

typedef struct s_global
{
	t_map		*map;
	t_player	*player;
	t_ray		ray;
	t_img		txtr[4]; // NO, SO, EA, WE
	t_img		screen;
	void		*mlx_ptr;
	void		*win_ptr;
	int			winw;
	int			winh;
	int			colors[2][3]; // 2= floor and ceiling colors & 3= RGB 
	int			left;
	int			right;
	int			up;
	int			down;
	int			cam_left;
	int			cam_right;
}	t_global;

#endif
