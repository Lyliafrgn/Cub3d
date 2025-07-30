/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:43:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/30 16:39:28 by ofilloux         ###   ########.fr       */
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
	int	fd;			// File descriptor for the map file
	int	**map_data;	// 2D array for the map
	int	width;		// Width of the map
	int	height;		// Height of the map
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


typedef struct s_global
{

	t_map		*map;
	t_player	*player;
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
