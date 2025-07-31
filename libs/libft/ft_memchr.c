/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:34:06 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:30:51 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s for
 *        the first occurrence of c.
 *
 * @param s Pointer to the memory area to scan.
 * @param c Character to search for (converted to unsigned char).
 * @param n Number of bytes to scan.
 * @return Pointer to the first occurrence of c in s, or NULL if not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*str;

	i = 0;
	d = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == d)
			return (((void *)str) + i);
		i++;
	}
	return (NULL);
}

/*
int main ()
{
	printf("%p\n",ft_memchr("hola",97,4));
        printf("%p\n\n",memchr("hola",97,4));

	printf("%p\n",ft_memchr("hola",97,3));
        printf("%p\n\n",memchr("hola",97,3));

        printf("%p\n",ft_memchr("hola",97,0));
        printf("%p\n\n",memchr("hola",97,0));

        printf("%p\n",ft_memchr("hola",98,4));
        printf("%p\n\n",memchr("hola",98,4));

        printf("%p\n",ft_memchr("hola",98,3));
        printf("%p\n\n",memchr("hola",98,3));

        printf("%p\n",ft_memchr("hola",98,7));
        printf("%p\n\n",memchr("hola",98,7));

        printf("%p\n",ft_memchr("hola",68,4));
        printf("%p\n\n",memchr("hola",68,4));
}
*/
