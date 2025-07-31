/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:33:01 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:15:41 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <string.h>

/**
 * @brief Sets the first n bytes of the memory area pointed to by s to zero.
 *
 * This function writes null bytes (`'\0'`) to the first `n` bytes of the memory
 * area pointed to by `s`. It is typically used to clear memory.
 *
 * @param s void pointer to the memory area to be zeroed.
 * @param n Number of bytes to set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

/*
int main ()
{
	char str[] = "hola";
        printf("Before bzero: %s\n", str);
	bzero(str, 2);

	printf("After memset: %s\n", str);

	        char str2[] = "hola";
        printf("Before bzero: %s\n", str2);
        ft_bzero(str2, 2);

        printf("After memset: %s\n", str2);
}
*/
