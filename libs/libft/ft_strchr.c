/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:36:04 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:01:18 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

/**
 * @brief Locates the first occurrence of character c in the string s.
 *
 * Searches for the first occurrence of the character c (converted to char)
 * in the null-terminated string s. If c is '\0', returns a pointer to the
 * null terminator.
 *
 * @param s The null-terminated string to search in.
 * @param c The character to locate (converted to char).
 * @return Pointer to the first occurrence of c in s, or NULL if not found.
 */
char	*ft_strchr(const char *s, int c)
{
	char	d;
	int		i;

	d = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return (((char *)s) + i);
		i++;
	}
	if (s[i] == '\0' && d == '\0')
		return (((char *)s) + i);
	return (0);
}
/*
int main()
{
	char	s[] = "hola";
   int c = 97;

   printf("%p \n",ft_strchr(s,c));
	printf("%p",strchr(s,c));
}
*/
