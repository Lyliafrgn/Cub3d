/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:50:11 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/01 16:11:05 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

///////////////NOT USED YET ////////////

/// @brief Check if a variable is registred in the ARR
/// @param var int
/// @param arr array of int
/// @return return true if var is in arr
bool	int_var_in_arr(int var, t_int_arr *arr)
{
	int	i;

	i = 0;
	if (!arr || !(arr->array) || (arr->size) < 0)
		return (false);
	while (i < arr->size)
	{
		if (var == arr->array[i])
			return (true);
		i++;
	}
	return (false);
}

void	print_int_arr(t_int_arr *arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < arr->size)
	{
		printf("print_arr[%i] = %i\n", i, arr->array[i]);
		i++;
	}
}
