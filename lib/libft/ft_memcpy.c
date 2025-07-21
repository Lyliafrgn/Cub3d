/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:34:38 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/12 19:46:46 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dest && !src)
	{
		return (0);
	}
	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
    char buffer[20] = "hello";
    printf("Avant fonction: %s\n", buffer);
    ft_memcpy(buffer, "SALUT", 3);
    printf("Après fonction: %s\n", buffer);
    return 0;
}*/
