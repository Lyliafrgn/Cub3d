/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:24:28 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/12 19:34:34 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = destlen;
	j = 0;
	if (size == 0)
	{
		return (srclen);
	}
	if (size <= destlen)
	{
		return (size + srclen);
	}
	while (src[j] && i < (size - 1))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (destlen + srclen);
}
/*int main(void) 
{
    char	src[5] = "ween";
    char	dest[20] = "HALLO";
    int	ptr;
	
	printf ("la chaine: %s, mesurait initialement: %lu\n",
	dest, strlen(dest));
	ptr = ft_strlcat(dest, src, 7);
    printf("la chaine est maintenant: %s , et mesure: %lu\n",
	dest, strlen(dest));
	printf("longueur totale (retournee) est: %d", ptr);
    return (0);
}*/
