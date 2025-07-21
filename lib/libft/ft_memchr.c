/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:46:33 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/15 12:32:08 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c2;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == c2)
		{
			return ((void *)str + i);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void) 
{
    unsigned char *str = "j ai plus d inspi";
    char *ptr;
	
	ptr = (char *)ft_memchr(str, 'u', 11);
	printf("Avant fonction: %s\n",str);
	printf("Apres fonction: %s\n", ptr);
	return (0);
}*/
