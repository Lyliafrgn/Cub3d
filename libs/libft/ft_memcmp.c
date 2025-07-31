/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:35:04 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:36:49 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

/**
 * @brief Compares the first n bytes of two memory areas.
 *
 * Can be used to compare byte arrays (e.g., char[]) directly.
 * For arrays of larger types (e.g., int[]), it compares the raw memory
 * byte-by-byte and requires n to be the total size in bytes (eg. use sizeof()).
 *
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n Number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if
 *         s1 is found to be less than, equal to, or greater than s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int main ()
{
	printf("%i\n",ft_memcmp("hola","hola", 4));
        printf("%i\n\n",memcmp("hola","hola", 4));

	printf("%i\n",ft_memcmp("hola","hola", 5));
        printf("%i\n\n",memcmp("hola","hola", 5));

	printf("%i\n",ft_memcmp("hola","hola", 8));
        printf("%i\n\n",memcmp("hola","hola", 8));

	//probleme 0 , -1
	printf("%i\n",ft_memcmp("hola","holb", 4));
        printf("%i\n\n",memcmp("hola","holb", 4));

	printf("%i\n",ft_memcmp("hola","holb", 3));
        printf("%i\n\n",memcmp("hola","holb", 3));

	// pb 0,1
	printf("%i\n",ft_memcmp("holc","hola", 4));
        printf("%i\n\n",memcmp("holc","hola", 4));

	//pb 0, -1
	printf("%i\n",ft_memcmp("hoaa","hola", 4));
        printf("%i\n\n",memcmp("hoaa","hola", 4));

        printf("%i\n",ft_memcmp("hola","hoaa", 2));
        printf("%i\n\n",memcmp("hola","hoaa", 2));
}
*/
