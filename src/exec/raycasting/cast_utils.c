/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/25 16:33:14 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*selects the texture of the wall to be drawn
based on the direction of the ray
and the side it has touched.
*/
void	ft_choose_wall_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x > 0)
			ray->wall = TX_EA;
		else
			ray->wall = TX_WE;
	}
	else
	{
		if (ray->dir.y > 0)
			ray->wall = TX_SO;
		else
			ray->wall = TX_NO;
	}
}

/*to know the direction in which we will move in the grid
step->x = -1 if we are looking to the left.
step->y = -1 if we are looking up.
Otherwise, we move to the right/down (+1)
*/
void	ft_set_step(t_global *data, t_point *step)
{
	step->x = 1;
	if (data->ray.dir.x < 0)
		step->x = -1;
	step->y = 1;
	if (data->ray.dir.y < 0)
		step->y = -1;
}

/*To know which wall will be hit first:
*sidedist = distance between the plyr current position
 and the next grid line (vertical or horizontal)
*/
void	ft_set_sidedist(t_global *data, t_vec *sidedist, t_vec deltadist)
{
	if (data->ray.dir.x < 0)
		sidedist->x = (data->player.x - data->ray.mapx) * deltadist.x;
	else
		sidedist->x = (data->ray.mapx + 1.0 - data->player.x) * deltadist.x;
	if (data->ray.dir.y < 0)
		sidedist->y = (data->player.y - data->ray.mapy) * deltadist.y;
	else
		sidedist->y = (data->ray.mapy + 1.0 - data->player.y) * deltadist.y;
	if (sidedist->x == 0)
		sidedist->x = 0.1;
	if (sidedist->y == 0)
		sidedist->y = 0.1;
}

/**
 * @brief calculate the differences between successive intersections
 *
 * , ex: deltadist.x = distance between two vertical intersections.
 * 	1e30 is used to represent infinity to avoid division by zero
 * 	when the ray is perfectly vertical or horizontal. Indeed,
 * 	if the ray's x or y direction component is zero,
 * 	it means the ray is moving exactly vertically or horizontally,
 * 	so the distance to the next vertical or horizontal grid line is infinite.
 *
 */
void	ft_init_deltadist(t_ray *ray, t_vec *deltadist)
{
	if (ray->dir.x == 0)
		deltadist->x = 1e30;
	else
		deltadist->x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		deltadist->y = 1e30;
	else
		deltadist->y = fabs(1 / ray->dir.y);
}
/* LE COURS derrière cette fonction:
 *  1 / ray->dir.x the distance to the next grid line
 * 	in the direction of the ray, not just the distance in grid units (1).
 * pythagore
 * 	Distance euclidienne :
 * 		deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
 *
 * Le rayon, c’est un vecteur direction et il a une direction (rayDirX, rayDirY).
 * Cela veut dire :
 * Quand tu avances de t unités le long du rayon, tu bouges de t * rayDirX en X,
 *  et de t * rayDirY en Y.

 * _____________
 * y
 * ^
 * |      t
 * |     /
 * |    /
 * |   /
 * |  /
 * | /
 * |/________________> x
 *
 *  Formule paramétrique : (x(t),y(t)) = (x0​ + t⋅rayDirX, y0​ + t⋅rayDirY)
 * où t est la distance parcourue le long du rayon.
 *
 * 2. Avancer de 1 case en X
 * Quand est-ce que mon rayon avance exactement de 1 en X ? Alors :
 * t . rayDirX = 1  ( 1 pour une case)    ==>   t= 1/ rayDirX
 * À ce moment-là, le rayon a avancé de :
 * y = t . rayDirY = rayDirX / rayDirY​
 * c’est exactement “combien d’unités en Y le rayon parcourt quand
 * il avance d’une unité en X”.
 *
 * Le ration correspond aussi à la pente d'une droite :
 * pente = Δy / Δx​
*/
