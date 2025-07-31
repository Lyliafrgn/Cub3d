/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:40:56 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:08:31 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	trim_end_n(char const *s1, char const *set, size_t slen)
{
	int	i;
	int	j;
	int	k;
	int	set_len;

	set_len = (int)ft_strlen(set);
	k = 0;
	i = (int)slen - 1;
	while (i >= 0 && k < (int)slen && k == (int)slen - i - 1)
	{
		j = 0;
		while (j < set_len)
		{
			if (s1[i] == set[j])
			{
				k++;
				break ;
			}
			j++;
		}
		i--;
	}
	return ((size_t)k);
}

static size_t	trim_start_n(char const *s1, char const *set, size_t slen)
{
	int	i;
	int	j;
	int	k;
	int	set_len;

	i = 0;
	set_len = (int)ft_strlen(set);
	k = 0;
	while (i < (int)slen && k < (int)slen && k == i)
	{
		j = 0;
		while (j < set_len)
		{
			if (s1[i] == set[j])
			{
				k++;
				break ;
			}
			j++;
		}
		i++;
	}
	return ((size_t)k);
}

/**
 * @brief Trims characters from the start and end of a string.
 *
 * Removes all characters from set found at the beginning and end of s1.
 * Returns a new allocated string without these characters.
 *
 * @param s1 The input string to trim.
 * @param set Characters to trim from s1.
 * @return A new allocated trimmed string,
 *         or an empty string if all characters are trimmed,
 *         or NULL if allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	t;
	size_t	t2;
	size_t	slen;
	size_t	i;
	char	*ns;

	slen = ft_strlen(s1);
	t = trim_start_n(s1, set, slen);
	if (t != slen)
		t2 = trim_end_n(s1, set, slen);
	else
		return (ft_strdup(""));
	ns = malloc(((1 + slen - (t + t2))) * sizeof(char));
	if (!s1 || !ns || !set)
		return (0);
	i = 0;
	while (i < slen - t - t2)
	{
		ns[i] = s1[i + t];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
/*
int main ()
{
        printf( "%s", ft_strtrim("bo bo bo bonjours bro bo bo ","bo "));
}
*/
