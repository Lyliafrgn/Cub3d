/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:43:16 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:01:13 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//     #include <string.h>
#include "libft.h"

/**
 * @brief Appends src to dst, ensuring null-termination and buffer size limit.
 *
 * Appends the string src to the end of dst. It appends at most
 * dstsize - strlen(dst) - 1 bytes, null-terminating the result.
 *
 * @param dst Destination buffer (must be null-terminated).
 * @param src Source string to append.
 * @param dstsize Total size of the destination buffer.
 * @return The total length of the string it tried to create:
 * strlen(src) + min(dstsize, strlen(dst)).
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ld;
	size_t	lsrc;
	size_t	t;
	int		i;

	ld = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (dstsize <= ld)
		return (lsrc + dstsize);
	t = ld;
	i = 0;
	while (t < dstsize - 1 && src[i] != '\0')
	{
		dst[t] = src[i];
		t++;
		i++;
	}
	dst[t] = '\0';
	return (ld + lsrc);
}

/*
int main ()
{
		char dst[10];

	printf("%lu\n", ft_strlcat(dst,"hola",2));
	printf("%s\n",dst);
	char dst2[10];
	printf("%lu\n", strlcat(dst2,"hola",2));
	printf("%s\n\n",dst2);


	char dst3[7] = "ma";
	char dst4[7] = "ma";
	printf("%lu\n", ft_strlcat(dst3,"hola",7));
	printf("%s\n",dst3);
	printf("%lu\n", strlcat(dst4,"hola",7));
	printf("%s\n\n",dst4);


	char dst5[20] = "ma";
	char dst6[20] = "ma";
	printf("%lu\n", ft_strlcat(dst5,"hola hola hola",2));
	printf("%s\n",dst5);
	printf("%lu\n", strlcat(dst6,"hola hola hola",2));
	printf("%s\n\n",dst6);


	char dst7[20] = "ma";
	char dst8[20] = "ma";
	printf("%lu\n", ft_strlcat(dst7,"tiut",0));
printf("%s\n",dst7);
	printf("%lu\n", strlcat(dst8,"tiut",0));
printf("%s\n\n",dst8);

//	printf("%lu\n", ft_strlcat(dst,"hola hola hola ",20));
//	printf("%lu\n\n", strlcpy(dst,"hola hola hola",20));

//	printf("%lu\n", ft_strlcat(dst,"",4));
//	printf("%lu\n\n", strlcat(dst,"",4));
}
*/
