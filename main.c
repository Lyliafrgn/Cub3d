/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/20 17:16:47 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av, char **env)
{
	t_global	data;

	(void)env;
	if (ac < 2)
	{
		write(STDERR_FILENO, "Run with: ./cub3D <map_file>\n", 30);
		return (EXIT_FAILURE);
	}
	initialize_structures(&data);
	if (av && av[1] && parse_map_root(&data, av[1]) == EXIT_FAILURE)
	{
		write(STDERR_FILENO, "Err: Map parsing failed.\n", 25);
		free_resources(&data);
		return (EXIT_FAILURE);
	}
	data.winw = data.map.width * TILE_SIZE;
	data.winh = data.map.height * TILE_SIZE;
	/* /// Je pense a première vue que pas utile///
	if (!data.map.map)
		return (free_resources(&data), write(STDERR_FILENO, MAP_PARS_ERR, 27), EXIT_FAILURE);
	/// */
	if (init_mlx(&data) == FAILURE)
	{
		write(2, "Err: MLX initialization failed.\n", 31);
		free_resources(&data);
		return (EXIT_FAILURE);
	}
	mlx_loop(data.mlx_ptr);
	free_resources(&data);
	write(STDIN_FILENO, "Game exited successfully.\n", 26);
	return (EXIT_SUCCESS);
}
