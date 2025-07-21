/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/21 17:58:07 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av, char **env)
{
	t_global	data;

	(void)env;
	if (ac < 2)
	{
		write(stderr, "Run with: ./cub3D <map_file>\n", 30);
		return (1);
	}
	initialize_structures(&data);
	if (av && av[1])
		parse_map(av[1]);

	if (!data.map || !data.player)
	{
		write(stderr, "Error: Map or player data not initialized.\n", 43);
		return (1);
	}
	run_game_main_loop(&data);
	free_resources(&data);
	write(stdout, "Game exited successfully.\n", 26);
	return (0);
}
