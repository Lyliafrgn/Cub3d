/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:33:42 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:43:54 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * The memory areas must not overlap. If they do, behavior is undefined.
 * The caller must ensure that dest points to allocated memory of
 * at least n bytes.
 * For copying arrays of types larger than a byte (e.g., int[]), n should be
 * the total size in bytes (count * sizeof(type)).
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to the destination memory area (dest).
 *
 * @note Prefer ft_memmove for safe copying when memory areas might overlap.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	if (dest < src || dest >= (src + n))
	{
		i = 0;
		while (i < n)
		{
			((char *) dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			((char *) dest)[i] = ((char *)src)[i];
		}
	}
	return (dest);
}

/*
int main ()
{
	 char str[] = "hola";
	 char sr[] = "bb";

        printf("Before memcpy: %s\n", str);
        memcpy(str, sr, 4);
        printf("After memcpy: %s\n", str);


	char str2[] = "hola";
        printf("Before memcpy: %s\n", str2);
        ft_memcpy(str2, sr,4);
        printf("After ft_memcpy: %s\n", str2);
}
*/
