/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:34:41 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:09:00 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Extracts a substring from a string.
 *
 * Allocates and returns a substring from s,
 * starting at index start and maximum length len.
 *
 * @param s Input string.
 * @param start Starting index of the substring.
 * @param len Maximum length of the substring.
 * @return Newly allocated substring, or empty string if start > length of s,
 *         or NULL if allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start > l)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > l)
		len = l - start;
	sub = ft_calloc(1 + len, sizeof (char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
/*
int main ()
{
	char st[] = "hola";
	printf("%s\n", ft_substr(st, 2,2));
}
*/
