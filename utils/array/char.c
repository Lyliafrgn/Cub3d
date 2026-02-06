/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:11:42 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/01 16:13:07 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pp_char_len(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

void	print_pp_char_arr(char **str)
{
	int	i;

	i = 0;
	if (!str)
	{
		printf("PP_char _ arr is NULL\n");
		return ;
	}
	if (!str[0])
	{
		printf("PP_char _ arr[0] is NULL\n");
		return ;
	}
	while (str && str[i] && str[i][0])
	{
		printf("*str[%i] = `%s`\n", i, str[i]);
		i++;
	}
}
