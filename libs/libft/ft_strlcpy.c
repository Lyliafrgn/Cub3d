/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:40:36 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:02:50 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

/**
 * @brief Copies src into dst, ensuring null-termination and size limit.
 *
 * Copies up to dstsize - 1 characters from src to dst,
 * then null-terminates the result. The destination buffer (dst)
 * must be pre-allocated and at least dstsize bytes long.
 *
 * @param dst Destination buffer (must be allocated beforehand).
 * @param src Source string (null-terminated).
 * @param dstsize Total size of destination buffer in bytes.
 * @return Length of src (not the number of characters copied).
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	if (src != NULL)
	{
		if (dst != NULL && dstsize != 0)
		{
			i = 0;
			while (i < dstsize - 1 && i < j)
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
	}
	return (j);
}
/*
int main()
{
	char dst[10];

	printf("%lu\n", ft_strlcpy(dst,"hola",2));
	printf("%lu\n\n", strlcpy(dst,"hola",2));

	printf("%lu\n", ft_strlcpy(dst,"hola",4));
	printf("%lu\n\n", strlcpy(dst,"hola",4));

	printf("%lu\n", ft_strlcpy(dst,"hola hola hola",2));
	printf("%lu\n\n", strlcpy(dst,"hola hola hola",2));

	printf("%lu\n", ft_strlcpy(dst,"hola hola hola",10));
	printf("%lu\n\n", strlcpy(dst,"hola hola hola",10));

	printf("%lu\n", ft_strlcpy(dst,"hola hola hola ",20));
//	printf("%lu\n\n", strlcpy(dst,"hola hola hola",20));

	printf("%lu\n", ft_strlcpy(dst,"",4));
	printf("%lu\n\n\n\n\n", strlcpy(dst,"",4));
////////
		char dst3[20] = "ma";
	char dst4[20] = "ma";
	printf("%lu\n", ft_strlcpy(dst3,"hola",20));
	printf("%s\n",dst3);
	printf("%lu\n", strlcpy(dst4,"hola",20));
	printf("%s\n\n",dst4);


	char dst5[20] = "ma";
	char dst6[20] = "ma";
	printf("%lu\n", ft_strlcpy(dst5,"hola hola hola",2));
	printf("%s\n",dst5);
	printf("%lu\n", strlcpy(dst6,"hola hola hola",2));
	printf("%s\n\n",dst6);


	char dst7[20] = "ma";
	char dst8[20] = "ma";
	printf("%lu\n", ft_strlcpy(dst7,"tiut",0));
printf("%s\n",dst7);
	printf("%lu\n", strlcpy(dst8,"tiut",0));
printf("%s\n\n",dst8);

}
*/
