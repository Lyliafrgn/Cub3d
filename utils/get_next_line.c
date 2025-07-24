/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:55:38 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/23 22:40:35 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	init_gnl_vars(char **line, char *buf, int *bits, int *npos)
{
	*npos = -2;
	*line = ft_strdup(buf);
	*npos = eol(*line);
	*bits = 0;
}

static int	eol_found_handler(char **line, char *buf, int *bits, int *npos)
{
	char	*tmp;

	tmp = NULL;
	if (*npos >= 0)
	{
		tmp = *line;
		*line = s_truncate(buf, *npos + 1);
		ft_free((void **) &tmp);
		str_cpy(buf, buf + *npos + 1);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static int	read_and_check(int fd, char *buf, char **line, int *bits)
{
	*bits = read(fd, buf, BUFFER_SIZE);
	if (*bits < 0)
	{
		perror("Error reading file");
		return (-1);
	}
	if ((bits == 0 && !(*line)) || (bits == 0 && (*line) && !(*line)[0]))
	{
		if (*line)
			ft_free((void **) line);
		return (0);
	}
	if (bits == 0)
		return (1);
	buf[*bits] = '\0';
}

static int	concat_and_check(char **line, char *buf, int npos)
{
	char	*tmp;

	tmp = *line;
	*line = concat(*line, buf);
	ft_free((void **) &tmp);
	npos = eol(*line);
	if (npos >= 0)
	{
		str_cpy(buf, *line + npos + 1);
		tmp = *line;
		*line = s_truncate(*line, npos + 1);
		ft_free((void **) &tmp);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

char	*ft_get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			bits;
	int			npos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	init_gnl_vars(&line, buf, &bits, &npos);
	if (eol_found_handler(&line, buf, &bits, &npos) == EXIT_SUCCESS)
		return (line);
	while (1)
	{
		if (read_and_check(fd, buf, &line, &bits) <= 0)
			return (NULL);
		else
			return (line);
		if (concat_and_check(&line, buf, npos) == EXIT_SUCCESS)
			return (line);
	}
	return (NULL);
}
