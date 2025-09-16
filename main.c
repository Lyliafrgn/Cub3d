/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:37:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/16 16:52:08 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	start_game(t_global *data)
{
	data->winw = 10 * TILE_SIZE;
	data->winh = 10 * TILE_SIZE;
	if (init_mlx(data) == FAILURE)
	{
		ft_err("Err: MLX initialization failed.", data);
		return (EXIT_FAILURE);
	}
	mlx_loop(data->mlx_ptr);
	free_resources(data);
	write(STDOUT_FILENO, "Game exited successfully.\n", 26);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	t_global	data;

	(void)env;
	if (ac < 2)
		return (err_msg("Run with: ./cub3D <map_file>\n"));
	initialize_structures(&data);
	if (parse_map_root(&data, av[1]) == EXIT_FAILURE)
		return (free_resources(&data),
			err_msg("Err: Map parsing failed.\n"));
	if (!data.map.map)
		return (err_msg(MAP_PARS_ERR));
	return (start_game(&data));
}
