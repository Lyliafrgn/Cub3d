/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:51:47 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/04 17:55:35 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	color_start(char *line)
{
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
		{
			flag = 1;
			i++;
		}
		if (flag == 1)
			break ;
		i++;
	}
	return (i);
}

static int	get_colors(char *line, int colors[3])
{
	int		i;
	char	**tmp;

	i = color_start(line);
	tmp = NULL;
	if (!line[i] || i == (int) ft_strlen(line))
		return (write(STDERR_FILENO, "Err: colors not found\n", 23), EXIT_FAILURE);
	tmp = ft_split(line + i, ',');
	if (pp_char_len(tmp) != 3)
		return (write(STDERR_FILENO, "Err: 3 colors are needed\n", 26), EXIT_FAILURE);
	colors[0] = ft_atoi(tmp[0]);
	colors[1] = ft_atoi(tmp[1]);
	colors[2] = ft_atoi(tmp[2]);
	free_av(&tmp);
	return (EXIT_SUCCESS);
}

int	process_colore_line(t_global *data, char *line)
{
	int					i;
	static const char	*col_code[] = {"F", "C"};

	i = 0;
	while (i < 2)
	{
		if (data->pars_sta.color[i] && ft_strncmp(line, col_code[i], 1) == 0)
			return (write(STDERR_FILENO,"Err: 2colors for same use\n", 27), EXIT_FAILURE);
		if (!data->pars_sta.color[i] && ft_strncmp(line, col_code[i], 1) == 0)
		{
			data->pars_sta.color[i] = true;
			if (get_colors(line + 1, data->colors[i]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
