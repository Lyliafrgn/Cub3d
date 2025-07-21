/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:43:12 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/15 12:10:38 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (c1[i] != c2[i])
		{
			return (c1[i] - c2[i]);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
    unsigned char s1 = "abce";
    unsigned char s2 = "abcf";
    printf("%d", ft_memcmp(s1, s2, 4));
	return(0);
}*/
