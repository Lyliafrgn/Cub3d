/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:38:37 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:48:47 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * The memory areas may overlap. Copying is done safely to avoid data
 * corruption.
 * If dest > src, copying is performed from the end to the beginning.
 * Otherwise, copying is from the beginning to the end.
 * The caller must ensure that dest points to allocated memory of
 * at least n bytes.
 * For copying arrays of types larger than a byte (e.g., int[]), n should be
 * the total size in bytes (count * sizeof(type)).
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to the destination memory area (dest).
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	i = 0;
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
int main ()
{
	 char str[] = "hola";
	 char sr[] = "bb";

        printf("Before memset: %s\n", str);
        memmove(str, sr, 2);
        printf("After memset: %s\n", str);


	char str2[] = "hola";
        printf("Before ft_memmove: %s\n", str2);
        ft_memmove(str2, sr,2);
        printf("After ft_memset: %s\n\n", str2);


	char str3[] = "hola mundo";
        printf("Before memmove: %s\n", str3);
        memmove(str3, sr,7);
        printf("After memmove: %s\n", str3);

	char str4[] = "hola mundo";
        printf("Before ft_memmove: %s\n", str4);
        ft_memmove(str4, sr,7);
        printf("After ft_memset: %s\n", str4);
}
*/
