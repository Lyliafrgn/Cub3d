/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:11:56 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/23 18:00:42 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Duplicates the given string by allocating sufficient memory
 *        and copying its content.
 *
 * Allocates memory for a new null-terminated string, copies the
 * content of s1 into it,and returns a pointer to the new string.
 *
 * @param s1 The source null-terminated string to duplicate.
 * @return A pointer to the duplicated string, or NULL if memory alloc fails.
 */
char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
		i++;
	cpy = malloc ((i + 1) * sizeof (char));
	if (!cpy)
		return (NULL);
	while (i >= 0)
	{
		cpy[i] = s1[i];
		i--;
	}
	return (cpy);
}
/*
int main ()
{
	char s1[] = "hola";
	printf("%p\n", strdup(s1));
	printf("%p\n", ft_strdup(s1));
}
*/
