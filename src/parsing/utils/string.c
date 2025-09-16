/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:38:48 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/16 16:19:18 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(s1, s2);
	result = ft_strjoin(tmp, s3);
	free (tmp);
	return (result);
}

bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\r');
}

bool	line_is_only_spaces(char *line)
{
	int	i;

	i = -1;
	if (!line)
		return (true);
	while (line[++i])
	{
		if (!ft_isspace(line[i]) && line[i] != '\n')
			return (false);
	}
	return (true);
}

int	is_cub_extension(const char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}