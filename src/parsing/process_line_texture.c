/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:51:20 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/07 15:35:22 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_len(char *line)
{
	int	i;

	i = 0;
	while (*line != '\0' && *line == ' ')
		line++;
	while (line[i] != '\0' && !ft_isspace(line[i]) && line[i] != '\n')
		i++;
	return (i);
}

/**
 * @brief Extracts the texture path from a line.
 * The function assumes the line starts with a texture identifier
 * (e.g., "NO", "SO", etc.)
 * and extracts the path that follows.
 * get_texture_len(line) - 2) for the length to exclude the newline character
 * 		and the '\0'.
 *
 * @param line The line containing the texture path.
 * @return A dynamically allocated string containing the texture path,
 * 		or NULL if not found.
 */

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
		return (err_msg("Err: texture path not found\n"), NULL);
	return (ft_substr(line + i, 0, (size_t) get_texture_len(line)));
}

int	process_texture_line(t_global *data, char *line)
{
	int					i;
	static const char	*txtr_code[] = {"NO", "SO", "EA", "WE"};

	i = 0;
	while (i < 5)
	{
		if (data->pars_sta.txtr[i] && ft_strncmp(line, txtr_code[i], 2) == 0)
			return (err_msg("Err: same NSEW texture twice\n"));
		if (!data->pars_sta.txtr[i] && ft_strncmp(line, txtr_code[i], 2) == 0)
		{
			data->txtr[i].path = get_texture(line + 2);
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
