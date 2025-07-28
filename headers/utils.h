/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:39:07 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/28 22:38:09 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifdef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "structures.h"

int		initialize_structures(t_global *data);

/// FREES /////
void	ft_free(void **ptr);
int		free_resources(t_global *data);

/// GET NEXT LINE /////
char	*ft_get_next_line(int fd);
char	*s_truncate(char *s, int n);
int		eol(char *line);
char	*str_cpy(char *dest, char *src);
char	*concat(char *s1, char *s2);

#endif
