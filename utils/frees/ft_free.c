/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:21:57 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/01 16:16:45 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

//Free a full char **
void	free_av(char ***av)
{
	int	i;

	if (av == NULL || *av == NULL)
		return ;
	i = 0;
	while ((*av)[i] != NULL)
	{
		ft_free((void **) &(*av)[i]);
		i++;
	}
	ft_free((void **) av);
	av = NULL;
}

// free an av that is incomplete due to a bug
char	**free_uncomplete_av(char ***av, int i)
{
	i--;
	while (i >= 0)
	{
		ft_free((void **) &(*av)[i]);
		i--;
	}
	ft_free((void **) av);
	return (NULL);
}
