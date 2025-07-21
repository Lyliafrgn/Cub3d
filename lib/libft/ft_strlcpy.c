/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:11:55 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/04 12:35:09 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
	{
		len++;
	}
	if (size == 0)
	{
		return (len);
	}
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*
int main(void)
{
    char        src[] = "COUCOU";
    char        dest[4];
    int ptr;

    ptr = ft_strlcpy(dest, src, 0);
    printf("la copie est : %s , la longueur est de: %d \n", dest, ptr);
    ptr = ft_strlcpy(dest, src, 4);
    printf("la copie est : %s , la longueur est de: %d \n", dest, ptr);
}*/
