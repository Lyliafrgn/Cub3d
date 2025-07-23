/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/23 18:04:06 by ly               ###   ########.fr       */
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
		return (1);
	}
	initialize_structures(&data);
	if (av && av[1])
		parse_map_root(&data, av[1]);

	if (!data.map || !data.player)
	{
		write(STDERR_FILENO, "Err: Map or player data not initialized.\n", 42);
		return (1);
	}
	init_mlx(&data);
	if (init_mlx(&data) == FAILURE)
	{
		write(2, "Err: Failed to initialize MLX.\n", 31);
		return (1);
	}
	run_game_main_loop(&data);
	free_resources(&data);
	write(STDIN_FILENO, "Game exited successfully.\n", 26);
	return (0);
}
