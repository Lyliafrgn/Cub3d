/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:32:10 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:45:40 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

/**
 * @brief Fills the first n bytes of the memory area pointed
 *        to by s with the constant byte c.
 *
 * @param s Pointer to the memory area to fill.
 * @param c The byte value to set (converted to unsigned char).
 * @param n Number of bytes to set.
 * @return Pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		((char *)s)[n - 1] = ((char)c);
		n--;
	}
	return (s);
}
/*
int	main()
{
	char str[] = "hola";
	printf("Before memset: %s\n", str);

    // Using memset on an array of characters
	memset(str, 65, 4);
	printf("After memset: %s\n", str);

	ft_memset(str, 66, 4);
        printf("After memset: %s\n", str);

	//printf("%p\n",ft_memset("hola",2 ,4));
       // printf("%p\n\n",memset("hola",2,4));
}
*/
