/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:17:02 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:08:32 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

/**
 * @brief Locates the last occurrence of a character in a string.
 *
 * Searches the string s for the last occurrence of the character c.
 *
 * @param s Null-terminated string to search in.
 * @param c Character to find (converted to char).
 * @return Pointer to the last occurrence of c in s,
 *         or NULL if c is not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	d;
	int		i;

	d = (char) c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == d)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
int main()
{
//	char	s[] = "hola";
 //  int c = 65;

//  printf("%s", ft_strrchr(((void *)0), '\0'));
   printf("%s \n",ft_strrchr(((void *)0), '\0'));
	printf("%s",strrchr(((void *)0),'\0'));
}
*/
