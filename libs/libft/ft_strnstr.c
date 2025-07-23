/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:31:11 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:07:07 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//       #include	<string.h>
//       #include	<stdio.h>
#include "libft.h"

/**
 * @brief Searches for a substring within a limited length of a string.
 *
 * Looks for the first occurrence of the null-terminated string little
 * inside the string big, but only within the first len characters of big.
 *
 * @param big The string to search in.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search within big.
 * @return Pointer to the beginning of the found substring in big,
 *         or NULL if not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == 0 || little == NULL)
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && i + j < len)
		{
			j++;
			if (little[j] == 0)
				return (((char *)big + i));
		}
		i++;
	}
	return (0);
}

/*
int main ()
{
        printf("%p\n",ft_strnstr("hola","la" ,4));
        printf("%p\n\n",strnstr("hola","la",4));

        printf("%p\n",ft_strnstr("hola","l",3));
        printf("%p\n\n",strnstr("hola","l",3));

        printf("%p\n",ft_strnstr("hola","h",0));
        printf("%p\n\n",strnstr("hola","h",0));

        printf("%p\n",ft_strnstr("hola","h",4));
        printf("%p\n\n",strnstr("hola","h",4));

        printf("%p\n",ft_strnstr("hola bica caca","bi",6));
        printf("%p\n\n",strnstr("hola bica caca","bi",6));

        printf("%p\n",ft_strnstr("hola caca caca","ca",20));
        printf("%p\n\n",strnstr("hola caca caca","ca",20));

        printf("%p\n",ft_strnstr("hola","hola",4));
        printf("%p\n\n",strnstr("hola","hola",4));

        printf("%p\n",ft_strnstr("","hola",4));
        printf("%p\n\n",strnstr("","hola",4));
 }
 */
