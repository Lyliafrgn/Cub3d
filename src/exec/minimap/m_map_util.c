/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_map_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:59:43 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/27 23:00:17 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	min_two_val(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

bool	not_in_mmap(int col, int row)
{
	return (col < M_MAP_OFFSET_X + M_MAP_BORDER \
		|| col > M_MAP_OFFSET_X + M_MAP_BORDER + M_MAP_SIZE \
		|| row < M_MAP_OFFSET_Y + M_MAP_BORDER \
		|| row > M_MAP_OFFSET_Y + M_MAP_BORDER + M_MAP_SIZE);
}
