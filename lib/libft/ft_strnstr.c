/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:19:40 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/15 18:01:02 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
	{
		return ((char *)big);
	}
	while (big[i] && i < len)
	{
		while (i + j < len && little[j] && big[i + j] == little[j])
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)big + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
/*
int main(void)
{
	    const char *big = "Hello, world!";
	    const char *little1 = "world";
	    const char *little2 = "ell";
	    const char *little3 = "o, w";

		printf("Test 1: %s\n", ft_strnstr(big, little1, 10));
// NULL, "world" is out of bounds
	    printf("Test 2: %s\n", ft_strnstr(big, little2, 10));
	    printf("Test 3: %s\n", ft_strnstr(big, little3, 10)); 
	    return (0);
}*/
