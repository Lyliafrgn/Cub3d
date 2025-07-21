/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:15:29 by lylfergu          #+#    #+#             */
/*   Updated: 2024/09/03 16:00:26 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_line(int fd, char *buffer, int bytes);
char	*protect_join(char *buffer, char *reading);
char	*extract_line(char *buffer);
char	*new_buffer(char *buffer);

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nb, size_t size);
char	*ft_double_free(char **str1, char **str2);
#endif
