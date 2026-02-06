/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:08:04 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/28 22:33:07 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*s_truncate(char *s, int n)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!s || n < 0)
		return (NULL);
	cpy = malloc ((n + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (s[i] && i < n)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	eol(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-2);
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*str_cpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*concat(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*cpy;
	int		len;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	cpy = malloc ((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (s1 && s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		cpy[i + j] = s2[j];
		j++;
	}
	cpy[i + j] = '\0';
	return (cpy);
}
