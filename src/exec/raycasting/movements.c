/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/31 04:04:02 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	ft_horizontal_move(t_data *data)
{
	t_vec	step;

	step.x = data->player.planex * data->player.ms;
	step.y = data->player.planey * data->player.ms;
	if (data->left)
	{
		if (data->map->map_data[(int)(data->player.x - step.x)][(int)(data->player.y)] == '0')
			data->player.x -= step.x;
		if (data->map->map_data[(int)(data->player.x)][(int)(data->player.y - step.y)] == '0')
			data->player.y -= step.y;
	}
	if (data->right)
	{
		if (data->map->map_data[(int)(data->player.x + step.x)][(int)(data->player.y)] == '0')
			data->px += step.x;
		if (data->map[(int)(data->player.x)][(int)(data->player.y + step.y)] == '0')
			data->player.y += step.y;
	}
}

static void	ft_vertical_move(t_data *data)
//TBC

static void	ft_rotate(t_data *data)
//TBC


void	ft_move(t_data *data)
{
	if (data->up || data->down)
		ft_vertical_move(data);
	if (data->left || data->right)
		ft_horizontal_move(data);
	if (data->rotleft || data->rotright)
		ft_rotate(data);
}
