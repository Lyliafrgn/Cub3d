/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/23 18:35:01 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_global	data;

	initialize_structures(&data);
//	if (av && av[1])
//		parse_map_root(&data, av[1]);
	if (init_mlx(&data) == FAILURE)
	{
		write(2, "Err: MLX initialization failed.\n", 31);
		return (1);
	}
	mlx_loop(data.mlx_ptr);
	write(STDIN_FILENO, "Game exited successfully.\n", 26);
	return (0);
}