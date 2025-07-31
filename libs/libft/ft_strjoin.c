/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:35:53 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:01:16 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief Concatenates two strings into a newly allocated string.
 *
 * Allocates memory for a new string that is the result of
 * appending s2 to s1. Both strings must be null-terminated.
 *
 * @param s1 First string to concatenate.
 * @param s2 Second string to concatenate.
 * @return A pointer to the new string, or NULL if allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	int		t;
	char	*nw;

	l1 = (int)ft_strlen(s1);
	l2 = (int)ft_strlen(s2);
	nw = malloc((l1 + l2 + 1) * sizeof(char));
	if (!nw)
		return (NULL);
	t = 0;
	while (t <= l1 - 1)
	{
		nw[t] = s1[t];
		t++;
	}
	while (t <= l1 + l2 - 1)
	{
		nw[t] = s2[t - l1];
		t++;
	}
	nw[t] = '\0';
	return (nw);
}
/*
int	main()
{
  printf("%s", ft_strjoin("hola","mundo"));
  return (1);
}
*/
