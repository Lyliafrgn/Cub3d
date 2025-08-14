/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:21:57 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/14 13:20:01 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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

static void	free_textures(t_global *data)
{
	if (data->txtr[0].mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->txtr[0].mlx_img);
	if (data->txtr[1].mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->txtr[1].mlx_img);
	if (data->txtr[2].mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->txtr[2].mlx_img);
	if (data->txtr[3].mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->txtr[3].mlx_img);
}

static void	free_screen(t_global *data)
{
	if (data->screen.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->screen.mlx_img);
}

static void	free_window(t_global *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

void	ft_free_resources(t_global *data)
{
	if (data->map.map)
		free_av(&data->map.map);
	free_textures(data);
	free_screen(data);
	free_window(data);
}
