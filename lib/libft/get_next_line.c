/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:12:10 by lylfergu          #+#    #+#             */
/*   Updated: 2024/09/04 16:42:36 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer, int bytes)
{
	char	*stash;

	stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!stash)
	{
		return (ft_double_free(&buffer, NULL));
	}
	while (bytes > 0)
	{
		if (ft_strchr(stash, '\n'))
			break ;
		bytes = read(fd, stash, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_double_free(&buffer, &stash));
		stash[bytes] = '\0';
		buffer = protect_join(buffer, stash);
		if (!buffer)
			return (NULL);
	}
	return (ft_double_free(&stash, NULL), buffer);
}

char	*protect_join(char *buffer, char *reading)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, reading);
	if (!tmp)
	{
		return (ft_double_free(&buffer, NULL));
	}
	return (tmp);
}

char	*extract_line(char *buffer)
{
	char	*line;
	char	*pos;
	int		start;
	int		end;

	if (!buffer)
		return (NULL);
	pos = ft_strchr(buffer, '\n');
	end = pos - buffer;
	if (!pos)
	{
		end = ft_strlen(buffer);
	}
	end++;
	line = ft_calloc(end + 1, sizeof(char));
	if (!line)
		return (NULL);
	start = 0;
	while (start < end)
	{
		line[start] = buffer[start];
		start++;
	}
	return (line);
}

char	*new_buffer(char *buffer)
{
	int		new_start;
	char	*new;
	char	*pos;
	int		size;
	int		i;

	pos = ft_strchr(buffer, '\n');
	new_start = pos - buffer;
	if (!pos)
		new_start = ft_strlen(buffer);
	if (!buffer[new_start])
		return (ft_double_free(&buffer, NULL));
	size = ft_strlen(buffer) - new_start;
	new = ft_calloc(size + 1, sizeof(char));
	if (!new)
		return (ft_double_free(&buffer, NULL));
	i = 0;
	new_start++;
	while (buffer[new_start])
	{
		new[i++] = buffer[new_start++];
	}
	free(buffer);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	if (!buffer)
	{
		buffer = ft_calloc(1, 1);
	}
	if (!buffer)
		return (NULL);
	buffer = read_line(fd, buffer, 1);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	if (!line || !*line)
	{
		return (ft_double_free(&buffer, &line));
	}
	buffer = new_buffer(buffer);
	return (line);
}
