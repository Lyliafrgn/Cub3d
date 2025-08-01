/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:51:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/01 18:28:02 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_texture(char *line)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
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
	if (!line[i] || i == (int) ft_strlen(line))
		return (write(STDERR_FILENO, "Err: texture path not found\n", 29), NULL);
	return (ft_strdup(line + i - 1));
}

int	process_texture_line(t_global *data, char *line)
{
	int					i;
	static const char	*txtr_code[] = {"NO", "SO", "EA", "WE"};

	i = 0;
	while (i < 5)
	{
		if (data->pars_sta.txtr[i] && ft_strncmp(line, txtr_code[i], 2) == 0)
			return (write(STDERR_FILENO,"Err: Use juste 1 north texture\n", 32), EXIT_FAILURE);
		if (!data->pars_sta.txtr[i] && ft_strncmp(line, txtr_code[i], 2) == 0)
		{
			data->txtr[0].path = get_texture(line + 2);
			data->pars_sta.txtr[i] = true;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

/* const char **get_texture_codes(void)
{
	static const char *txtr_code[] = {"NO", "SO", "EA", "WE"};
	return (txtr_code);
} */
