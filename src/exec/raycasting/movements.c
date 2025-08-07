/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/07 16:39:24 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
Allows the player to move in a 
2D environment represented 
by a map and to rotate his view.
	
	-> base map[row][column] (y, x)
*/
static void	ft_horizontal_move(t_data *data)
{
	t_vec	step;

	step.x = data->player.planex * data->player.ms;
	step.y = data->player.planey * data->player.ms;
	if (data->left)
	{
		if (data->map->map[(int)(data->player.y)][(int)(data->player.x - step.x)] == '0')
			data->player.x -= step.x;
		if (data->map->map[(int)(data->player.y - step.y)][(int)(data->player.x)] == '0')
			data->player.y -= step.y;
	}
	if (data->right)
	{
		if (data->map->map[(int)(data->player.y)][(int)(data->player.x + step.x)] == '0')
			data->player.x += step.x;
		if (data->map->map[(int)(data->player.y + step.y)][(int)(data->player.x)] == '0')
			data->player.y += step.y;
	}
}

static void	ft_vertical_move(t_data *data)
{
	t_vec	step;

	step.x = data->player.dirx * data->player.ms;
	step.y = data->player.diry * data->player.ms;
	if (data->down)
	{
		if (data->map->map[(int)(data->player.y)][(int)(data->player.x - step.x)] == '0')
			data->player.x -= step.x;
		if (data->map->map[(int)(data->player.y - step.y)][(int)(data->player.x)] == '0')
			data->player.y -= step.y;
	}
	if (data->up)
	{
		if (data->map->map[(int)(data->player.y)][(int)(data->player.x + step.x)] == '0')
			data->player.x += step.x;
		if (data->map->map[(int)(data->player.y + step.y)][(int)(data->player.x)] == '0')
			data->player.y += step.y;
	}
}

static void	ft_rotate(t_data *data)
{
	double	old_dirx;
	double	old_planex;
	double	rs;

	rs = data->player.rs;
	if (data->cam_left)
		rs = -rs;
	else if (!data->cam_right)
		return ;
	old_dirx = data->player.dirx;
	data->player.dirx = data->player.dirx * cos(rs) - data->player.diry * sin(rs);
	data->player.diry = old_dirx * sin(rs) + data->player.diry * cos(rs);

	old_planex = data->player.planex;
	data->player.planex = data->player.planex * cos(rs) - data->player.planey * sin(rs);
	data->player.planey = old_planex * sin(rs) + data->player.planey * cos(rs);
}
void	ft_move(t_data *data)
{
	if (data->up || data->down)
		ft_vertical_move(data);
	if (data->left || data->right)
		ft_horizontal_move(data);
	if (data->rotleft || data->rotright)
		ft_rotate(data);
}