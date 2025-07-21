/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:13:34 by lylfergu          #+#    #+#             */
/*   Updated: 2024/09/03 16:31:43 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nb, size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = malloc(nb * size);
	if (!memory)
	{
		return (NULL);
	}
	while (i < (nb * size))
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}

char	*ft_double_free(char **str1, char **str2)
{
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	return (NULL);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	if (str[i] == (char)c)
	{
		return (&str[i]);
	}
	if ((char)c == '\0')
	{
		return (str);
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		res[j++] = s2[i++];
	}
	res[j] = '\0';
	free(s1);
	return (res);
}
