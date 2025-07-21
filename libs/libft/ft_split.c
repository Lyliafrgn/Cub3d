/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 09:49:21 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/14 15:24:59 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int	ft_n_w(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	w;

	i = 0;
	j = 0;
	w = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == c)
			w = 0;
		else if (s[i] != c && w == 0)
		{
			j++;
			w = 1;
		}
		i++;
	}
	return (j);
}

static size_t	ft_l_w(int i, const char *s, char c)
{
	size_t	t;

	t = 0;
	while (s[i] != c && s[i])
	{
		t++;
		i++;
	}
	return (t + 1);
}

static char	**freeall(char **ns_ar, int i)
{
	i--;
	while (i >= 0)
	{
		free(ns_ar[i]);
		i--;
	}
	free(ns_ar);
	return (NULL);
}

static char	**ft_new(char const *s, char c, char **ns_ar, int nb_words)
{
	int	i;
	int	word_i;
	int	s_i;

	i = 0;
	word_i = 0;
	while (s[i] && word_i < nb_words)
	{
		s_i = 0;
		while (s[i] == c)
			i++;
		ns_ar[word_i] = malloc(ft_l_w(i, s, c) * sizeof(char));
		if (ns_ar[word_i] == NULL)
		{
			freeall(ns_ar, word_i);
			return (NULL);
		}
		while (s[i] && s[i] != c)
			ns_ar[word_i][s_i++] = s[i++];
		ns_ar[word_i][s_i] = '\0';
		word_i++;
	}
	ns_ar[word_i] = 0;
	return (ns_ar);
}

/**
 * @brief Splits the string s into an array of strings using the delimiter c.
 *
 * Allocates memory for the resulting array of strings,
 * which is null-terminated.
 *
 * @param s The string to split. If NULL, returns NULL.
 * @param c The delimiter character used to split the string.
 * @return A null-terminated array of strings (char **),
 *         or NULL if allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	char	**ns_ar;

	if (s == NULL)
		return (NULL);
	ns_ar = malloc(((1 + ft_n_w(s, c))) * sizeof(char *));
	if (!ns_ar)
		return (0);
	ns_ar = ft_new(s, c, ns_ar, ft_n_w(s, c));
	return (ns_ar);
}

/*
int main ()
{
    const char *input_str = "boopaionbroooo bo";
    char delimiter = 'o';

    char **result = ft_split(input_str, delimiter);

     if (result == NULL) {
        fprintf(stderr, "Erreur lors de l'exécution de ft_split.\n");
        return 1;
    }

      for (int i = 0; result[i] != NULL; i++) {
        printf("%s\n", result[i]);
    }

      for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
*/
