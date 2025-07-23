/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/23 17:52:53 by ofilloux         ###   ########.fr       */
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
	if (initialize_structures(&data))
		return (EXIT_FAILURE);
	if (av && av[1])
		parse_map_root(&data, av[1]);

	if (!data.map || !data.player)
	{
		write(STDERR_FILENO, "Err: Map or player data not initialized.\n", 42);
		return (1);
	}
	run_game_main_loop(&data);
	free_resources(&data);
	write(STDIN_FILENO, "Game exited successfully.\n", 26);
	return (0);
}
