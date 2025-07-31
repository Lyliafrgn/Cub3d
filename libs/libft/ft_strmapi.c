/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:39:40 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:05:05 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief Applies a function to each char of a string to create a new string.
 *
 * Applies the function f to each character of the input string s,
 * passing the character’s index and the character itself, and
 * builds a new allocated string with the results.
 *
 * @param s The input string (null-terminated).
 * @param f Function to apply to each character.
 *          Takes index and char, returns char.
 * @return A new allocated string with transformed characters,
 *         or NULL if memory allocation fails.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	ret = malloc((1 + len) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
