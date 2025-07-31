/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:54:02 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:06:23 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

/**
 * @brief Compares up to n characters of two strings.
 *
 * Compares the characters of s1 and s2 up to n bytes or until
 * a null terminator is reached in either string.
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @param n Maximum number of characters to compare.
 * @return
 *   0 if the strings are equal up to n characters,
 *   a positive or negative value depending on the first differing character.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((const char) s1[i] != (const char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
/*
int main ()
{
	printf("%i\n",strncmp("hola","holb",3));
	printf("%i\n\n", ft_strncmp("hola","holb",3));
	printf("%i\n",strncmp("hola","holb",4));
	printf("%i\n\n", ft_strncmp("hola","holb",4));
	printf("%i\n",strncmp("hola","hola",4));
	printf("%i\n\n", ft_strncmp("hola","hola",4));
	printf("%i\n",strncmp("hola","holb",5));
	printf("%i\n\n", ft_strncmp("hola","holb",5));
	printf("%i\n",strncmp("hola","hoaa",5));
	printf("%i\n\n", ft_strncmp("hola","hoaa",5));
	printf("%i\n",strncmp("hola","hoaa",0));
	printf("%i\n\n", ft_strncmp("hola","hoaa",0));
}
*/
