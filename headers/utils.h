/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:39:07 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/01 16:46:02 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "structures.h"

int		initialize_structures(t_global *data);

/// FREES /////
int		free_resources(t_global *data);
void	ft_free(void **ptr);
void	free_av(char ***av);
char	**free_uncomplete_av(char ***av, int i);

/// GET NEXT LINE /////
char	*ft_get_next_line(int fd);
char	*s_truncate(char *s, int n);
int		eol(char *line);
char	*str_cpy(char *dest, char *src);
char	*concat(char *s1, char *s2);

/// ARRAY /////
//Char
int		pp_char_len(char **array);
void	print_pp_char_arr(char **str);

#endif
